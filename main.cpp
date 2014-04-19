#include <iostream>
#include <cmath>

using namespace std;

double trapezoidRuleEx(double a, double b, double h)
{
	double sumIntegrals = 0;
	for(double i = a; i<b && (i+h)<=b; i+=h)
	{
		sumIntegrals += (h/2)*(exp(i)+exp(i+h));
	}
	return sumIntegrals;
}

double simpsonRuleEx(double a, double b, double h)
{
	double sumIntegrals = 0;
	
	for(double i = a; i<b && (i + 2*h)<=b ; i+=2*h)
	{
		sumIntegrals += (h/3)*(exp(i) + 4*exp(i+h) + exp(i + 2*h));
	}

	return sumIntegrals;
}

void approximateDerv(double a, double b, double h)
{
	for(double i = a; i<b; i+=h)
	{
		cout << "f'("<<i<<")\t = "<<(exp(i + h)-exp(i))/h<<endl;
	}
}

int main(int argc, char* argv)
{
	cout << "Using the trapezoid rule for the function f(x) = e^x"<<endl;
	cout <<trapezoidRuleEx(0, 1, 0.1) << endl;
	cout << endl;
	cout << "The error appr : "<<exp(1.0) - 1 - trapezoidRuleEx(0, 1, 0.1)<<endl;
	cout << "*****************************************************"<<endl<<endl;
	cout << "Using the simpson's rule"<<endl;
	cout << simpsonRuleEx(0, 1, 0.1) << endl;
	cout << endl;
	cout << "The error appr : "<<exp(1.0) - 1 - simpsonRuleEx(0, 1, 0.1)<<endl<<endl;
	cout << "*****************************************************"<<endl;
	cout << "The exact calc : "<<exp(1.0) - 1 << endl;
	cout << endl << endl;


	approximateDerv(0, 10, 0.1);
	cout << endl;


	return 0;
}
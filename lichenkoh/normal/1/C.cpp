#include <iostream>
#include <cmath>
#include <assert.h>
#include <math.h>
using namespace std;
double sq(double x){
	return x*x;
}
unsigned long check(double needed, double needed2)
{
	int n = 3;
	double unrounded;
	double rounded;
	while (true)
	{
		unrounded = needed * n;
		rounded = floor(unrounded+0.5);
		double diff = unrounded - rounded;
		double unrounded2 = needed2 * n;
		double rounded2 = floor(unrounded2+0.5);
		double diff2 = unrounded2 - rounded2;
		//cout << unrounded << endl;
		//cout << unrounded2 << endl;
		if (-0.00001 < diff && diff < 0.00001 && -0.00001 < diff2 && diff2 < 0.00001)
		{
			return n;
		}
		n++;
	}
}
double calc(double *p, double *q, double *r)
{
	double sqa = sq(p[0]-q[0])+sq(p[1]-q[1]);
	double sqb = sq(p[0]-r[0])+sq(p[1]-r[1]);
	double sqc = sq(q[0]-r[0])+sq(q[1]-r[1]);
	double a = sqrt(sqa);
	double b = sqrt(sqb);
	double c = sqrt(sqc);
	double theta = acos((sqa+sqb-sqc)/(2*a*b));
	double theta2 = acos((sqa+sqc-sqb)/(2*a*c));
	//double polar = 2*theta;
	double pi = atan(1)*4;
	double needed = theta/pi;
	double needed2 = theta2/pi;
	unsigned long n = check(needed,needed2);
	//cout << n <<endl;
	double sqr = sqc/(2*(1-cos(2*theta)));
	//cout << sqrt(sqr) << endl;
	double area = n * sqr * abs(sin(2*pi/n)) / 2;
	return area;
}

int main()
{
	double a[2];
	double b[2];
	double c[2];
	cin >> a[0];
	cin >> a[1];
	cin >> b[0];
	cin >> b[1];
	cin >> c[0];
	cin >> c[1];
	cout.precision(10);
	cout.setf(ios::fixed,ios::floatfield);
	double ans = calc(a,b,c);
	cout << ans << endl;
}
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	double r1=(-b+sqrt(b*b-4*a*c))/(2*a),r2=(-b-sqrt(b*b-4*a*c))/(2*a);
	printf("%.8lf\n%.8lf",max(r1,r2),min(r1,r2));
}
#include <iostream>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265358979

using namespace std;

int n, r;

int main(void)
{
	cin >> n >> r;
	
	double s = sin(PI/n);
	double R = r*s/(1-s);
	printf("%.11f\n", R);
	
	return 0;
}
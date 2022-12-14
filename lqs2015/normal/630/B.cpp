#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double n,mul;
int t;
int main()
{
	mul=1.000000011;
	cin>>n>>t;
	n=n*(double)pow(mul,t);
	printf("%lf\n",n);
	return 0;
}
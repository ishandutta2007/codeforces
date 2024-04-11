#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n;cin>>t;
	while(t--)
	{
		cin>>n;
		double T=n;
		if(n*n<4*n) {printf("N\n");continue;}
		double a=(T+sqrt(T*T-4.0*T))/2.0;
		double b=(T-sqrt(T*T-4.0*T))/2.0;
		printf("Y %.10lf %.10lf\n",a,b);
	} 
}
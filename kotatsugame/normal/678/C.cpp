#include<iostream>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int N,a,b,p,q;
main()
{
	cin>>N>>a>>b>>p>>q;
	long long ans=0;
	ans+=(long long)N/a*p;
	ans+=(long long)N/b*q;
	int g=gcd(a,b);
	long long L=(long long)a/g*b;
	ans-=N/L*(p<q?p:q);
	cout<<ans<<endl;
}
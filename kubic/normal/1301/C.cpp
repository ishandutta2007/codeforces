#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;ll n,m,d,r,ans;
ll f(ll x) {return (x*(x-1)>>1)+x;}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld",&n,&m);
		d=(n-m)/(m+1);r=(n-m)%(m+1);
		printf("%lld\n",f(n)-(m+1-r)*f(d)-r*f(d+1));
	}return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n;long long g=1,k,a[400005];
inline long long gcd(long long a,long long b) {return a&&b?gcd(b,a%b):a+b;}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(k=a[n];n--;) k=gcd(k,a[n]);
	for(long long i=2,t=0,e=sqrt(k)+1;i<=e&&k!=1;i++,t=0) {while(k%i==0) k/=i,t++;g=g*(t+1);}
	return printf("%lld\n",g*((k!=1)+1)),0;
}
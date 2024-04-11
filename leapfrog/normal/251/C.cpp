#include<bits/stdc++.h>
using namespace std;
long long a,b,k,lcm,ans=0,f[400005];
inline long long gcd(int a,int b) {return a==0||b==0?a:gcd(b,a%b);}
inline long long dp(int a,int b)
{
	memset(f,0x3f,sizeof(f)),f[b]=0;
	for(int i=b;i>a;i--)
	{
		f[i-1]=min(f[i]+1,f[i-1]);
		for(int j=2;j<=k;j++) if((i-i%j)>=a) f[i-i%j]=min(f[i-i%j],f[i]+1);
	}
	return f[a];
}
int main()
{
	scanf("%lld%lld%lld",&a,&b,&k),lcm=1;
	for(int i=1;i<=k;i++) lcm=lcm/gcd(lcm,i)*i;
	if(a/lcm==b/lcm) return printf("%lld\n",dp(b%lcm,a%lcm)),0;
	return printf("%lld\n",dp(0,a%lcm)+1ll*(a/lcm-b/lcm-1)*dp(0,lcm)+dp(b%lcm,lcm)),0;
}
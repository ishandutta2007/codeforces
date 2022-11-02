#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
int main()
{
	int T=rd();
	while(T--)
	{
		int n=rd();ll s=0;
		rep(i,1,n)
		{
			ll a=rd();
			s+=a;
		}
		s%=n;
		printf("%lld\n",1ll*s*(n-s));
	}
	return 0;
}
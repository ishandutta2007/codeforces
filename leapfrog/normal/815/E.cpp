//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
ll n,K;
inline ll solve(ll n,ll w)
{
	ll x=n,y=n-1,s1=1,s2=0,tt=0;if(x<=w*2) return 0;
	for(;y>=w*2;x/=2,y=x-1)
	{
		if(y==w*2) return tt+s1;else tt+=s1+s2;
		if(x&1) s1=2*s1+s2;else s2=2*s2+s1;
	}return tt;
}
inline ll work(ll l,ll r,ll p,ll k)
{
	ll md=(l+r)>>1;if(k==1) return md;
	ll v1=solve(md-l,p),v2=solve(r-md,p+1);
	if(k>v1+v2+1) return work(md+1,r,p,k-v1-1);
	else return work(l,md-1,p,k-v2-1);
}
int main()
{
	read(n,K);if(K==1) return puts("1"),0;
	if(K==2) return printf("%lld\n",n),0;else K-=2;
	ll l=1,r=n/2+1,rs=0;while(l<=r)
		{ll md=(l+r)>>1;if(solve(n-2,md)>=K) rs=md,l=md+1;else r=md-1;}
	return printf("%lld\n",work(2,n-1,rs,K)),0;
}
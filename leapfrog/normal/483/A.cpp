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
int main()
{
	ll l,r;read(l,r);
	for(ll i=l;i<=r;i++) for(ll j=i+1;j<=r;j++) for(ll k=j+1;k<=r;k++)
		if(__gcd(i,j)==1&&__gcd(j,k)==1&&__gcd(i,k)!=1) return printf("%lld %lld %lld\n",i,j,k),0;
	return puts("-1"),0;
}
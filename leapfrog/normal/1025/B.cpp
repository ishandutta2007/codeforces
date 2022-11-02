//Coded by Kamiyama_Shiki on 2021.11.05 {{{
//
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
ll rs=0;int n,x,y;
inline ll Lcm(ll a,ll b) {return a/__gcd(a,b)*b;}
inline int Fac(int x)
{
	for(int i=2,e=sqrt(x);i<=e;i++) if(x%i==0) return i;
	return x;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(x,y),rs=__gcd(rs,Lcm(x,y));
	if(rs==1) return puts("-1"),0;
	if(__gcd(rs,1ll*x)!=1) return printf("%d\n",Fac(__gcd(rs,1ll*x))),0;
	if(__gcd(rs,1ll*y)!=1) return printf("%d\n",Fac(__gcd(rs,1ll*y))),0;
}
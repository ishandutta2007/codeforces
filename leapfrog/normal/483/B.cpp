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
int c1,c2,X,Y;
inline char chk(ll x)
{
	if(x-x/X<c1) return 0;
	if(x-x/Y<c2) return 0;
	if(x-x/X/Y<c1+c2) return 0;
	return 1;
}
int main()
{
	read(c1,c2,X,Y);ll l=0,r=1e12,rs=0;
	while(l<=r) {ll md=(l+r)>>1;if(chk(md)) rs=md,r=md-1;else l=md+1;}
	return printf("%lld\n",rs),0;
}
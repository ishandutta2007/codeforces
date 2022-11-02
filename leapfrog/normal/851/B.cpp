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
inline ll sqr(ll x) {return x*x;}
int main()
{
	ll ax,ay,bx,by,cx,cy;read(ax,ay,bx,by,cx,cy);
	if((bx-ax)*(cy-by)==(by-ay)*(cx-bx)) return puts("No"),0;
	if(sqr(ax-bx)+sqr(ay-by)==sqr(cx-bx)+sqr(cy-by)) puts("Yes");else puts("No");
}
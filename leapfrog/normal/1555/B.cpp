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
#define y1 I_Love_Kamiyama_Shiki
int W,H,x1,y1,x2,y2,w,h;
inline void solve()
{
	read(W,H,x1,y1,x2,y2,w,h);int rs=1e9,ww=x2-x1,hh=y2-y1;
	if(w+x2-x1>W&&h+y2-y1>H) return puts("-1"),void();
	if(w+ww<=W) rs=min(rs,max(0,min(w-x1,x2-W+w)));
	if(h+hh<=H) rs=min(rs,max(0,min(h-y1,y2-H+h)));
	printf("%.10lf\n",1.0*rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}
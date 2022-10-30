//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int Ca,n;struct node{int x,y;char operator<(node b) const {return x<b.x;}}a[200005];
inline int wk1(int x,int y) {return x==y+1?0:(x-y)>>1;}
inline int wk2(int x,int y) {return x==y?x-1:(x-y)>>1;}
inline void solve()
{
	read(n),a[0]=(node){1,1};for(int i=1;i<=n;i++) read(a[i].x);
	for(int i=1;i<=n;i++) read(a[i].y);
	sort(a,a+n+1);ll rs=0;for(int i=1;i<=n;i++)
	{
		int x1=a[i-1].x,y1=a[i-1].y,x2=a[i].x,y2=a[i].y;
		if((x1+y1)&1) rs+=wk1(x2-x1+2,y2-y1+1);else rs+=wk2(x2-x1+1,y2-y1+1);
	}
	printf("%lld\n",rs);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}
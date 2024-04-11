//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n;
inline int qry(int l,int r) {if(l==r) return 0;else {printf("? %d %d\n",l,r),fflush(stdout);int r;return read(r),r;}}
inline void solve1(int l,int r,int dw)
{
	int md=(l+r)>>1;if(l+1==r) return printf("! %d\n",l),void();
	if(qry(md,dw)==dw) solve1(md,r,dw);else solve1(l,md,dw);
}
inline void solve2(int l,int r,int dw)
{
	int md=(l+r)>>1;if(l+1==r) return printf("! %d\n",r),void();
	if(qry(dw,md)==dw) solve2(l,md,dw);else solve2(md,r,dw);
}
int main()
{
	read(n);int wh=qry(1,n);if(wh!=1&&qry(1,wh)==wh) solve1(1,wh,wh);else solve2(wh,n,wh);
	return 0;
}
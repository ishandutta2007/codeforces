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
inline void solve(int l,int r,int sc)
{
	int md=(l+r)>>1;if(l==r) return printf("! %d\n",l),void();else if(r-l==1) return printf("! %d\n",l^r^sc),void();
	if(sc<=md) {if(qry(l,md)==sc) solve(l,md,sc);else solve(md+1,r,qry(md+1,r));}
	else {if(qry(md+1,r)==sc) solve(md+1,r,sc);else solve(l,md,qry(l,md));}
}
int main() {read(n);return solve(1,n,qry(1,n)),0;}
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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,m,X;
inline void solve()
{
	int L,R;read(n),read(L),R=L,read(m);
	for(int i=1,l,r;i<=m;i++)
	{
		read(l),read(r);if(r<L||R<l) continue;
		L=min(L,l),R=max(R,r);
	}
	printf("%d\n",R-L+1);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}
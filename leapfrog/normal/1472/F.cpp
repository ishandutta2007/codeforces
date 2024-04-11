//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int N,n;struct node{int x,y;char operator<(node b) const {return y<b.y;}}a[200005];
inline void solve()
{
	read(N),read(n);for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y);
	a[++n]=(node){3,N+1},sort(a+1,a+n+1);int m=0;
	for(int i=1;i<=n;i++) if(a[i].y==a[m].y) a[m].x|=a[i].x;else a[++m]=a[i];
	n=m;for(int i=1,ls=3;i<=n;i++) if(ls==3) ls=a[i].x;
		else if(a[i].x!=3&&((ls!=a[i].x)^((a[i].y-a[i-1].y)&1))) ls=3;
		else return puts("NO"),void();
	return puts("YES"),void();
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}
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
int n,m,K,a[205][205];
inline char chk(int x,int y)
{
	if(a[x-1][y-1]) return 0;
	if(a[x-1][y]) return 0;
	if(a[x-1][y+1]) return 0;
	if(a[x][y-1]) return 0;
	if(a[x][y]) return 0;
	if(a[x][y+1]) return 0;
	if(a[x+1][y-1]) return 0;
	if(a[x+1][y]) return 0;
	if(a[x+1][y+1]) return 0;
	return 1;
}
inline void solve()
{
	read(n),read(m),memset(a,0,sizeof(a));
	for(int j=1;j<=m;j++) if(chk(1,j)) a[1][j]=1;
	for(int i=1;i<=n;i++) if(chk(i,m)) a[i][m]=1;
	for(int j=m;j>=1;j--) if(chk(n,j)) a[n][j]=1;
	for(int i=n;i>=1;i--) if(chk(i,1)) a[i][1]=1;
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=m;j++) printf("%d",a[i][j]);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}
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
const int N=305;int n,m,a[N][N],b[N][N];
inline void solve()
{
	read(n,m);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) b[i][j]=(i!=1)+(j!=1)+(i!=n)+(j!=m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]>b[i][j]) return puts("NO"),void();
	puts("YES");for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",b[i][j],j==m?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}
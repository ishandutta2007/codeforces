#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,a[200005];long long W;
inline void solve()
{
	read(n),read(W);long long sm=0,hlf=(W>>1)+(W&1);int cnt=0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) if(a[i]<=W&&a[i]>=hlf) return(void)(printf("1\n%d\n",i));
	for(int i=1;i<=n;i++) if(a[i]<hlf) sm=(sm+a[i]<=W?++cnt,sm+a[i]:sm);
	if(sm<hlf) return(void)(puts("-1"));else sm=0,printf("%d\n",cnt);
	for(int i=1;i<=n;i++) if(a[i]<hlf) sm=(sm+a[i]<=W?printf("%d ",i),sm+a[i]:sm);
	putchar('\n');
}
int main() {for(read(T);T--;) solve();return 0;}
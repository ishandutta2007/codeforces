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
int Ca,n,X[200015],Y[200015],QT=0,d[50];char v[200005];
inline void sv(int x,int y) {++QT,X[QT]=x,Y[QT]=y;}
inline void flush()
{
	printf("%d\n",QT);for(int i=1;i<=QT;i++) printf("%d %d\n",X[i],Y[i]);
}
inline void solve()
{
	read(n),QT=0;for(int i=1;i<=n;i++) v[i]=0;
	int cnt=0;if(n<=2) return;
	for(int i=n;i>2;i=ceil(sqrt(i))) v[i]=1,d[++cnt]=i;
	d[++cnt]=2,v[2]=1;for(int i=2;i<=n;i++) if(!v[i]) sv(i,n);
	for(int i=1;i<cnt;i++) sv(d[i],d[i+1]),sv(d[i],d[i+1]);
	flush();
}
signed main() {for(read(Ca);Ca--;) solve();return 0;}
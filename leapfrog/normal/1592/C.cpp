#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=200005;int sm[N],a[N],cnt=0;
struct edge{int to,nxt;}e[N<<1];int n,m,et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	sm[x]=a[x];for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa) dfs(e[i].to,x),sm[x]^=sm[e[i].to];
}
inline int work(int x,int fa,int vl)
{
	int xr=a[x];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		xr^=work(e[i].to,x,vl);
	if(xr==vl) return cnt++,0;else return xr;
}
inline void solve()
{
	read(n,m),et=0,memset(head,0,sizeof(head));
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs(1,0);if(!sm[1]) return puts("YES"),void();else cnt=0;
	if(work(1,0,sm[1])) return puts("NO"),void();
	if(cnt==1) return puts("NO"),void();else cnt=cnt%2+2;
	if(cnt>m) return puts("NO"),void();else puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}
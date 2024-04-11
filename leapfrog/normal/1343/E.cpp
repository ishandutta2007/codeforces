//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int et,head[200005];struct edge{int to,nxt;}e[400005];
int T,n,m,a,b,c,da[200005],db[200005],dc[200005];ll s[600015];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void bfs(int s,int d[])
{
	queue<int>q;q.push(s),d[s]=0,memset(d,0,(n+1)<<2);
	while(!q.empty()) {int x=q.front();q.pop();for(int i=head[x];i;i=e[i].nxt) if(!d[e[i].to]&&e[i].to^s) d[e[i].to]=d[x]+1,q.push(e[i].to);}
}
inline void solve()
{
	read(n),read(m),read(a),read(b),read(c),et=0,memset(head,0,(n+1)<<2);
	memset(s,0x3f,sizeof(s));for(int i=1;i<=m;i++) read(s[i]);
	sort(s+1,s+m+1),s[0]=0;for(int i=1;i<=m;i++) s[i]+=s[i-1];
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	bfs(a,da),bfs(b,db),bfs(c,dc);ll cnt=1e18;
//	for(int i=1;i<=n;i++) printf("%d%c",da[i],i==n?'\n':' ');
//	for(int i=1;i<=n;i++) printf("%d%c",db[i],i==n?'\n':' ');
//	for(int i=1;i<=n;i++) printf("%d%c",dc[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) cnt=min(cnt,s[db[i]]+s[da[i]+db[i]+dc[i]]);
	printf("%lld\n",cnt);
}
int main() {for(read(T);T--;) solve();return 0;}
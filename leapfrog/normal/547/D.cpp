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
struct edge{int to,nxt;}e[400005];int n,et,head[200005],ax[200005],ay[200005],cl[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void addx(int id,int x) {if(ax[x]) adde(id,ax[x]),adde(ax[x],id),ax[x]=0;else ax[x]=id;}
inline void addy(int id,int y) {if(ay[y]) adde(id,ay[y]),adde(ay[y],id),ay[y]=0;else ay[y]=id;}
inline void dfs(int x) {for(int i=head[x];i;i=e[i].nxt) if(!~cl[e[i].to]) cl[e[i].to]=cl[x]^1,dfs(e[i].to);}
int main()
{
	read(n);for(int i=1,x,y;i<=n;i++) read(x),read(y),addx(i,x),addy(i,y);
	memset(cl,-1,sizeof(cl));for(int i=1;i<=n;i++) if(!~cl[i]) cl[i]=1,dfs(i);
	for(int i=1;i<=n;i++) putchar(cl[i]?'b':'r');return putchar('\n'),0;
}
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
const int N=200005;int n,d[N],rs[N],vl[N],id[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int w,int dd)
{
	if(vl[x]>=w-dd) return;else vl[x]=w-dd,rs[x]=max(rs[x],w);
	for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to,w,dd+1);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	memset(d,0x3f,sizeof(d));queue<int>q;int m;
	read(m);for(int x;m--;) read(x),q.push(x),d[x]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(d[e[i].to]>1e9) d[e[i].to]=d[x]+1,q.push(e[i].to);
	}for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[](int a,int b){return d[a]>d[b];});
	for(int i=1;i<=n;i++) dfs(id[i],d[id[i]],0);
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,nxt;}e[1000005];vector<pair<int,int> >q[500005];
int n,m,et,dep[500005],head[500005],dw[500005],sz[500005],sn[500005];char c[500005],rs[500005],avd[500005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline char Chk(int x) {return (x&(-x))==x;}
inline void dfs1(int x,int fa)
{
	sz[x]=1,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		dfs1(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void baoli(int x)
{
	dw[dep[x]]^=(1<<(c[x]-'a'));
	for(int i=head[x];i;i=e[i].nxt) if(!avd[e[i].to]) baoli(e[i].to);
}
inline void solve(int x,int isw)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=sn[x]) solve(e[i].to,0);
	if(sn[x]) solve(sn[x],1),avd[sn[x]]=1;
	baoli(x),avd[sn[x]]=0;
	//printf("solve %d : ",x);for(int i=1;i<=n;i++) printf("%d%c",dw[i],i==n?'\n':' ');
	for(int i=0;i<(int)q[x].size();i++) rs[q[x][i].second]=Chk(dw[q[x][i].first]);
	if(!isw) baoli(x);
}
int main()
{
	read(n),read(m);
	for(int i=2,f;i<=n;i++) read(f),adde(f,i);
	scanf("%s",c+1);for(int i=1,x,d;i<=m;i++) read(x),read(d),q[x].push_back(make_pair(d,i));
	dfs1(1,0),solve(1,1);for(int i=1;i<=m;i++) puts(rs[i]?"Yes":"No");
	return 0;
}
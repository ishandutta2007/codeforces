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
struct edge{int to,nxt;}e[200005];
int n,m,et,head[100005],a[100005],sz[100005],dep[100005],sn[100005],gx[200005],rs[100005];
map<int,int>v[100005];map<string,int>wq;char avd[100005];
vector<pair<int,int> >q[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1,sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		dfs1(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[sn[x]]<sz[e[i].to]) sn[x]=e[i].to;
	}
}
inline void baoli(int x,int tag)
{
	if(tag) {v[dep[x]][a[x]]++;if(v[dep[x]][a[x]]==1) gx[dep[x]]++;}
	else {v[dep[x]][a[x]]--;if(!v[dep[x]][a[x]]) gx[dep[x]]--;}
	for(int i=head[x];i;i=e[i].nxt) if(!avd[e[i].to]) baoli(e[i].to,tag);
}
inline void solve(int x,int isw)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=sn[x]) solve(e[i].to,0);
	{if(sn[x]) solve(sn[x],1),avd[sn[x]]=1;}baoli(x,1),avd[sn[x]]=0;
	for(int i=0;i<(int)q[x].size();i++) rs[q[x][i].second]=gx[q[x][i].first+dep[x]];
	if(!isw) baoli(x,0);
}
int main()
{
	read(n);string s;int Id=0,rt=n+1;
	for(int i=1,f;i<=n;i++) {cin>>s,read(f),f?adde(f,i):adde(rt,i);if(wq[s]) a[i]=wq[s];else a[i]=wq[s]=++Id;}
	read(m);for(int i=1,x,y;i<=m;i++) read(x),read(y),q[x].push_back(make_pair(y,i));
	dfs1(rt,0),solve(rt,1);for(int i=1;i<=m;i++) printf("%d\n",rs[i]);
	return 0;
}
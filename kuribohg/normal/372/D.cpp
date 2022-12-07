#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<utility>
#include<iterator>
using namespace std;
const int MAXN=1000010;
map<int,int> M;
map<int,int>::iterator it;
int n,k,size,now,ans;
int dfn[MAXN],anc[MAXN][20],dep[MAXN],Log[MAXN],dfs_clock;;
int head[MAXN],to[MAXN],next[MAXN],cnt;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x)
{
	dfn[x]=++dfs_clock;
	for(int i=head[x];i;i=next[i])
		if(anc[x][0]!=to[i])
			anc[to[i]][0]=x,dep[to[i]]=dep[x]+1,DFS(to[i]);
}
int LCA(int p,int q)
{
	if(dep[p]<dep[q]) swap(p,q);
	int d=dep[p]-dep[q];
	for(int i=Log[d];i>=0;i--)
		if(d&(1<<i)) p=anc[p][i];
	for(int i=Log[n];i>=0;i--)
		if(anc[p][i]!=anc[q][i]) p=anc[p][i],q=anc[q][i];
	if(p!=q) return anc[p][0];
	else return p;
}
void Insert(int x)
{
	int p,q;
	it=M.lower_bound(dfn[x]);
	if(it==M.end()) it=M.begin();
	p=it->second;
	size+=dep[x]+dep[p]-2*dep[LCA(x,p)];
	if(it==M.begin()) it=M.end();
	it--;
	q=it->second;
	size+=dep[x]+dep[q]-2*dep[LCA(x,q)];
	size-=dep[p]+dep[q]-2*dep[LCA(p,q)];
	M.insert(make_pair(dfn[x],x));
}
void Delete(int x)
{
	int p,q;
	it=M.find(dfn[x]);
	M.erase(it);
	it=M.lower_bound(dfn[x]);
	if(it==M.end()) it=M.begin();
	p=it->second;
	size-=dep[x]+dep[p]-2*dep[LCA(x,p)];
	if(it==M.begin()) it=M.end();
	it--;
	q=it->second;
	size-=dep[x]+dep[q]-2*dep[LCA(x,q)];
	size+=dep[p]+dep[q]-2*dep[LCA(p,q)];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
	Log[0]=-1;
	for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
	DFS(1);
	for(int i=1;i<=Log[n];i++)
		for(int j=1;j<=n;j++)
			anc[j][i]=anc[anc[j][i-1]][i-1];
	M.insert(make_pair(dfn[1],1));
	now=1,ans=1,size=2;
	for(int i=2;i<=n;i++)
	{
		Insert(i);
		while(size/2>k) Delete(now++);
		ans=max(ans,i-now+1);
	}
	printf("%d\n",ans);
	return 0;
}
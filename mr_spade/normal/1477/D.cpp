#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,sum,idx;
int deg[N];
vector<int> e[N],e2[N];
set<int> S,T;
int p[N],q[N],bk[N];
vector<int> V[N];
inline void clear()
{
	register int i;
	memset(deg+1,0,sizeof(int)*n);
	for(i=1;i<=n;i++)
		e[i].clear(),e2[i].clear(),V[i].clear();
	S.clear();T.clear();
	for(i=1;i<=n;i++)
		p[i]=q[i]=bk[i]=0;
	return;
}
void bfs(int x,int father)
{
	set<int>::iterator it;
	for(int y:e[x])
		if((it=S.find(y))!=S.end())
			T.insert(y),S.erase(it);
	for(int y:S)
		e2[x].push_back(y),e2[y].push_back(x);
	S.clear();
	for(int y:T)
		S.insert(y);
	T.clear();
	for(int y:e2[x])
		if(y!=father)
			bfs(y,x);
	return;
}
void dfs(int x,int father)
{
	p[x]=father;sum++;
	for(int y:e2[x])
		if(y!=father)
			deg[x]++,dfs(y,x);
	if(deg[x]==0)
		T.insert(x);
	return;
}
inline void run()
{
	int x,y;
	while(!T.empty())
	{
		x=*T.begin();y=p[x];
		bk[y]=1;deg[y]=-1;
		for(int z:e2[y])
			if(z!=p[y]&&deg[z]==0)
				deg[z]=-1,V[y].push_back(z),T.erase(z);
		if(p[y]&&deg[p[y]]==1&&(!p[p[y]]||deg[p[p[y]]]==-1))
			V[y].push_back(p[y]),deg[p[y]]=-1;
		else if(deg[p[y]]!=-1&&--deg[p[y]]==0)
			T.insert(p[y]);
	}
	return;
}
inline void solve()
{
	int x,y;
	register int i;
	scanf("%d%d",&n,&m);
	while(m--)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	for(i=1;i<=n;i++)
		S.insert(i);
	while(!S.empty())
	{
		x=*S.begin();S.erase(x);
		bfs(x,0);
		sum=0;dfs(x,0);
		if(sum==1)
		{
			bk[x]=1;T.clear();
			continue;
		}
		run();
	}
	idx=0;
	for(i=1;i<=n;i++)
		if(bk[i])
		{
			p[i]=++idx;
			for(int y:V[i])
				p[y]=++idx;
		}
	if(idx>n)
		exit(1);
	idx=0;
	for(i=1;i<=n;i++)
		if(bk[i])
		{
			for(int y:V[i])
				q[y]=++idx;
			q[i]=++idx;
		}
	if(idx>n)
		exit(1);
	for(i=1;i<=n;i++)
		printf("%d ",p[i]);
	putchar('\n');
	for(i=1;i<=n;i++)
		printf("%d ",q[i]);
	putchar('\n');
	clear();
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
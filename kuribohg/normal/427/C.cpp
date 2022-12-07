#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int MAXN=100010;
const int INF=2e9;
const long long MOD=1e9+7;
stack<int> S;
vector<int> graph[MAXN];
int n,m,t,belong[MAXN],dfn[MAXN],low[MAXN],tot,from,to,siz[MAXN];
long long w[MAXN],minw[MAXN],ans,num=1;
bool used[MAXN];
void tarjan(int x)
{
	t++;
	dfn[x]=low[x]=t;
	S.push(x);
	used[x]=true;
	int len=graph[x].size();
	for(int i=0;i<len;i++)
	{
		int to=graph[x][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(used[to]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		int p=-1;
		tot++;
		while(p!=x)
		{
			p=S.top();
			S.pop();
			used[p]=false;
			belong[p]=tot;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&from,&to);
		graph[from].push_back(to);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
 			tarjan(i);
	for(int i=1;i<=tot;i++)
		minw[i]=INF;
	for(int i=1;i<=n;i++)
		minw[belong[i]]=min(minw[belong[i]],w[i]);
	for(int i=1;i<=tot;i++) ans+=minw[i];
	for(int i=1;i<=n;i++) if(minw[belong[i]]==w[i]) siz[belong[i]]++;
	for(int i=1;i<=tot;i++) num=(num*(siz[i]%MOD))%MOD;
	printf("%I64d %I64d\n",ans,num);
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
char s[500005];
bool ans[500005];
int cur[500005][26],sz[500005],dep[500005];
vector<int> v[500005];
vector<pair<int,int> > qu[500005];
void pre(int node,int d)
{
	sz[node]=1;
	dep[node]=d;
	for (int u:v[node])
	{
		pre(u,d+1);
		sz[node]+=sz[u];
	}
}
void add(int node,int big)
{
	if (node==big)
	return;
	cur[dep[node]][s[node-1]-'a']^=1;
	for (int u:v[node])
	add(u,big);
}
void dfs(int node,bool keep)
{
	int big=-1;
	for (int u:v[node])
	{
		if (big==-1 || sz[u]>sz[big])
		big=u;
	}
	for (int u:v[node])
	{
		if (u!=big)
		dfs(u,0);
	}
	if (big!=-1)
	dfs(big,1);
	add(node,big);
	for (auto q:qu[node])
	{
		int cnt=0;
		for (int c=0;c<26;c++)
		cnt+=cur[q.first][c];
		if (cnt<=1)
		ans[q.second]=1;
	}
	if (!keep)
	add(node,-1);
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		v[p].push_back(i);
	}
	scanf(" %s",s);
	for (int i=0;i<q;i++)
	{
		int v,h;
		scanf("%d%d",&v,&h);
		qu[v].push_back({h,i});
	}
	pre(1,1);
	dfs(1,1);
	for (int i=0;i<q;i++)
	printf(ans[i]? "Yes\n":"No\n");
}
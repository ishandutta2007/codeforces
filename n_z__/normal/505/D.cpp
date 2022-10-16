#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,col[N],cnt;
bool flg[N],vis[N],isk[N];
vector<int>g[N],g1[N];
void dfs1(int u){col[u]=cnt;for(auto v:g1[u])if(!col[v])dfs1(v);}
void dfs(int u){vis[u]=isk[u]=1;for(auto v:g[u])if(!vis[v])dfs(v);else flg[col[v]]|=isk[v];isk[u]=0;}
int main()
{
	int i,x,y;
	for(cin>>n>>m;m--;g[x].push_back(y),g1[x].push_back(y),g1[y].push_back(x))cin>>x>>y;
	y=n-cnt;
	for(int i=1;i<=n;i++){if(!col[i])++cnt,dfs1(i);if(!vis[i])dfs(i);}
	for(i=1,y=n-cnt;i<=cnt;i++)y+=flg[i];
	printf("%d\n",y);
	return 0;
}
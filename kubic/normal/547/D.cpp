#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,lim=1e5,lstX[N],lstY[N],ans[N];bool vs[N];vector<int> e[N]; 
void dfs(int u,int f)
{
	vs[u]=1;ans[u]=ans[f]^1;
	for(int i=0,v;i<e[u].size();++i) {v=e[u][i];if(!vs[v]) dfs(v,u);}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%d %d",&x,&y);
		if(lstX[x])
		{
			e[i].push_back(lstX[x]);
			e[lstX[x]].push_back(i);lstX[x]=0;
		}else lstX[x]=i;
		if(lstY[y])
		{
			e[i].push_back(lstY[y]);
			e[lstY[y]].push_back(i);lstY[y]=0;
		}else lstY[y]=i;
	}for(int i=1;i<=n;++i) if(!vs[i]) dfs(i,0);
	for(int i=1;i<=n;++i) putchar(ans[i]?'b':'r');return 0;
}
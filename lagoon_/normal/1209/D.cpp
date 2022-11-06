#include<bits/stdc++.h>
using namespace std;
#define re register
int d[100100],q[100100],p[100100],ta;
bool vis[100100];
const int mod=1e9+7;
struct eg{int to;eg*nx;}e[200100],*la[100100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
void dfs(re int a)
{
	vis[a]=1;
	for(re eg*i=la[a];i;i=i->nx)if(!vis[i->to])
	{
		dfs(i->to);
	}
}
int main()
{
	re int n,m,x,y,ans;
	scanf("%d%d",&n,&m);ans=n;
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		addE(x,y);
	}
	for(re int i=1;i<=n;i++)if(!vis[i])
	{
		ans--;
		dfs(i);
	}
	printf("%d\n",m-ans);
}
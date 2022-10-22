#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define pb push_back
int n,ans,fa[N],SG[N];bool vs[N];vector<int> e[N];
void dfs(int u,int f)
{fa[u]=f;for(auto v:e[u]) if(v!=f) dfs(v,u),SG[u]^=SG[v]+1;}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs(1,0);vs[1]=1;ans=SG[1];putchar(ans?'1':'2');
	for(int i=2;i<=n;++i)
	{
		for(int j=i;!vs[j];j=fa[j])
			vs[j]=1,ans^=SG[j]^(SG[j]+1)^1;
		putchar(ans?'1':'2');
	}return 0;
}
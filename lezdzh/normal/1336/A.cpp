#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>g[200001];
int d[200001],sz[200001];
void dfs(int u,int f){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++)
		if(g[u][i]!=f){
			d[g[u][i]]=d[u]+1;
			dfs(g[u][i],u);
			sz[u]+=sz[g[u][i]];
		}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);	
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		d[i]-=sz[i]-1;
	sort(d+1,d+n+1);
	long long ans=0;
	for(int i=n-k+1;i<=n;i++)
		ans+=d[i];
	printf("%lld\n",ans);
}
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>g[200001],g2[200001];
int f1[200001],f2[200001];
bool vis[200001],vis2[200001];
bool dfs(int u){
	for(int i=0;i<g[u].size();i++)
		if(vis[g[u][i]]){
			if(f1[g[u][i]]!=2e9)continue;
			else{
				printf("-1\n");
				return 0;
			}
		}
		else{
			vis[g[u][i]]=1;
			if(!dfs(g[u][i]))return 0;
		}
	for(int i=0;i<g[u].size();i++)
		f1[u]=min(f1[u],f1[g[u][i]]);
	f1[u]=min(f1[u],u);
	return 1;
}
bool dfs2(int u){
	for(int i=0;i<g2[u].size();i++)
		if(vis2[g2[u][i]]){
			if(f2[g2[u][i]]!=2e9)continue;
			else{
				printf("-1\n");
				return 0;
			}
		}
		else{
			vis2[g2[u][i]]=1;
			if(!dfs2(g2[u][i]))return 0;
		}
	for(int i=0;i<g2[u].size();i++)
		f2[u]=min(f2[u],f2[g2[u][i]]);
	f2[u]=min(f2[u],u);
	return 1;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f1[i]=f2[i]=2e9;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g2[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(f1[i]==2e9)
			if(!dfs(i))return 0;
	for(int i=1;i<=n;i++)
		if(f2[i]==2e9)
			if(!dfs2(i))return 0;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(min(f1[i],f2[i])==i)
			ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(min(f1[i],f2[i])==i)
			printf("A");
		else printf("E");
	printf("\n");
}
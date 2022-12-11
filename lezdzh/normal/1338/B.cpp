#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>g[100001];
int d[100001],fa[100001],a[100001];
void dfs(int u,int f){
	fa[u]=f;
	for(int i=0;i<g[u].size();i++)
		if(g[u][i]!=f){
			d[g[u][i]]=d[u]+1;
			dfs(g[u][i],u);
		}
}
bool cmp(int u,int v){
	return fa[u]<fa[v];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(g[i].size()!=1){
			dfs(i,0);
			break;
		}
	for(int i=1;i<=n;i++)
		if(g[i].size()==1)
			a[++a[0]]=i;
	sort(a+1,a+a[0]+1,cmp);
	int ok=1,ans=n-1;
	for(int i=2;i<=a[0];i++){
		if((d[a[i]]-d[a[i-1]])%2!=0)
			ok=0;
		if(fa[a[i]]==fa[a[i-1]])
		ans--;
	}
	printf("%d %d\n",ok==1?1:3,ans);
}
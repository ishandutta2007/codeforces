#include<cstdio>
#include<vector>
using namespace std;

int kd[1000001],a[1000001];
vector<int>g[1000001];
void dfs1(int u){
	if(kd[u]==4)return;
	for(int i=0;i<g[u].size();i++)
		dfs1(g[u][i]);
	a[u]=kd[u]==0?a[g[u][0]]&a[g[u][1]]:
		kd[u]==1?a[g[u][0]]|a[g[u][1]]:
		kd[u]==2?a[g[u][0]]^a[g[u][1]]:!a[g[u][0]];
}
int ans[1000001];
void dfs2(int u,int yx){
	if(kd[u]==4){
		ans[u]=yx;
		return;
	}
	if(kd[u]==0){
		dfs2(g[u][0],yx&&(a[u]||a[g[u][1]]));
		dfs2(g[u][1],yx&&(a[u]||a[g[u][0]]));
	}
	if(kd[u]==1){
		dfs2(g[u][0],yx&&(!a[u]||!a[g[u][1]]));
		dfs2(g[u][1],yx&&(!a[u]||!a[g[u][0]]));
	}
	if(kd[u]==2){
		dfs2(g[u][0],yx);
		dfs2(g[u][1],yx);
	}
	if(kd[u]==3){
		dfs2(g[u][0],yx);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c[10];
		scanf("%s",c);
		if(c[0]=='A'){
			kd[i]=0;
			int x,y;
			scanf("%d%d",&x,&y);
			g[i].push_back(x);
			g[i].push_back(y);
		}
		if(c[0]=='O'){
			kd[i]=1;
			int x,y;
			scanf("%d%d",&x,&y);
			g[i].push_back(x);
			g[i].push_back(y);
		}
		if(c[0]=='X'){
			kd[i]=2;
			int x,y;
			scanf("%d%d",&x,&y);
			g[i].push_back(x);
			g[i].push_back(y);
		}
		if(c[0]=='N'){
			kd[i]=3;
			int x;
			scanf("%d",&x);
			g[i].push_back(x);
		}
		if(c[0]=='I'){
			kd[i]=4;
			int x;
			scanf("%d",&x);
			a[i]=x;
		}
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		if(kd[i]==4)printf("%d",ans[i]^a[1]);
	printf("\n");
}
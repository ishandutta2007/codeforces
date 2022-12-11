#include<cstdio>
#include<vector>
using namespace std;

vector<int>g[100001];
struct dn{int x,y;};
vector<dn>ans;
void dfs(int u,int t,int f){
	for(int i=0;i<g[u].size();i++)
		if(g[u][i]==f){
			swap(g[u][i],g[u][g[u].size()-1]);
			g[u].pop_back();
		}
	int z=g[u].size()+(u!=1),o=t,p=0;
	while(o<z){
		ans.push_back((dn){g[u][p],o+1});
		dfs(g[u][p],o+1,u);
		o++;
		p++;
	}
	if(u==1)return;
	o=t-(g[u].size()-p)-1;
	ans.push_back((dn){u,o});
	while(p<g[u].size()){
		ans.push_back((dn){g[u][p],o+1});
		dfs(g[u][p],o+1,u);
		o++;
		p++;
	}
	ans.push_back((dn){f,t});
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
	ans.push_back((dn){1,0});
	dfs(1,0,0);
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].x,ans[i].y);
}
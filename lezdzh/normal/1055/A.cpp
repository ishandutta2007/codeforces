#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector<int>g[1001];
queue<int>q;
int vis[1001];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1,oo=0;i<=n;i++){
		int o;
		scanf("%d",&o);
		if(o==1){
			if(oo)g[oo].push_back(i);
			oo=i;
		}
	}
	for(int i=1,oo=0;i<=n;i++){
		int o;
		scanf("%d",&o);
		if(o==1){
			if(oo)g[i].push_back(oo);
			oo=i;
		}
	}
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
			if(!vis[g[u][i]])q.push(g[u][i]),vis[g[u][i]]=1;
	}
	printf(vis[s]?"YES\n":"NO\n");
}
#include<cstdio>
#include<vector>
using namespace std;

const int md=998244353;
vector<int>g[300001];
int f[300001][3];
int pw(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%md)
		if(y&1)ans=1ll*ans*x%md;
	return ans;
}
int dfs(int u,int fa=0){
	f[u][0]=f[u][2]=1;f[u][1]=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		dfs(v,u);
		f[u][2]=1ll*f[u][2]*f[v][2]%md;
		f[u][0]=1ll*f[u][0]*(f[v][1]+f[v][2])%md;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		f[u][1]=(f[u][1]+1ll*f[v][0]*f[u][0]%md*pw(f[v][1]+f[v][2],md-2))%md;
	}
	f[u][2]=(f[u][2]+f[u][1])%md;
	//printf("%d:%d %d %d\n",u,f[u][0],f[u][1],f[u][2]);
	return f[u][2];
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
	printf("%d\n",dfs(1,0));
}
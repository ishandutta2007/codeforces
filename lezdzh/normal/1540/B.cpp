#include<cstdio>
#include<vector>
using namespace std;

const int md=1000000007;
vector<int>g[201];
int fa[201],sz[201];
void dfs(int u,int f){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++)
		if(g[u][i]!=f){
			fa[g[u][i]]=u;
			dfs(g[u][i],u);
			sz[u]+=sz[g[u][i]];
		}
}
int pw(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%md)
		if(y&1)ans=1ll*ans*x%md;
	return ans;
}
int p[201][201];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++){
			if(i==0)p[i][j]=1;
			else if(j==0)p[i][j]=0;
			else p[i][j]=(1ll*(md+1)/2*p[i-1][j]+1ll*(md+1)/2*p[i][j-1])%md;
		}
	int sum=0;
	for(int i=1;i<=n;i++){
		dfs(i,0);
		for(int j=1;j<=n;j++)
			if(j!=i){
				int o=j,d=0,dd=0,ans=0,nyn=pw(n,md-2);
				while(o!=i)o=fa[o],d++;
				o=j;
				while(o!=i){
					dd++;
					ans=(ans+1ll*(sz[fa[o]]-sz[o])*nyn%md*p[d-dd][dd])%md;
					o=fa[o];
				}
				if(i<j)ans=(1-ans+md)%md;
				sum=(sum+ans)%md;
			}
	}
	printf("%lld\n",1ll*sum*(md+1)/2%md);
}
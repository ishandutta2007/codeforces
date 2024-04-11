#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct ed{int v,c;};
vector<ed>g[500001];
int k;
long long f[500001][2];
long long a[500001];
void dfs(int u,int fa){
	for(int i=0;i<g[u].size();i++)
		if(g[u][i].v!=fa)
			dfs(g[u][i].v,u);
	int at=0;
	long long ans=0;
	for(int i=0;i<g[u].size();i++)
		if(g[u][i].v!=fa){
			int v=g[u][i].v;
			a[++at]=f[v][0]+g[u][i].c-f[v][1];
			ans+=f[v][1];
		}
	sort(a+1,a+at+1);
	f[u][0]=f[u][1]=ans;
	for(int i=1;i<=at;i++){
		if(at-i+1<=k-1)f[u][0]+=max(0ll,a[i]);
		if(at-i+1<=k)f[u][1]+=max(0ll,a[i]);
	}
	//printf("%d %lld %lld\n",u,f[u][0],f[u][1]);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		 int n;
		 scanf("%d%d",&n,&k);
		 for(int i=1;i<=n;i++)
			 g[i].clear();
		 for(int i=1;i<n;i++){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			g[u].push_back((ed){v,c});
			g[v].push_back((ed){u,c});
		 }
		 dfs(1,0);
		 printf("%lld\n",f[1][1]);
	}
}
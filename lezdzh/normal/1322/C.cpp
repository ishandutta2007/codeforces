#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int b[500001];
long long c[500001],w[2000001],vis[500001];
vector<int>g[500001];
bool cmp(int u,int v){
	return b[u]<b[v];
}
long long gcd(long long x,long long y){
	return !y?x:gcd(y,x%y);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&c[i]);
		for(int i=1;i<=n;i++){
			g[i].clear();
			b[i]=1;
			vis[i]=0;
		}
		b[0]=1;
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			vis[v]=1;
		}
		for(int i=1;i<=n;i++){
			sort(g[i].begin(),g[i].end(),cmp);
			for(int j=0;j<g[i].size();){
				int k=j;
				while(k<g[i].size()&&b[g[i][k]]==b[g[i][j]])k++;
				b[0]++;
				for(int l=j;l<k;l++)
					b[g[i][l]]=b[0];
				j=k;
			}
		}
		for(int i=1;i<=b[0];i++)
			w[i]=0;
		for(int i=1;i<=n;i++)
			if(vis[i])
				w[b[i]]+=c[i];
		long long ans=0;
		for(int i=1;i<=b[0];i++)
			ans=gcd(ans,w[i]);
		printf("%lld\n",ans);
	}
}
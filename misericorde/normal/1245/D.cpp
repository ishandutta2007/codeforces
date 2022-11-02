#include <bits/stdc++.h>
#define ll long long
#define maxn 2005
const ll inf=(ll)1<<(ll)62;
int n,x[maxn],y[maxn],k[maxn],c[maxn],vis[maxn]={0},pre[maxn];
ll ans=0,G[maxn][maxn]={0},dis[maxn];
int dist(int a,int b){return std::abs(x[a]-x[b])+std::abs(y[a]-y[b]);}
void prim(){
	n++;
	for(int i=1;i<=n;++i)dis[i]=inf;
	dis[n]=0;vis[n]=1;
	for(int i=1;i<n;++i){dis[i]=std::min(dis[i],G[n][i]);pre[i]=n;}
	for(int i=2;i<=n;++i){
		int sel=0;
		for(int j=1;j<=n;++j){
			if (vis[j])continue;
			if (!sel||dis[j]<dis[sel])sel=j;
		}vis[sel]=1;ans+=dis[sel];
		for(int j=1;j<=n;++j){
			if (!vis[j]){
				if (dis[j]>G[sel][j])
					pre[j]=sel;
				dis[j]=std::min(dis[j],G[sel][j]);
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%d",&k[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			G[i][j]=(ll)(k[i]+k[j])*dist(i,j);
	for(int i=1;i<=n;++i)G[n+1][i]=c[i];
	prim();
	std::cout<<ans<<std::endl;
	int cnt=0;
	for(int i=1;i<n;++i)if (pre[i]==n)cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<n;++i)if (pre[i]==n)printf("%d ",i);printf("\n");
	printf("%d\n",n-cnt-1);
	for(int i=1;i<n;++i)if (pre[i]!=n)printf("%d %d\n",i,pre[i]);
	return 0;
}
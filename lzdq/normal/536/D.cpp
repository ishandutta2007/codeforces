#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
const int MAXN=2005,MAXM=2e5+5;
int n,m,s0,s1,val[MAXN];
int cnte,h[MAXN],to[MAXM],nx[MAXM],ww[MAXM];
inline void adde(int u,int v,int w){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	ww[cnte]=w;
	h[u]=cnte;
}
ll dis[MAXN];
bool vis[MAXN];
void Dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	memset(vis,0,sizeof(vis));
	while(1){
		int u=0;
		for(int i=1; i<=n; i++)
			if(!vis[i]&&(!u||dis[i]<dis[u])) u=i;
		if(!u) break;
		vis[u]=1;
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			dis[v]=min(dis[v],dis[u]+ww[i]);
		}
	}
	return ;
}
inline bool cmp(int a,int b){
	return dis[a]<dis[b];
}
int p0[MAXN],p1[MAXN],nx0[MAXN],nx1[MAXN][MAXN];
bool sm0[MAXN],sm1[MAXN];
int a[MAXN];
ll b[MAXN],f[MAXN][MAXN][2],sum[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s0,&s1);
	for(int i=1; i<=n; i++)
		scanf("%d",val+i);
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);
		adde(v,u,w);
	}
	Dij(s0);
	for(int i=1; i<=n; i++)
		p0[i]=i;
	sort(p0+1,p0+n+1,cmp);
	for(int i=1; i<n; i++)
		if(dis[p0[i]]==dis[p0[i+1]]) sm0[i]=1;
	Dij(s1);
	for(int i=1; i<=n; i++)
		p1[i]=i;
	sort(p1+1,p1+n+1,cmp);
	for(int i=1; i<n; i++)
		if(dis[p1[i]]==dis[p1[i+1]]) sm1[i]=1;
	for(int i=0; i<=n; i++){
		memset(vis,0,sizeof(vis));
		for(int j=1; j<=i; j++)
			vis[p0[j]]=1;
		for(int j=1; j<=n; j++)
			a[j]=!vis[p1[j]];
		for(int j=0,s=0,k=0; j<=n; j++){
			s-=a[j];
			while(!s&&k<n||sm1[k]) s+=a[++k];
			if(s) nx1[i][j]=k;
			else nx1[i][j]=n+1;
		}
	}
	for(int j=n-1; j>=0; j--){
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=j; i++)
			vis[p1[i]]=1;
		for(int i=1; i<=n; i++){
			if(!vis[p0[i]]){
				a[i]=1;
				b[i]=val[p0[i]];
			}else a[i]=b[i]=0;
			sum[i]=sum[i-1]+b[i];
		}
		for(int i=0; i<=n; i++){
			f[i][j][1]=f[i][j+1][1];
			for(int k=nx1[i][j]; k<nx1[i][j+1]; k++)
				f[i][j][1]=min(f[i][j][1],f[i][k][0]);
		}
		for(int i=0,s=0,k=0; i<=n; i++){
			s-=a[i];
			while(!s&&k<n||sm0[k]) s+=a[++k];
			if(s) nx0[i]=k;
			else nx0[i]=n+1;
		}
		ll mx=0;
		for(int i=n,k=n; i>=0; i--){
			while(k>=nx0[i]){
				mx=max(mx,f[k][j][1]+sum[k]-sum[i]);
				k--;
			}
			f[i][j][0]=mx;
			mx+=b[i];
		}
	}
	ll ans=f[0][0][0]<<1;
	for(int i=1; i<=n; i++)
		ans-=val[i];
	if(ans>0) puts("Break a heart");
	else if(ans==0) puts("Flowers");
	else puts("Cry");
	return 0;
}
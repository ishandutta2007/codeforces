#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef double ld;
int n;
int cnte,h[55],to[105],nx[105];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int siz[55];
ld f[55][55],g[55][55],c[55][55];
void Dfs(int u,int fa=0){
	siz[u]=0;
	f[u][0]=1;
	static ld tmp[55];
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa) continue;
		Dfs(v,u);
		memset(tmp,0,sizeof(tmp));
		for(int j=0; j<=siz[u]; j++)
			for(int k=0; k<=siz[v]; k++)
				tmp[j+k]+=f[u][j]*g[v][k]*c[j+k][j]*c[siz[u]+siz[v]-j-k][siz[u]-j]/c[siz[u]+siz[v]][siz[u]];
		memcpy(f[u],tmp,sizeof(tmp));
		siz[u]+=siz[v];
	}
	siz[u]++;
	for(int i=0; i<=siz[u]; i++){
		if(i) g[u][i]=i*f[u][i-1];
		else g[u][i]=0;
		for(int j=i; j<siz[u]; j++)
			g[u][i]+=f[u][j]/2;
		g[u][i]/=siz[u];
	}
	if(0){
		printf("u %d\nf",u);
		for(int i=0; i<siz[u]; i++)
			printf(" %.2f",f[u][i]);
		printf("\ng");
		for(int i=0; i<=siz[u]; i++)
			printf(" %.2f",g[u][i]);
		puts("");
	}
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	for(int i=0; i<=n; i++){
		c[i][0]=1;
		for(int j=1; j<=i; j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(int i=1; i<=n; i++){
		Dfs(i);
		printf("%.7f\n",f[i][0]);
	}
	return 0;
}
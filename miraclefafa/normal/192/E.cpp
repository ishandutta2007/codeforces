#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,h,t,tot,k,q[100100],f[100100],u,v,fst[200100],nxt[200100],y[200100];
int F[100100][20],id[100100],dep[100100],cnt[100100],ans[100100];
void add(int u,int v) {
	tot++;y[tot]=v;nxt[tot]=fst[u];fst[u]=tot;
	tot++;y[tot]=u;nxt[tot]=fst[v];fst[v]=tot;
}
int LCA(int u,int v) {
	int k;if (dep[u]>dep[v]) swap(u,v);
	for (k=dep[v]-dep[u],j=17;j>=0;j--) if ((k>>j)&1) v=F[v][j],k^=(1<<j);
	if (u==v) return u;
	for (k=17;f[u]!=f[v];u=F[u][k],v=F[v][k]) 
		for (;k && F[u][k]==F[v][k];k--);
	return f[u];
}
int main() {
	scanf("%d",&n);
	for (i=1;i<n;i++) scanf("%d%d",&u,&v),add(u,v);
	for (f[1]=-1,h=0,t=1,q[0]=1;h<t;h++) {
		for (j=fst[q[h]];j;j=nxt[j]) if (f[y[j]]==0) {
			q[t++]=y[j];f[y[j]]=q[h];id[y[j]]=(j+1)/2;dep[y[j]]=dep[q[h]]+1;
		}
	}
	f[1]=0;
	for (i=1;i<=n;i++) F[i][0]=f[i];
	for (j=1;j<=17;j++) for (i=1;i<=n;i++) F[i][j]=F[F[i][j-1]][j-1];
	scanf("%d",&k);
	for (i=1;i<=k;i++) {scanf("%d%d",&u,&v);cnt[u]++;cnt[v]++;cnt[LCA(u,v)]-=2;}
	for (i=n;i>=1;i--) cnt[f[q[i]]]+=cnt[q[i]];
	for (i=1;i<=n;i++) ans[id[i]]=cnt[i];
	for (i=1;i<n;i++) printf("%d ",ans[i]);
}
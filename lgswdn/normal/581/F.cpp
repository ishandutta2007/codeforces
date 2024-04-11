#include<bits/stdc++.h>
using namespace std;
const int N=5009;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]}; hd[u]=tot;}

int n,leaf,lcnt[N],l[N];
void dfs1(int u,int fa) { //get leaves
	for(int i=hd[u],v;i;i=e[i].nxt) {
		l[u]++;
		if((v=e[i].to)==fa) continue;
		dfs1(v,u);
	}
	leaf+=(l[u]==1);
}

int f[N][N][2],g[N][2];
void dfs2(int u,int fa) { //tree bag dp
	if(l[u]==1) {
		f[u][0][0]=f[u][1][1]=0; lcnt[u]=1;
		return;
	}
	bool vst=0;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		dfs2(v,u);
		if(!vst) {
			for(int k=0;k<=lcnt[v];k++)
				f[u][k][0]=min(f[v][k][0],f[v][k][1]+1),
				f[u][k][1]=min(f[v][k][0]+1,f[v][k][1]);
		}
		else {
			for(int j=0;j<=min(lcnt[u],leaf/2);j++)
				for(int k=0;k<2;k++)
					g[j][k]=f[u][j][k],f[u][j][k]=0x3f3f3f3f;
			for(int j=0;j<=min(lcnt[u],leaf/2);j++) {
				for(int k=0;k<=min(lcnt[v],leaf/2-j);k++) {
					f[u][j+k][0]=min(f[u][j+k][0],g[j][0]+min(f[v][k][0],f[v][k][1]+1));
					f[u][j+k][1]=min(f[u][j+k][1],g[j][1]+min(f[v][k][1],f[v][k][0]+1));
				}
			}
		}
		vst=1; lcnt[u]+=lcnt[v];
	}
}

int main() {
	scanf("%d",&n);
	if(n==2) return puts("2"), 0;
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v), add(u,v), add(v,u);
	dfs1(1,0);
	memset(f,0x3f,sizeof(f));
	int root=1;
	while(l[root]==1) root++;
	dfs2(root,0);
	printf("%d",min(f[root][leaf/2][0],f[root][leaf/2][1]));
	return 0;
}
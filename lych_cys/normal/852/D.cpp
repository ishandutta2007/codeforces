#include<bits/stdc++.h>
#define inf 1000000000
#define N 1209
#define M 1000009
using namespace std;

int n,m,cnt,pt,tot,gol,fst[N],cur[N],pnt[M],len[M],nxt[M];
int a[N],d[N],h[N],f[N][N];
void add(int x,int y,int z){
	pnt[++tot]=y; len[tot]=z; nxt[tot]=fst[x]; fst[x]=tot;
}
void ins(int x,int y,int z){ add(x,y,z); add(y,x,0); }
bool bfs(){
	int head=0,tail=1,i,x,y; h[1]=0;
	memset(d,-1,sizeof(d)); d[0]=1;
	memcpy(cur,fst,sizeof(fst));
	while (head<tail){
		x=h[++head];
		for (i=fst[x]; i; i=nxt[i]) if (len[i]){
			y=pnt[i];
			if (d[y]==-1){
				d[y]=d[x]+1; h[++tail]=y;
			}
		}
	}
	return d[gol]!=-1;
}
int dfs(int x,int rst){
	if (x==gol || !rst) return rst;
	int &i=cur[x],y,tmp,flow=0;
	for (; i; i=nxt[i]) if (len[i]){
		y=pnt[i];
		if (d[x]+1==d[y]){
			tmp=dfs(y,min(len[i],rst));
			flow+=tmp; len[i]-=tmp;
			len[i^1]+=tmp; rst-=tmp;
			if (!rst) break;
		}
	}
	if (!flow) d[x]=-1; return flow;
}
bool check(int lim){
	int i,j; gol=n<<1|1;
	tot=1; memset(fst,0,sizeof(fst));
	for (i=1; i<=n; i++) if (a[i]) ins(0,i,a[i]);
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++) if (f[i][j]<=lim) ins(i,j+n,1);
	for (i=1; i<=n; i++) ins(i+n,gol,1);
	int flow=0;
	while (bfs()){ flow+=dfs(0,inf); if (flow>=pt) return 1; }
	return 0;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&cnt,&pt);
	int i,j,k,x,y,z;
	for (i=1; i<=cnt; i++){
		scanf("%d",&x); a[x]++;
	}
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++) if (i!=j) f[i][j]=1731312;
	for (i=1; i<=m; i++){
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=f[y][x]=min(f[x][y],z);
	}
	for (k=1; k<=n; k++)
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int l=0,r=1731312,mid;
	while (l<r){
		mid=l+r>>1;
		if (check(mid)) r=mid; else l=mid+1;
	}
	printf("%d\n",(l<1731312)?l:-1);
	return 0;
}
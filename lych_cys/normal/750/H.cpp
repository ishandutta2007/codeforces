#include<bits/stdc++.h>
#define N 1005
#define M 1000005
using namespace std;

int m,n,cas,cnt,tp,sta,gol,id[N][N],fa[M],fa0[M],bx[N],by[N],q[N],rt[N];
char a[N][N]; bool vis[M];
int dx[8]={-1,-1,-1,0,1,1,1,0},dy[8]={-1,0,1,1,1,0,-1,-1};
struct hsh_node{
	int tot,fst[2010527],px[M<<3],py[M<<3],nxt[M<<3];
	void ins(int x,int y){
		if (!x || !y) return;
		if (x>y) swap(x,y);
		int z=(x*233+y)%2010527,i;
		for (i=fst[z]; i; i=nxt[i]) if (px[i]==x && py[i]==y) return;
		px[++tot]=x; py[tot]=y; nxt[tot]=fst[z]; fst[z]=tot;
	}
	bool check(int x,int y){
		if (x>y) swap(x,y);
		int z=(x*233+y)%2010527,i;
		for (i=fst[z]; i; i=nxt[i]) if (px[i]==x && py[i]==y) return 1;
		return 0;
	}
}hsh;
int getfa(int x){ if (!x){puts("no!");while(1);}return (x==fa[x])?x:fa[x]=getfa(fa[x]); }
int findfa(int x){ return (x==fa[x])?x:getfa(fa[x]); }
bool ok(){
	int i,j,S=findfa(sta),T=findfa(gol);
	if (S==T) return 0;
	for (i=1; i<=tp; i++) rt[i]=findfa(q[i]);
	for (i=1; i<=tp; i++) if (rt[i]==S)
		for (j=1; j<=tp; j++) if (rt[j]==T && hsh.check(q[i],q[j])) return 0;
	return 1;
}
int main(){
	scanf("%d%d%d",&m,&n,&cas);
	int i,j,k,l,x,y;
	for (i=1; i<=m; i++) scanf("%s",a[i]+1);
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++) id[i][j]=(i-1)*n+j;
	sta=m*n+1; gol=sta+1;
	for (i=1; i<=gol; i++) fa[i]=i;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++) if (a[i][j]=='#'){
			x=id[i][j];
			for (k=0; k<8; k++)
				if (a[i+dx[k]][j+dy[k]]=='#')
					fa[getfa(x)]=getfa(id[i+dx[k]][j+dy[k]]);
			if (i==m || j==1) fa[getfa(x)]=getfa(sta);
			if (i==1 || j==n) fa[getfa(x)]=getfa(gol);
		}
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++){
			if (i+1==m || j==2) hsh.ins(getfa(sta),getfa(id[i][j]));
			if (i==2 || j+1==n) hsh.ins(getfa(gol),getfa(id[i][j]));
			for (k=0; k<8; k++)
				for (l=0; l<k; l++)
					if (abs(dx[k]-dx[l])==2 && abs(dy[k]-dy[l])==2 && (x=id[i+dx[k]][j+dy[k]]) && (y=id[i+dx[l]][j+dy[l]]))
						hsh.ins(getfa(x),getfa(y));
			}
	for (i=1; i<=gol; i++) fa0[i]=getfa(i);
	while (cas--){
		scanf("%d",&cnt);
		q[1]=sta; q[tp=2]=gol; vis[sta]=vis[gol]=1;
		if (!vis[fa[sta]]){ q[++tp]=fa[sta]; vis[fa[sta]]=1; }
		if (!vis[fa[gol]]){ q[++tp]=fa[gol]; vis[fa[gol]]=1; }
		for (i=1; i<=cnt; i++){
			scanf("%d%d",&bx[i],&by[i]);
			a[bx[i]][by[i]]='#';
			q[++tp]=x=id[bx[i]][by[i]]; vis[x]=1;
			for (k=0; k<8; k++) if (a[bx[i]+dx[k]][by[i]+dy[k]]=='#'){
				y=findfa(id[bx[i]+dx[k]][by[i]+dy[k]]);
				if (!vis[y]){ q[++tp]=y; vis[y]=1; }
				fa[findfa(x)]=y;
			}
			if (bx[i]==m || by[i]==1) fa[findfa(x)]=findfa(sta);
			if (bx[i]==1 || by[i]==n) fa[findfa(x)]=findfa(gol);
		}
		puts((ok())?"YES":"NO"); fflush(stdout);
		for (i=1; i<=cnt; i++) a[bx[i]][by[i]]='.';
		for (i=1; i<=tp; i++){
			vis[q[i]]=0; fa[q[i]]=fa0[q[i]];
		}
	}
	return 0;
}
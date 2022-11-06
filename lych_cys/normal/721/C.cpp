#include<bits/stdc++.h>
#define N 5005
using namespace std;

int d[N][N],pre[N][N],tot,fst[N],nxt[N],pnt[N],len[N],n,m,t; bool vis[N];
void add(int x,int y,int z){pnt[++tot]=y;len[tot]=z;nxt[tot]=fst[x];fst[x]=tot;}
void dp(int x){
	int i,j,y;
	if (vis[x]) return; vis[x]=1;
		if (x==1) d[x][1]=0;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];dp(y);
		for (j=1; j<=n; j++)
			if (d[y][j-1]+len[i]<d[x][j]){
				d[x][j]=d[y][j-1]+len[i]; pre[x][j]=y;
			}
	}
}
void solve(int x,int y){
	if (y>1) solve(pre[x][y],y-1);printf("%d ",x);
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	int i,x,y,z;
	for (i=1; i<=m; i++){
		scanf("%d%d%d",&x,&y,&z);
		add(y,x,z);
	}
	memset(d,0x3f,sizeof(d));
	//cout<<d[0][0]<<endl;
	dp(n);
	for (i=n; i; i--) if (d[n][i]<=t) break;
	//	cout<<d[n][i]<<endl;
	printf("%d\n",i);
	solve(n,i);
	return 0;
}
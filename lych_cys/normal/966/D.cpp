#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define N 300009
#define M 600009
using namespace std;

int n,m,tot,fst[N],pnt[M],nxt[M],dgr[N],fa[N],h[N],d[N]; bool vis[N];
void add(int x,int y){
	dgr[x]++;
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;	
}
void opt(int n){
	if (!n) return; opt(fa[n]); printf("%d ",n);
}
void solve(int x){
	int i,j,y,z;
	puts("5");
	memset(vis,0,sizeof(vis));
	for (i=fst[x]; i; i=nxt[i]) vis[pnt[i]]=1;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y==1) continue;
		for (j=fst[y]; j; j=nxt[j]){
			z=pnt[j];
			if (z==x || z==1 || vis[z]) continue;
			printf("1 %d %d %d %d %d\n",z,y,x,z,n);
			exit(0);
		}
	}
}
void work(int sta){
	int head=0,tail=1,i,x,y; h[1]=sta; vis[sta]=1;
	int pt=0; ll eg=0;
	while (head<tail){
		x=h[++head]; pt++; eg+=dgr[x]-1;
		for (i=fst[x]; i; i=nxt[i]){
			y=pnt[i];
			if (y!=1 && !vis[y]){
				vis[y]=1; h[++tail]=y;
			}
		}
	}
	if (eg==(ll)pt*(pt-1)) return;
	for (i=1; i<=tail; i++){
		x=h[i];
		if (dgr[x]!=pt) solve(x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int i,x,y;
	for (i=1; i<=m; i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);	
	}
	int head=0,tail=1; h[1]=1;
	memset(d,-1,sizeof(d)); d[1]=0;
	while (head<tail){
		x=h[++head];
		for (i=fst[x]; i; i=nxt[i]){
			y=pnt[i];
			if (d[y]==-1){
				d[y]=d[x]+1; fa[y]=x; h[++tail]=y;
			}
		}
	}
	if (d[n]!=-1 && d[n]<=4){
		printf("%d\n",d[n]); opt(n); puts(""); return 0;	
	}
	for (i=2; i<n; i++) if (d[i]==2){
		puts("4");
		printf("1 %d %d 1 %d\n",fa[i],i,n); return 0;
	}
	for (i=2; i<n; i++) if (!vis[i] && d[i]==1) work(i);
	puts("-1");
	return 0;
}
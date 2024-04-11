#include<bits/stdc++.h>
#define inf 1000000000
#define N 100009
#define M 309
using namespace std;

int n,cnt,mx,fst[9],nxt[N],a[N],b[M],c[9][M],h[N],d[N][9],f[9][9];
long long res; bool vis[N]; char ch[N];
void bfs(int c){
	int head=0,tail=0,i,x,y;
	for (i=1; i<=n; i++) if (a[i]==c){
		d[i][c]=0; h[++tail]=i;
	}
	memset(vis,0,sizeof(vis)); vis[c]=1; f[c][c]=0;
	while (head<tail){
		x=h[++head];
		if (!vis[a[x]]){
			vis[a[x]]=1; f[c][a[x]]=d[x][c];
			for (y=fst[a[x]]; y; y=nxt[y]) if (d[y][c]>inf){
				d[y][c]=d[x][c]+1; h[++tail]=y;
			}
		}
		if (x>1 && d[x-1][c]>inf){
			d[x-1][c]=d[x][c]+1; h[++tail]=x-1;
		}
		if (x<n && d[x+1][c]>inf){
			d[x+1][c]=d[x][c]+1; h[++tail]=x+1;
		}
	}
}
void update(int x,int y){
	if (x>mx){ mx=x; res=y; }
	else if (x==mx) res+=y;
}
int main(){
	int cas=1;// scanf("%d",&cas);
	while (cas--){
		scanf("%d%s",&n,ch+1);
		if (n==1){ puts("0 1"); continue; }
		int i,j,k,x,y;
		memset(fst,0,sizeof(fst));
		for (i=1; i<=n; i++){
			a[i]=ch[i]-'a'; nxt[i]=fst[a[i]]; fst[a[i]]=i;
		}
		memset(d,60,sizeof(d)); memset(f,60,sizeof(f));
		for (i=0; i<8; i++) bfs(i);
		mx=0; res=0;
		for (i=1; i<=n; i++){
			for (j=max(1,i-15); j<i; j++){
				x=i-j;
				for (k=0; k<8; k++) x=min(x,d[j][k]+d[i][k]+1);
				update(x,1);
			}
			if (i>16){
				b[cnt=1]=0; x=a[i-16];
				for (j=0; j<8; j++) if (d[i-16][j]>f[x][j]){
					for (k=1; k<=cnt; k++)
						b[k+cnt]=b[k]|1<<j;
					cnt<<=1;
				}
				while (cnt) c[x][b[cnt--]]++;
			}
			for (j=0; j<8; j++) if (c[j][0]){
				x=inf;
				for (k=0; k<8; k++) x=min(x,f[j][k]+d[i][k]+1);
				if (x==inf) continue;
				for (k=y=0; k<8; k++)
					if (f[j][k]+d[i][k]+1==x) y|=1<<k;
				if (c[j][y]) update(x+1,c[j][y]);
					else update(x,c[j][0]);
			}
		}
		printf("%d %lld\n",mx,res);
	}
	return 0;
}
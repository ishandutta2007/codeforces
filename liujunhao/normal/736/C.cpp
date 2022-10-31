#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MOD 1000000007
#define MAXN 100
#define MAXK 20
#define MAXK 20
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int f[MAXN+10][MAXK+2][MAXK+2],n,k,g[2][MAXK+2][MAXK+2],ans;
struct node{
	int v;
	node *next;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	Read(n),Read(k);
	int i,u,v;
	for(i=1;i<n;i++){
		Read(u),Read(v);
		addedge(u,v);
		addedge(v,u);
	}
}
void dfs(int u,int fa){
	for(node *p=adj[u];p;p=p->next)
		if(p->v!=fa)
			dfs(p->v,u);
	memset(g,0,sizeof g);
	int now=0,i,j,x,y;
	g[0][0][k+1]=1;
	for(node *p=adj[u];p;p=p->next){
		if(p->v!=fa){
			now^=1;
			memset(g[now],0,sizeof g[now]);
			for(i=0;i<=k+1;i++)
				for(j=0;j<=k+1;j++)
					for(x=0;x<=k+1;x++)
						for(y=0;y<=k+1;y++){
							int tx=min(max(i+y<=k?0:i,j+x<=k?0:x),k+1),ty=min(j,y);
							g[now][tx][ty]=(g[now][tx][ty]+1ll*g[now^1][i][j]*f[p->v][x][y])%MOD;
						}
		}
	}
	for(i=0;i<=k;i++){
		for(j=0;j<=k+1;j++){
			if(i==0&&j<=k)
				f[u][i][min(j+1,k+1)]=(f[u][i][min(k+1,j+1)]+g[now][i][j])%MOD;
			else
				f[u][i+1][min(j+1,k+1)]=(f[u][i+1][min(k+1,j+1)]+g[now][i][j])%MOD;
			f[u][0][1]=(f[u][0][1]+g[now][i][j])%MOD;
		}
	}
}
int main()
{
	read();
	dfs(1,0);
	for(int i=0;i<=k+1;i++)
		ans=(ans+f[1][0][i])%MOD;
	printf("%d\n",ans);
}
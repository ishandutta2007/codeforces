#include<cstdio>
#define MAXN 2500
#include<algorithm>
#include<cstring>
#define INF 0x3fffffff
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int n,m,dfn[MAXN+10],low[MAXN+10],dcnt,size[MAXN+10],f[MAXN+10][MAXN+10][3][3];
struct node{
	int v;
	node *next;
}*adj[MAXN+10],edge[MAXN*4+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	Read(n),Read(m);
	int i,u,v;
	for(i=1;i<=m;i++){
		Read(u),Read(v);
		addedge(u,v);
		addedge(v,u);
	}
}
void dfs(int u,int fa){
	int i,j,k,a,b;
	size[u]=1;
	dfn[u]=low[u]=++dcnt;
	f[u][1][1][0]=f[u][0][0][0]=0;
	f[u][0][2][0]=1;
	for(node *p=adj[u];p;p=p->next){
		if(p->v!=fa&&dfn[p->v]<dfn[u]){
			if(!dfn[p->v]){
				dfs(p->v,u);
				size[u]+=size[p->v];
				low[u]=min(low[u],low[p->v]);
				for(a=size[u];a>=0;a--)
					for(i=0;i<3;i++)
						for(j=2;j>=0;j--){
							int mx=-INF;
							for(b=max(0,a-(size[u]-size[p->v]));b<=min(a,size[p->v]);b++)
								for(k=0;k<3;k++){
									if(i+k==3)
										continue;
									if(low[p->v]==dfn[u])
										mx=max(mx,f[u][a-b][i][j]+f[p->v][b][k][i]);
									else if(low[p->v]<dfn[u])
										mx=max(mx,f[u][a-b][i][0]+f[p->v][b][k][j]);
									else
										mx=max(mx,f[u][a-b][i][j]+f[p->v][b][k][0]);
								}
							f[u][a][i][j]=mx;
						}
			}
			else{
				low[u]=dfn[p->v];
				for(a=0;a<=size[u];a++){
					f[u][a][0][1]=f[u][a][0][2]=f[u][a][0][0];
					f[u][a][1][2]=f[u][a][2][1]=-INF;
					f[u][a][1][1]=f[u][a][1][0];
					f[u][a][2][2]=f[u][a][2][0];
				}
			}
		}
	}
	/*for(a=0;a<=size[u];a++){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++)
				printf("%d ",f[u][a][i][j]);
			puts("");
		}
		puts("");
	}
	puts("");*/
}
int main()
{
	read();
	memset(f,0xc0,sizeof f);
	dfs(1,0);
	for(int i=0;i<=n;i++){
		int ans=0;
		for(int j=0;j<3;j++)
			ans=max(ans,f[1][i][j][0]);
		printf("%d ",ans);
	}
}
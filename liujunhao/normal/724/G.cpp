#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 100000
#define MAXM 200000
#define MOD 1000000007
using namespace std;
template<class T>
void Read(T &x){
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
typedef long long LL;
struct node{
	int v;
	LL wt;
	node *next;
}*adj[MAXN+10],edge[MAXM*2+10],*ecnt=edge;
int n,m,c[60],cnt,dfn[MAXN+10],dcnt,cc[60][2],ans;
LL a[61],dep[MAXN+10];
inline void addedge(int u,int v,LL wt){
	node *p=++ecnt;
	p->v=v;
	p->wt=wt;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	Read(n),Read(m);
	int i,u,v;
	LL wt;
	for(i=1;i<=m;i++){
		Read(u),Read(v),Read(wt);
		addedge(u,v,wt);
		addedge(v,u,wt);
	}
}
void gaussian_elimination(LL b){
	int j;
	for(j=0;j<60;j++)
		if(b&(1ll<<j)){
			if(!c[j]){
				a[++cnt]=b;
				c[j]=cnt;
				return;
			}
			else
				b^=a[c[j]];
		}
}
void dfs(int u,int fa){
	dfn[u]=++dcnt;
	for(int j=0;j<60;j++)
		cc[j][(dep[u]>>j)&1]++;
	for(node *p=adj[u];p;p=p->next){
		if(p->v!=fa){
			if(!dfn[p->v]){
				dep[p->v]=dep[u]^p->wt;
				dfs(p->v,u);
			}
			else if(dfn[p->v]<dfn[u])
				gaussian_elimination(dep[u]^dep[p->v]^p->wt);
		}
	}
}
void solve(int rt){
	memset(c,0,sizeof c);
	memset(cc,0,sizeof cc);
	cnt=0;
	dfs(rt,0);
	int i,j;
	for(i=0;i<60;i++){
		for(j=1;j<=cnt;j++)
			if((a[j]>>i)&1)
				break;
		if(cnt&&j<=cnt)
			ans=(ans+1ll*(cc[i][0]+cc[i][1])*(cc[i][0]+cc[i][1]-1)/2%MOD*((1ll<<(cnt-1))%MOD)%MOD*((1ll<<i)%MOD)%MOD)%MOD;
		else
			ans=(ans+1ll*cc[i][0]*cc[i][1]%MOD*((1ll<<cnt)%MOD)%MOD*((1ll<<i)%MOD)%MOD)%MOD;
	}
}
void solve(){
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			solve(i);
}
int main()
{
	read();
	solve();
	printf("%d\n",ans);
}
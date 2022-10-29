#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

#define K 17

vector<pair<int,int> > g[1<<K];int n;
int F[K][1<<K],D[1<<K];ll d[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i].fst,c=g[x][i].snd;if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;d[y]=d[x]+c;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;d[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}
ll dist(int x, int y){return d[x]+d[y]-2*d[lca(x,y)];}

int m;

int uf[1<<K];

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}
void join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)return;
	uf[x]=y;
}

vector<pair<pair<int,int>,int> > e;
ll f[64][64];
int q;
int u[1<<K];
int w[64];
ll a[64],b[64];

int main(){
	memset(uf,-1,sizeof(uf));
	memset(u,-1,sizeof(u));
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);x--;y--;
		if(find(x)==find(y))e.pb(mp(mp(x,y),c));	
		else {
			g[x].pb(mp(y,c));
			g[y].pb(mp(x,c));
			join(x,y);
		}
	}
	lca_init();
	for(auto p:e){
		int x=p.fst.fst,y=p.fst.snd;
		if(u[x]<0)u[x]=q,w[q++]=x;
		if(u[y]<0)u[y]=q,w[q++]=y;
	}
	fore(i,0,q)fore(j,0,q)f[i][j]=dist(w[i],w[j]);
	for(auto p:e){
		int x=p.fst.fst,y=p.fst.snd,c=p.snd;
		f[u[x]][u[y]]=min(f[u[x]][u[y]],1LL*c);
		f[u[y]][u[x]]=min(f[u[y]][u[x]],1LL*c);
	}
	fore(k,0,q)fore(i,0,q)fore(j,0,q)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int poron;
	scanf("%d",&poron);
	while(poron--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		ll r=dist(x,y);
		fore(i,0,q)a[i]=dist(x,w[i]);
		fore(i,0,q)b[i]=dist(y,w[i]);
		fore(i,0,q)fore(j,0,q)r=min(r,a[i]+f[i][j]+b[j]);
		printf("%lld\n",r);
	}
	return 0;
}
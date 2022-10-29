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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MAXN 256
#define INF (1<<30)

int nodes,src,dst;
int dist[MAXN],q[MAXN],work[MAXN];
struct edge {int to,rev;ll f,cap;};
vector<edge> g[MAXN];
void add_edge(int s, int t, ll cap){
	g[s].pb((edge){t,SZ(g[t]),0,cap});
	g[t].pb((edge){s,SZ(g[s])-1,0,0});
}
bool dinic_bfs(){
	fill(dist,dist+nodes,-1);dist[src]=0;
	int qt=0;q[qt++]=src;
	for(int qh=0;qh<qt;qh++){
		int u=q[qh];
		fore(i,0,g[u].size()){
			edge &e=g[u][i];int v=g[u][i].to;
			if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
		}
	}
	return dist[dst]>=0;
}
ll dinic_dfs(int u, ll f){
	if(u==dst)return f;
	for(int &i=work[u];i<g[u].size();i++){
		edge &e=g[u][i];
		if(e.cap<=e.f)continue;
		int v=e.to;
		if(dist[v]==dist[u]+1){
			ll df=dinic_dfs(v,min(f,e.cap-e.f));
			if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
		}
	}
	return 0;
}
ll max_flow(int _src, int _dst){
	src=_src;dst=_dst;
	ll result=0;
	while(dinic_bfs()){
		fill(work, work+nodes, 0);
		while(ll delta=dinic_dfs(src,INF))result+=delta;
	}
	return result;
}

int n;
vector<int> a,b;
int ai[256],bi[256];
vector<vector<int> > r;
bool isp[20005];
bool vis[256];
vector<int> gg[256];

int main(){
	mset(isp,true);
	fore(i,2,20005)if(isp[i])for(int j=i+i;j<20005;j+=i)isp[j]=false;
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		if(x%2==0)ai[SZ(a)]=i,a.pb(x);
		else bi[SZ(b)]=i,b.pb(x);
	}
	if(SZ(a)!=SZ(b)){puts("Impossible");return 0;}
	nodes=2+n;
	fore(i,0,SZ(a))add_edge(0,2+i,2);
	fore(i,0,SZ(b))add_edge(2+SZ(a)+i,1,2);
	fore(i,0,SZ(a))fore(j,0,SZ(b))if(isp[a[i]+b[j]])add_edge(2+i,2+SZ(a)+j,1);
	if(max_flow(0,1)!=n){puts("Impossible");return 0;}
	fore(i,0,SZ(a))for(auto p:g[2+i])if(p.cap&&p.f){
		int x=ai[i],y=bi[p.to-SZ(a)-2];
		gg[x].pb(y);gg[y].pb(x);
	}
	fore(i,0,n)assert(SZ(gg[i])==2);
	fore(i,0,n)if(!vis[i]){
		vector<int> v={i};vis[i]=true;
		for(int j=gg[i][0],l=i,t;j!=i;t=l,l=j,j=gg[j][0]^gg[j][1]^t)
			vis[j]=true,v.pb(j);
		r.pb(v);
	}
	printf("%d\n",SZ(r));
	for(auto v:r){
		printf("%d",SZ(v));
		for(int x:v)printf(" %d",x+1);
		puts("");
	}
	return 0;
}
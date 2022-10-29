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

#define MAXN 2048

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
		fore(i,0,SZ(g[u])){
			edge& e=g[u][i];int v=g[u][i].to;
			if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
		}
	}
	return dist[dst]>=0;
}
ll dinic_dfs(int u, ll f){
	if(u==dst)return f;
	for(int& i=work[u];i<SZ(g[u]);i++){
		edge& e=g[u][i];
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
	ll r=0;
	while(dinic_bfs()){
		fill(work,work+nodes,0);
		while(ll d=dinic_dfs(src,1LL<<60))r+=d;
	}
	return r;
}

int n,m,k,c;
int d[605],r[605];

void perdi(){printf("0");fore(_,1,m)printf(" 0");puts("");}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%d%d",&n,&m,&k);
		mset(d,0);
		fore(i,0,nodes)g[i].clear();
		nodes=n+m+2;
		fore(i,0,m){
			int x,y;
			scanf("%d%d",&x,&y);x--;y--;
			d[x]++;d[y]++;
			add_edge(2+x,2+n+i,1);
			add_edge(2+y,2+n+i,1);
			add_edge(2+n+i,1,1);
		}
		bool can=true;int q=0;
		fore(i,0,n){
			int t=d[i];
			if(t>2*k){can=false;break;}
			if(t<=k)continue;
			add_edge(0,2+i,(t-k)*2);
			q+=(t-k)*2;
		}
		if(!can){perdi();continue;}
		if(max_flow(0,1)<q){perdi();continue;}
		mset(r,-1);
		c=1;
		fore(i,0,n){
			int t=0;
			for(auto p:g[2+i]){
				if(!p.cap)continue;
				if(p.f){
					int j=p.to-2-n;
					r[j]=c;
					t^=1;
					if(!t)c++;
				}
			}
		}
		fore(i,0,m)if(r[i]<0)r[i]=c++;
		fore(i,0,m)printf("%d%c",r[i]," \n"[i==m-1]);
	}
	return 0;
}
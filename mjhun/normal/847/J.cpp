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

const ll MAXN=2e4+10, INF=1LL<<60;
int nodes,src,dst; // remember to init nodes
int dist[MAXN],q[MAXN],work[MAXN];
struct edge {int to,rev;ll f,cap;};
vector<edge> g[MAXN];
void add_edge(int s, int t, ll cap){
	g[s].pb((edge){t,g[t].size(),0,cap});
	g[t].pb((edge){s,g[s].size()-1,0,0});
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

int n, m;
vector<pair<int,int> > ee;
void reset(int val){
  memset(work,0,sizeof(work));
	fore(x,0,n+m+2)g[x].clear();
	fore(x,1,n+1) add_edge(0,x,val);
	fore(x,1,m+1){
		add_edge(ee[x-1].first, n+x,1);
		add_edge(ee[x-1].second, n+x,1);
		add_edge(n+x,n+m+1,1);
	}
}
int main(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;nodes=n+m+2;
	fore(x,0,m){
		int u,v; cin>>u>>v;
		ee.pb({u,v});
	}

	int low=0,high=5000,mid,ans=high;
	while(low<=high){
		mid=(low+high)/2;reset(mid);
		if(max_flow(0,n+m+1)==m){
			high=mid-1; ans=min(ans,mid);
		}else low=mid+1;
	}

	cout << ans << "\n"; reset(ans);max_flow(0,n+m+1);

  fore(x,1,m+1){
    if(g[n+x][0].f || g[n+x][0].cap){
      cout << g[n+x][0].to << " " << g[n+x][1].to << "\n";
    }else if(g[n+x][1].f || g[n+x][1].cap){
      cout << g[n+x][1].to << " " << g[n+x][0].to << "\n";
    }
  }

	return 0;
}
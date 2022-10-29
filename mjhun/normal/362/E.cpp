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

#define MAXN 64

typedef ll tf;const tf INFFLUJO=1e14;
typedef ll tc;const tc INFCOSTO=1e14;
struct edge {
	int u,v;tf cap,flow;tc cost;
	tf rem(){return cap-flow;}
};
int nodes;
vector<int> g[MAXN];
vector<edge> e;
void add_edge(int u, int v, tf cap, tc cost) {
	g[u].pb(e.size());e.pb((edge){u,v,cap,0,cost});
	g[v].pb(e.size());e.pb((edge){v,u,0,0,-cost});
}
tc dist[MAXN],mncost;
int pre[MAXN];
tf cap[MAXN],mxflow;
bool in_queue[MAXN];
void flow(int s, int t){
	memset(in_queue,0,sizeof(in_queue));
	mxflow=mncost=0;
	while(1){
		fill(dist,dist+nodes,INFCOSTO);dist[s]=0;
		memset(pre,-1,sizeof(pre));pre[s]=0;
		memset(cap,0,sizeof(cap));cap[s]=INFFLUJO;
		queue<int> q;q.push(s);in_queue[s]=1;
		while(q.size()){
			int u=q.front();q.pop();in_queue[u]=0;
			fore(_,0,g[u].size()){
				int i=g[u][_];
				edge &E=e[i];
				if(E.rem()&&dist[E.v]>dist[u]+E.cost){
					dist[E.v]=dist[u]+E.cost;
					pre[E.v]=i;
					cap[E.v]=min(cap[u],E.rem());
					if(!in_queue[E.v])q.push(E.v),in_queue[E.v]=1;
				}
			}
		}
		if(pre[t]<0)break;
		mxflow+=cap[t];mncost+=cap[t]*dist[t];
		for(int v=t;v!=s;v=e[pre[v]].u){
			e[pre[v]].flow+=cap[t];e[pre[v]^1].flow-=cap[t];
		}
	}
}

int b[64][64];
int n,k;

bool can(ll f){
	fore(i,0,nodes)g[i].clear();
	e.clear();
	fore(i,0,n)fore(j,0,n)if(b[i][j]){
		add_edge(i,j,b[i][j],0);
		add_edge(i,j,1<<30,1);
	}
	add_edge(n,0,f,0);
	flow(n,n-1);
	assert(mxflow==f);
	return mncost<=k;
}

int main(){
	scanf("%d%d",&n,&k);nodes=n+1;
	fore(i,0,n)fore(j,0,n){
		scanf("%d",&b[i][j]);
		if(b[i][j])add_edge(i,j,b[i][j],0);
	}
	flow(0,n-1);
	if(!mxflow){puts("0");return 0;}
	ll s=mxflow,e=mxflow+k+1;
	while(e-s>1){
		ll m=(s+e)/2;
		if(can(m))s=m;
		else e=m;
	}
	printf("%lld\n",s);
	return 0;
}
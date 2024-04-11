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

#define MAXN 200050
#define INF (1LL<<60)

int nodes,src,dst;
int dist[MAXN],q[MAXN],work[MAXN];
struct edge {int to,rev;ll f,cap,id;};
vector<edge> g[MAXN];
ll dd[MAXN];
void add_edge(int s, int t, ll cap, ll mincap=0, int id=-1){
	//printf(" %d %d %lld %lld\n",s,t,mincap,cap);
	mincap=max(mincap,0LL);
	if(mincap>cap){puts("-1");exit(0);}
	assert(mincap<=cap);
	dd[s]+=mincap;dd[t]-=mincap;
	g[s].pb((edge){t,SZ(g[t]),0,cap-mincap,id});
	g[t].pb((edge){s,SZ(g[s])-1,0,0,-1});
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
ll max_flow_min_cap(int s, int t){
	add_edge(t,s,INF);
	ll w=0;
	fore(i,0,nodes){
		if(dd[i]>0)add_edge(i,nodes+1,dd[i]),w+=dd[i];
		else if(dd[i]<0)add_edge(nodes,i,-dd[i]);
	}
	nodes+=2;
	if(max_flow(nodes-2,nodes-1)!=w)return -1;
	nodes-=2;
	fore(i,0,nodes)if(dd[i])g[i].pop_back();
	//ll r=g[t].back().f;
	//g[s].pop_back();g[t].pop_back();
	return max_flow(s,t);
}

int n,m,rr,bb;
int x[100005],y[100005],qx[100005],qy[100005];
vector<int> xs,ys;
int a[100005],b[100005];
char ans[100005];

int main(){
	scanf("%d%d%d%d",&n,&m,&rr,&bb);
	fore(i,0,n)scanf("%d%d",x+i,y+i),xs.pb(x[i]),ys.pb(y[i]);
	sort(xs.begin(),xs.end());xs.erase(unique(xs.begin(),xs.end()),xs.end());
	sort(ys.begin(),ys.end());ys.erase(unique(ys.begin(),ys.end()),ys.end());
	fore(i,0,n){
		x[i]=lower_bound(xs.begin(),xs.end(),x[i])-xs.begin();
		y[i]=lower_bound(ys.begin(),ys.end(),y[i])-ys.begin();
		qx[x[i]]++;qy[y[i]]++;
	}
	fore(i,0,n)a[i]=b[i]=1<<29;
	while(m--){
		int t,l,d;
		scanf("%d%d%d",&t,&l,&d);
		if(t==1){
			int k=lower_bound(xs.begin(),xs.end(),l)-xs.begin();
			if(k<SZ(xs)&&xs[k]==l)a[k]=min(a[k],d);
		}
		else {
			int k=lower_bound(ys.begin(),ys.end(),l)-ys.begin();
			if(k<SZ(ys)&&ys[k]==l)b[k]=min(b[k],d);
		}
	}
	fore(i,0,SZ(xs))add_edge(0,2+i,(qx[i]+a[i])/2,(qx[i]-a[i]+1)/2);
	fore(i,0,SZ(ys))add_edge(2+SZ(xs)+i,1,(qy[i]+b[i])/2,(qy[i]-b[i]+1)/2);
	fore(i,0,n)add_edge(2+x[i],2+SZ(xs)+y[i],1,0,i);
	nodes=2+SZ(xs)+SZ(ys);
	//puts("holis");
	int r=max_flow_min_cap(0,1);
	if(r<0){puts("-1");return 0;}
	if(r<(n+1)/2){
		assert(0);
		//printf(" %d %d\n",r,dd[0]);
	}
	printf("%lld\n",1LL*r*min(rr,bb)+1LL*(n-r)*max(rr,bb));
	fore(i,0,SZ(xs))for(auto e:g[2+i])if(e.id>=0){
		if(e.f){
			if(rr<bb)ans[e.id]='r';
			else ans[e.id]='b';
		}
		else {
			if(rr<bb)ans[e.id]='b';
			else ans[e.id]='r';
		}
	}
	puts(ans);
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll INF=(1ll<<30);

// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
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
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

const int MAXN=100005;

vector<pair<ll,ll>> ed;

vector<ll> g[MAXN];

ll vis[MAXN],c[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			c[i]=c[v]^1;
			dfs(i);
		}
	}
}

/*----------------DSU------------------*/
int pa[MAXN],sz[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

set<pair<ll,ll>> edr;

pair<ll,ll> rep(ll a, ll b){
	return {min(a,b),max(a,b)};
}

ll cant[MAXN];

vector<pair<ll,ll>> res[2];

vector<ll> qu[2];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ed.clear();
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y; cin>>x>>y; x--; y--;
			ed.pb({x,y});
			g[x].pb(y);
			g[y].pb(x);
		}
		fore(i,0,n)vis[i]=0,c[i]=0;
		dfs(0);
		Dinic d(n+2);
		fore(i,0,n){
			if(c[i]==0){
				d.add_edge(n,i,2);
			}else{
				d.add_edge(i,n+1,2);
			}
		}
		for(auto i:ed){
			assert(c[i.fst]+c[i.snd]==1);
			if(c[i.fst]==0){
				d.add_edge(i.fst,i.snd,1);
			}else{
				d.add_edge(i.snd,i.fst,1);
			}
		}
		d.max_flow(n,n+1);
		dsu_init(n);
		edr.clear();
		for(auto i:ed){
			edr.insert({rep(i.fst,i.snd)});
		}
		fore(i,0,n)cant[i]=0;
		fore(i,0,n){
			for(auto j:d.g[i]){
				if(j.to<n&&j.f==1){
					//cout<<"ar: "<<i<<" "<<j.to<<endl;
					edr.erase(rep(i,j.to));
					join(i,j.to);
					cant[i]++;
					cant[j.to]++;
				}
			}
		}
		//cout<<SZ(edr)<<endl;
		qu[0].clear();
		qu[1].clear();
		fore(i,0,n){
			if(cant[i]<2){
				qu[cant[i]].pb(i);
			}
		}
		res[0].clear();
		res[1].clear();
		for(auto i:edr)res[0].pb(i);
		while(SZ(qu[0])>=2){
			ll a=qu[0].back();
			qu[0].pop_back();
			ll b=qu[0].back();
			qu[0].pop_back();
			res[1].pb({a,b});
			join(a,b);
			cant[a]++;
			cant[b]++;
			qu[1].pb(a);
			qu[1].pb(b);
		}
		
		if(SZ(qu[0])){
			ll a=qu[0].back();
			qu[0].pop_back();
			ll b=qu[1].back();
			qu[1].pop_back();
			res[1].pb({a,b});
			join(a,b);
			cant[a]++;
			cant[b]++;
			qu[1].pb(a);
		}
		
		while(SZ(qu[1])>2){
			ll a=qu[1].back();
			qu[1].pop_back();
			ll b=qu[1].back();
			qu[1].pop_back();
			ll c=qu[1].back();
			qu[1].pop_back();
			if(find_pa(a)!=find_pa(b)){
				res[1].pb({a,b});
				cant[a]++;
				cant[b]++;
				join(a,b);
			}else if(find_pa(a)!=find_pa(c)){
				res[1].pb({a,c});
				cant[a]++;
				cant[c]++;
				join(a,c);
			}else if(find_pa(c)!=find_pa(b)){
				res[1].pb({c,b});
				cant[c]++;
				cant[b]++;
				join(c,b);
			}
			if(cant[a]<2)qu[1].pb(a);
			if(cant[b]<2)qu[1].pb(b);
			if(cant[c]<2)qu[1].pb(c);
		}
		//cout<<"HOLAAAAa"<<endl;
		assert(SZ(res[0])==SZ(res[1]));
		cout<<SZ(res[0])<<"\n";
		fore(i,0,SZ(res[0])){
			cout<<res[0][i].fst+1<<" "<<res[0][i].snd+1<<" ";
			cout<<res[1][i].fst+1<<" "<<res[1][i].snd+1<<"\n";
		}
	}
	
	return 0;
}
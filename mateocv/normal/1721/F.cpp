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

ll INF=1e9;

// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),dist(x),q(x),work(x),g(x){}
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

map<pair<ll,ll>,ll> ed;

int main(){FIN;
	ll n,m,e,q; cin>>n>>m>>e>>q;
	Dinic d(n+m+2);
	fore(i,0,e){
		ll x,y; cin>>x>>y; x--; y--;
		d.add_edge(x,n+y,1);
		ed[{x,y}]=i;
	}
	fore(i,0,n)d.add_edge(n+m,i,1);
	fore(i,0,m)d.add_edge(n+i,n+m+1,1);
	d.max_flow(n+m,n+m+1);
	vector<pair<ll,ll>> vc;
	fore(i,0,n){
		for(auto j:d.g[i]){
			if(n<=j.to&&j.to<n+m&&j.f==1){
				vc.pb({ed[{i,j.to-n}]+1,(d.dist[i]<0)?i+1:-(j.to-n+1)});
			}
		}
	}
	ll s=0;
	for(auto i:vc)s+=i.fst;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			cout<<"1\n"<<vc.back().snd<<"\n"<<s-vc.back().fst<<endl;
			s-=vc.back().fst;
			vc.pop_back();
		}else{
			cout<<SZ(vc)<<"\n";
			for(auto i:vc)cout<<i.fst<<" ";
			cout<<endl;
		}
	}
	
	return 0;
}
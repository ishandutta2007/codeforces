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
typedef int ll;

const int MAXN=1010;

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN][MAXN];
void dijkstra(int v){
	fore(i,0,MAXN)dist[v][i]=-1;
	priority_queue<pair<ll,int> > q;
	ll x=v;
	dist[v][x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[v][x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[v][y]<0||dist[v][x]+c<dist[v][y])
				dist[v][y]=dist[v][x]+c,q.push({-dist[v][y],y});
		}
	}
}

vector<pair<ll,ll>> ed,q;

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--; v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
		ed.pb({u,v});
	}
	fore(i,0,n){
		dijkstra(i);
	}
/*	fore(i,0,n){
		fore(j,0,n){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	fore(i,0,k){
		ll a,b; cin>>a>>b; a--; b--;
		q.pb({a,b});
	}
	ll res=0;
	for(auto i:q){
		res+=dist[i.fst][i.snd];
	}
	for(auto i:ed){
		ll va=0;
		for(auto j:q){
			va+=min({dist[j.fst][i.fst]+dist[i.snd][j.snd],dist[j.fst][i.snd]+dist[i.fst][j.snd],dist[j.fst][j.snd]});
		}
		res=min(res,va);
	}
	cout<<res<<"\n";
	return 0;
}
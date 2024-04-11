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

ll n,m;

const int MAXN=6000006;

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

vector<pair<pair<ll,ll>,ll>> ed;

bool vis[MAXN];

int main(){FIN;
	cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--; v--;
		ed.pb({{u,v},w});
		vis[w*n+u]=1;
		vis[w*n+v]=1;
	}
	for(auto i:ed){
		ll u=i.fst.fst,v=i.fst.snd,w=i.snd;
		g[u].pb({w*n+v,w*w});
		g[v].pb({w*n+u,w*w});
		fore(j,1,51){
			if(vis[j*n+u])g[j*n+u].pb({v,2*j*w+w*w});
			if(vis[j*n+v])g[j*n+v].pb({u,2*j*w+w*w});
		}
	}
	dijkstra(0);
	fore(i,0,n)cout<<dist[i]<<" ";
	cout<<"\n";
	
	return 0;
}
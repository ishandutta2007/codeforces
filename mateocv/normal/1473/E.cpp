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

const int MAXN=800005;

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

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll x,y,w; cin>>x>>y>>w; x--; y--;
		fore(j,0,4){
			g[n*j+x].pb({n*j+y,w});
			g[n*j+y].pb({n*j+x,w});
		}
		g[x].pb({n+y,2*w});
		g[x].pb({2*n+y,0});
		g[2*n+x].pb({3*n+y,2*w});
		g[n+x].pb({3*n+y,0});
		g[y].pb({n+x,2*w});
		g[y].pb({2*n+x,0});
		g[2*n+y].pb({3*n+x,2*w});
		g[n+y].pb({3*n+x,0});
	}
	dijkstra(0);
	fore(i,1,n)cout<<min(dist[3*n+i],dist[i])<<" ";
	cout<<"\n";
	
	return 0;
}
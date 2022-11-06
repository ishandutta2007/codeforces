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

const int MAXN=200005;
vector<ll> g[MAXN];

vector<pair<int,int> > gr[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x){
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,gr[x].size()){
			int y=gr[x][i].fst; ll c=gr[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

ll dp[MAXN][2];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==0)return res=0;
	res=dist[x];
	for(auto i:g[x]){
		if(dist[i]>dist[x]){
			res=min(res,f(i,y));
		}else{
			if(y)res=min(res,f(i,0));
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)g[i].clear();
		fore(i,0,n)gr[i].clear();
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			gr[u].pb({v,1});
		}
		fore(i,0,n)dist[i]=-1;
		dijkstra(0);
		fore(i,0,n)dp[i][0]=-1,dp[i][1]=-1;
		fore(i,0,n)cout<<f(i,1)<<" ";
		cout<<"\n";
	}
	
	return 0;
}
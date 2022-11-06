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

ll MOD=998244353;
const int MAXN=200005,k=20;

vector<ll> g[MAXN];

ll INF=9e18;

pair<int,int> operator+(pair<int,int> a, pair<int,int> b){
	return (pair<int,int>) {a.fst+b.fst,a.snd+b.snd};
}

vector<pair<int,pair<int,int>> > gr[k*MAXN];  // u->[(v,cost)]
pair<int,int> dist[k*MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<pair<int,int>,int> > q;
	dist[x]={0,0};q.push({{0,0},x});
	while(!q.empty()){
		x=q.top().snd;
		pair<int,int> c={-q.top().fst.fst,-q.top().fst.snd};
		q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,gr[x].size()){
			int y=gr[x][i].fst; pair<int,int> c=gr[x][i].snd;
			if(dist[y].fst<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({{-dist[y].fst,-dist[y].snd},y});
		}
	}
}

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
	}
	fore(i,0,k){
		fore(j,0,n){
			for(auto ii:g[j]){
				if(i&1){
					gr[i*n+ii].pb({i*n+j,{0,1}});
				}else{
					gr[i*n+j].pb({i*n+ii,{0,1}});
				}
			}
		}	
	}
	fore(i,0,k-1){
		fore(j,0,n){
			gr[i*n+j].pb({(i+1)*n+j,{0,1<<i}});
		}
	}
	dijkstra(0);
	ll res=INF;
	fore(i,0,k){
		if(dist[i*n+n-1].fst!=-1)res=min(res,(ll)dist[i*n+n-1].snd);
	}
	if(res!=INF){
		cout<<res%MOD<<"\n";
		return 0;
	}
	fore(i,0,k*n)gr[i].clear();
	fore(i,0,2){
		fore(j,0,n){
			for(auto ii:g[j]){
				if(i&1){
					gr[i*n+ii].pb({i*n+j,{0,1}});
				}else{
					gr[i*n+j].pb({i*n+ii,{0,1}});
				}
			}
		}	
	}
	fore(i,0,2){
		fore(j,0,n){
			gr[i*n+j].pb({(i^1)*n+j,{1,0}});
		}
	}
	dijkstra(0);
	auto resf=min(dist[n-1],dist[n+n-1]);
	res=(fpow(2,resf.fst)+resf.snd+MOD-1)%MOD;
	cout<<res<<"\n";
	return 0;
}
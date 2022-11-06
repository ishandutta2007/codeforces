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

vector<ll> g[200005];
vector<ll> gr[200005];

ll vis[200005];

vector<ll> topo;

void dfs(ll v, ll b){
	if(vis[v])return;
	vis[v]=1;
	for(auto i:g[v]){
		dfs(i,b);
	}
	if(b)topo.pb(v);
}

ll visr[200005];

void dfsr(ll v){
	if(visr[v])return;
	visr[v]=1;
	for(auto i:gr[v]){
		dfsr(i);
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		g[v].pb(u);
		gr[u].pb(v);
	}
	fore(i,0,n)dfs(i,1);
	reverse(ALL(topo));
	ll u[n];
	assert(SZ(topo)==n);
	fore(i,0,n){
		u[topo[i]]=i;
	}
	fore(i,0,n){
		for(auto j:g[i]){
			if(u[j]<u[i]){
				cout<<-1;
				return 0;
			}
		}
	}
	mset(vis,0);
	ll cant=0;
	string res;
	fore(i,0,n){
		if(vis[i]==0&&visr[i]==0){
			cant++;
			res+='A';
			dfs(i,0);
			dfsr(i);
		}else{
			dfs(i,0);
			dfsr(i);
			res+='E';
		}
	}
	cout<<cant<<"\n"<<res;
	return 0;
}
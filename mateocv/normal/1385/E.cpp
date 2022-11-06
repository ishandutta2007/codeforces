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

vector<pair<ll,ll>> ed[2];

ll vis[MAXN];
vector<ll> ord;
ll ub[MAXN];

void dfs(ll v){
	if(vis[v])return;
	vis[v]=1;
	for(auto i:g[v])dfs(i);
	ord.pb(v);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,m){
			ll typ,u,v; cin>>typ>>u>>v; u--; v--;
			ed[typ].pb({u,v});
			if(typ==1){
				g[u].pb(v);
			}
		}
		fore(i,0,n)dfs(i);
		reverse(ALL(ord));
		fore(i,0,n)ub[ord[i]]=i;
		ll br=0;
		for(auto i:ed[1]){
			if(ub[i.fst]>ub[i.snd]){
				br++; break;
			}
		}
		if(br){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			for(auto i:ed[1])cout<<i.fst+1<<" "<<i.snd+1<<"\n";
			for(auto i:ed[0]){
				if(ub[i.fst]<ub[i.snd])cout<<i.fst+1<<" "<<i.snd+1<<"\n";
				else cout<<i.snd+1<<" "<<i.fst+1<<"\n";
			}
		}
		fore(i,0,n)g[i].clear();
		fore(k,0,2)ed[k].clear();
		fore(i,0,n)vis[i]=0,ub[i]=0;
		ord.clear();
	}
	
	return 0;
}
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

const int MAXN=100005;

vector<pair<ll,ll>> g[MAXN];

ll vis[MAXN],xp[MAXN];

ll n,a,b;

void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(vis[i.fst])continue;
		if(i.fst!=b){
			xp[i.fst]=xp[x]^i.snd;
			dfs(i.fst);
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>a>>b;
		a--; b--;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y,w; cin>>x>>y>>w; x--; y--;
			g[x].pb({y,w});
			g[y].pb({x,w});
		}
		fore(i,0,n)vis[i]=0,xp[i]=0;
		dfs(a);
		//fore(i,0,n)cout<<i<<" "<<vis[i]<<" "<<xp[i]<<"\n";
		set<ll> st;
		fore(i,0,n)st.insert(xp[i]);
		fore(i,0,n)vis[i]=0,xp[i]=0;
		dfs(b);
		//fore(i,0,n)cout<<i<<" "<<vis[i]<<" "<<xp[i]<<"\n";
		ll res=0;
		fore(i,0,n){
			if(i!=b){
				if(st.count(xp[i]))res=1;
			}
		}
		cout<<(res?"YES\n":"NO\n");
	}
	
	return 0;
}
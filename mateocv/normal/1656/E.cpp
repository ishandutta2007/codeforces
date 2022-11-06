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

vector<ll> g[MAXN];

ll vis[MAXN],c[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(vis[i])continue;
		c[i]=(c[x]^1);
		dfs(i);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		fore(i,0,n)vis[i]=0,c[i]=0;
		dfs(0);
		fore(i,0,n)cout<<(c[i]==0?1:-1)*SZ(g[i])<<" ";
		cout<<"\n";
	}
	
	return 0;
}
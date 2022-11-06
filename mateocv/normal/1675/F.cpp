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

ll vis[MAXN],d[MAXN],p[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(!vis[i]){
			d[i]=d[x]+1;
			p[i]=x;
			dfs(i);
		}
	}
}

void sub(ll x){
	if(x==-1||vis[x])return;
	vis[x]=1;
	sub(p[x]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll x,y; cin>>x>>y; x--; y--;
		vector<ll> a(k);
		fore(i,0,k)cin>>a[i],a[i]--;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(i,0,n)vis[i]=0,d[i]=0,p[i]=-1;
		dfs(x);
		fore(i,0,n)vis[i]=0;
		fore(i,0,k)sub(a[i]);
		sub(y);
		ll res=0;
		fore(i,0,n){
			res+=vis[i];
		}
		res--;
		res*=2;
		res-=d[y];
		cout<<res<<"\n";
	}
	
	return 0;
}
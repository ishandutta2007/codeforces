#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<pair<ll,ll>> ed;
vector<ll> g[5005];

ll vis[5005];
vector<ll> t;

void dfs(int v) {
  if(vis[v])return;
  vis[v]=1;
  for(int i:g[v])dfs(i);
  t.pb(v);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll vv,v;
	fore(i,0,m){
		cin>>vv>>v; vv--; v--;
		ed.pb({vv,v});
		g[vv].pb(v);
	}
	fore(i,0,n)dfs(i);
	ll u[n];
	fore(i,0,n){
		u[t[i]]=i;
	}
	vector<ll> res;
	fore(i,0,m){
		if(u[ed[i].fst]<u[ed[i].snd])res.pb(2);
		else res.pb(1);
	}
	ll maxi=0;
	fore(i,0,m)maxi=max(maxi,res[i]);
	cout<<maxi<<"\n";
	fore(i,0,m)cout<<res[i]<<" ";
	
	return 0;
}
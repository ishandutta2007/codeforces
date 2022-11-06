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

vector<ll> g[100005];

ll vis[100005];
ll c[100005];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(vis[i])continue;
		c[i]=1-c[v];
		dfs(i);
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	set<ll> st[2];
	ll tot=0;
	fore(i,0,n){
		if(SZ(g[i])==1){
			st[0].insert(c[i]);
			st[1].insert(g[i][0]);
			tot++;
		}
	}
	if(SZ(st[0])==1){
		cout<<"1 ";
	}else cout<<"3 ";
	cout<<n-1-tot+SZ(st[1]);
	
	
	return 0;
}
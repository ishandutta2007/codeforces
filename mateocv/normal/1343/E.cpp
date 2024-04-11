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

ll n,m,a,b,c;

vector<ll> d(ll v){
	ll vis[n];
	mset(vis,0);
	queue<ll>q;
	vis[v]=1;
	q.push(v);
	vector<ll> res(n,0);
	while(q.size()) {
		ll t=q.front(); q.pop();
		for(auto i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				q.push(i);
				res[i]=res[t]+1;
			}
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>a>>b>>c;
		a--; b--; c--;
		ll p[m];
		fore(i,0,m)cin>>p[i];
		sort(p,p+m);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		auto da=d(a);
		auto db=d(b);
		auto dc=d(c);
		//for(auto i:da)cout<<i<<" "; cout<<"\n";
		//for(auto i:db)cout<<i<<" "; cout<<"\n";
		//for(auto i:dc)cout<<i<<" "; cout<<"\n";
		ll sump[3*n];
		fore(i,0,3*n)sump[i]=1e18;
		sump[0]=0;
		fore(i,0,m)sump[i+1]=sump[i]+p[i];
		//fore(i,0,m+1)cout<<sump[i]<<" "; cout<<"\n";
		ll res=1e18;
		fore(i,0,n){
			res=min(res,sump[da[i]+db[i]+dc[i]]+sump[db[i]]);
		}
		cout<<res<<"\n";
		fore(i,0,n)g[i].clear();
	}
	
	return 0;
}
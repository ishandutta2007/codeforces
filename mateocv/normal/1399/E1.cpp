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

ll vis[MAXN],cant[MAXN],par[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(vis[i.fst])continue;
		dfs(i.fst);
		cant[v]+=cant[i.fst];
		par[i.fst]=i.snd;
	}
	if(SZ(g[v])==1)cant[v]=1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,s; cin>>n>>s;
		ll w[n];
		fore(i,0,n-1){
			ll u,v,we; cin>>u>>v>>we; u--; v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
			w[i]=we;
		}
		ll res=0,val=0;
		priority_queue<pair<ll,ll>> pq;
		dfs(0);
		//fore(i,0,n)cout<<cant[i]<<" "; cout<<endl;
		fore(i,1,n){
			val+=cant[i]*w[par[i]];
			pq.push({cant[i]*((w[par[i]]+1)/2),i});
		}
		while(val>s){
			auto f=pq.top(); pq.pop();
			val-=f.fst;
			w[par[f.snd]]/=2;
			pq.push({cant[f.snd]*((w[par[f.snd]]+1)/2),f.snd});
			res++;
		}
		cout<<res<<"\n";
		fore(i,0,n)g[i].clear();
		fore(i,0,n)vis[i]=0,cant[i]=0,par[i]=0;
	}
	
	return 0;
}
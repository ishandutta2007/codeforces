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

vector<ll> g[MAXN],gr[MAXN];

vector<ll> ord,u;

ll vis[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			dfs(i);
		}
	}
	ord.pb(v);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n)gr[i].clear();
		fore(i,0,n){
			ll k; cin>>k;
			fore(j,0,k){
				ll x; cin>>x; x--;
				gr[i].pb(x);
				g[x].pb(i);
			}
		}
		ord.clear();
		u.clear();
		fore(i,0,n)vis[i]=0;
		fore(i,0,n){
			if(!vis[i])dfs(i);
		}
		reverse(ALL(ord));
		u.resize(n);
		fore(i,0,n)u[ord[i]]=i;
		ll br=0;
		fore(i,0,n){
			for(auto j:g[i]){
				if(u[j]<u[i])br++;
			}
		}
		if(br){
			cout<<"-1\n";
			continue;
		}
		vector<pair<ll,ll>> vt(n);
		fore(i,0,n){
			vt[ord[i]]={1,ord[i]};
			for(auto j:gr[ord[i]]){
				vt[ord[i]]=max(vt[ord[i]],vt[j]);
			}
			if(vt[ord[i]].snd>ord[i]){
				vt[ord[i]].fst++;
			}
			vt[ord[i]].snd=ord[i];
		}
		pair<ll,ll> res={0,0};
		for(auto i:vt)res=max(res,i);
		cout<<res.fst<<"\n";
	}
	
	return 0;
}
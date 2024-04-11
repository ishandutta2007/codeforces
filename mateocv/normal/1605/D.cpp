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

bool vis[MAXN];
ll c[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			c[i]=c[v]^1;
			dfs(i);
		}
	}
}

vector<ll> oc[30];

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
		fore(i,0,30)oc[i].clear();
		fore(i,1,n+1){
			oc[31-__builtin_clz(i)].pb(i);
		}
		ll cant[2]={0,0};
		fore(i,0,n)cant[c[i]]++;
		if(cant[0]>cant[1]){
			fore(i,0,n)c[i]^=1;
			swap(cant[0],cant[1]);
		}
		vector<ll> v[2];
		fore(i,0,n)v[c[i]].pb(i);
		vector<ll> res(n);
		fore(i,0,30){
			if((1ll<<i)&cant[0]){
				while(SZ(oc[i])){
					auto bo=oc[i].back();
					oc[i].pop_back();
					assert(SZ(v[0]));
					auto bv=v[0].back();
					v[0].pop_back();
					res[bv]=bo;
				}
			}else{
				while(SZ(oc[i])){
					auto bo=oc[i].back();
					oc[i].pop_back();
					assert(SZ(v[1]));
					auto bv=v[1].back();
					v[1].pop_back();
					res[bv]=bo;
				}
			}
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}
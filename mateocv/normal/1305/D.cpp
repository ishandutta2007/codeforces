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

set<ll> g[1010];

ll ask(ll u, ll v){
	cout<<"? "<<u+1<<" "<<v+1<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp;
}

ll vis[1010];

int main(){FIN;
	ll n; cin>>n;
	ll u,vv;
	fore(i,0,n-1){
		cin>>u>>vv; u--; vv--;
		g[u].insert(vv);
		g[vv].insert(u);
	}
	vector<ll> v;
	while(1){
		fore(i,0,n){
			if(!vis[i]&&SZ(g[i])==1){
				vis[i]=1; v.pb(i);
			}
		}
		if(SZ(v)==0){
			fore(i,0,n){
				if(!vis[i]){
					cout<<"! "<<i+1<<endl; return 0;
				}
			}
		}
		assert(SZ(v)!=1);
		ll a=v.back(); v.pop_back();
		ll b=v.back(); v.pop_back();
		ll c=ask(a,b); c--;
		if(c==a){
			cout<<"! "<<a+1<<endl; return 0;
		}
		if(c==b){
			cout<<"! "<<b+1<<endl; return 0;
		}
		ll ta=*g[a].begin();
		g[a].erase(ta);
		g[ta].erase(a);
		ll tb=*g[b].begin();
		g[b].erase(tb);
		g[tb].erase(b);
	}
	
	
	return 0;
}
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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> p(n);
		fore(i,0,n)cin>>p[i];
		fore(i,0,n)p[i]--;
		vector<ll> c(n,0);
		fore(i,0,n){
			if(p[i]!=i){
				c[p[i]]++;
			}
		}
		vector<vector<ll>> res;
		vector<ll> vis(n);
		fore(i,0,n){
			if(vis[i]||c[i])continue;
			ll va=i;
			res.pb({});
			while(!vis[va]){
				res.back().pb(va);
				vis[va]=1;
				va=p[va];
			}
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res){
			cout<<SZ(i)<<"\n";
			reverse(ALL(i));
			for(auto j:i)cout<<j+1<<" ";
			cout<<"\n";
		}
		cout<<"\n";
	}
	
	return 0;
}
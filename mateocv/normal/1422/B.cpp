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

ll solve(vector<ll> v){
	ll res=9e18,va=0;
	fore(i,0,SZ(v)){
		va=0;
		for(auto j:v)va+=abs(j-v[i]);
		res=min(res,va);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n][m];
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
			}
		}
		bool vis[n][m];
		mset(vis,0);
		ll res=0;
		fore(i,0,n){
			fore(j,0,m){
				if(!vis[i][j]){
					vector<ll> v;
					v.pb(a[i][j]);
					vis[i][j]=1;
					if(n-1-i!=i){
						v.pb(a[n-1-i][j]);
						vis[n-1-i][j]=1;
					}
					if(m-1-j!=j){
						v.pb(a[i][m-1-j]);
						vis[i][m-1-j]=1;
					}
					if(n-1-i!=i&&m-1-j!=j){
						v.pb(a[n-1-i][m-1-j]);
						vis[n-1-i][m-1-j]=1;
					}
					res+=solve(v);
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
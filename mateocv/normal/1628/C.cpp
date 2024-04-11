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

bool val(ll x, ll y, ll n){
	return 0<=x&&x<n&&0<=y&&y<n;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vector<ll>> a(n);
		fore(i,0,n){
			a[i].resize(n);
			fore(j,0,n)cin>>a[i][j];
		}
		vector<pair<ll,ll>> v;
		auto vis=a;
		fore(i,0,n){
			fore(j,0,n){
				vis[i][j]=0;
			}
		}
		vector<pair<ll,ll>> dir={{1,0},{0,1},{-1,0},{0,-1}};
		fore(i,0,n){
			fore(j,0,n){
				if((i+j)&1)continue;
				vector<pair<ll,ll>> vec;
				for(auto ii:dir){
					ll x=i+ii.fst,y=j+ii.snd;
					if(val(x,y,n)){
						vec.pb({x,y});
					}
				}
				ll br=0;
				for(auto ii:vec){
					br+=vis[ii.fst][ii.snd];
				}
				if(!br){
					v.pb({i,j});
					for(auto ii:vec){
						vis[ii.fst][ii.snd]=1;
					}
				}
			}
		}
		ll res=0;
		for(auto ii:v){
			res^=a[ii.fst][ii.snd];
			res^=a[ii.fst][n-1-ii.snd];
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
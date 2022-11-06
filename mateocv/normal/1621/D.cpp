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
		vector<vector<ll>> v(2*n);
		fore(i,0,2*n){
			v[i].resize(2*n);
			fore(j,0,2*n)cin>>v[i][j];
		}
		ll res=0;
		fore(i,n,2*n){
			fore(j,n,2*n){
				res+=v[i][j];
			}
		}
		ll mini=1e18;
		mini=min(mini,v[n][0]);
		mini=min(mini,v[2*n-1][0]);
		mini=min(mini,v[n][n-1]);
		mini=min(mini,v[2*n-1][n-1]);
		mini=min(mini,v[0][n]);
		mini=min(mini,v[0][2*n-1]);
		mini=min(mini,v[n-1][n]);
		mini=min(mini,v[n-1][2*n-1]);
		res+=mini;
		cout<<res<<"\n";
	}
	
	return 0;
}
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
		vector<vector<ll>> a(n);
		fore(i,0,n){
			ll k; cin>>k;
			a[i].resize(k);
			fore(j,0,k)cin>>a[i][j];
		}
		vector<pair<ll,ll>> b;
		fore(i,0,n){
			ll maxi=0;
			fore(j,0,SZ(a[i])){
				maxi=max(maxi,a[i][j]+1-j);
			}
			b.pb({maxi,SZ(a[i])});
		}
		sort(ALL(b));
		ll res=0,va=0;
		fore(i,0,n){
			res=max(res,b[i].fst-va);
			va+=b[i].snd;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
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

bool diag(vector<ll> v){
	return v[1]==v[2];
}

vector<vector<ll>> v;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		v.clear();
		fore(i,0,n){
			ll a,b,c,d; cin>>a>>b>>c>>d;
			v.pb({a,b,c,d});
		}
		ll br=0;
		for(auto i:v){
			if(diag(i)){
				br++; break;
			}
		}
		if(br&&!(m&1)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}
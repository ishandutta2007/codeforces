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
		string s; cin>>s;
		vector<ll> v[3];
		fore(i,0,n){
			if(s[i]=='T'){
				if(SZ(v[0])<n/3)v[0].pb(i);
				else v[2].pb(i);
			}else{
				v[1].pb(i);
			}
		}
		if(min({SZ(v[0]),SZ(v[1]),SZ(v[2])})<n/3){
			cout<<"NO\n";
		}else{
			ll br=0;
			fore(i,0,n/3){
				if(v[0][i]>=v[1][i]||v[1][i]>=v[2][i])br++;
			}
			if(br)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	
	return 0;
}
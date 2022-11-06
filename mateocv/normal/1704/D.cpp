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
		ll n,m; cin>>n>>m;
		//vector<vector<ll>> a(n);
		vector<pair<ll,ll>> s;
		fore(i,0,n){
			vector<ll> a(m);
			fore(j,0,m)cin>>a[j];
			ll va=0;
			fore(j,0,SZ(a))va+=a[j]*(j+1);
			s.pb({va,i});
		}
		//for(auto i:s)cout<<i.fst<<" "<<i.snd<<"\n";
		sort(ALL(s));
		cout<<s.back().snd+1<<" "<<s.back().fst-s[0].fst<<"\n";
	}
	
	return 0;
}
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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> v={0};
		fore(i,0,n){
			fore(j,0,SZ(v)){
				v.pb(v[j]+a[i]);
				v.pb(v[j]-a[i]);
			}
		}
		ll tot=0;
		for(auto i:v)tot+=(i==0);
		if(tot>1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
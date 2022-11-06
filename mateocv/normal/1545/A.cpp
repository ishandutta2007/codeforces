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
		vector<ll> b[2];
		fore(i,0,n){
			b[i&1].pb(a[i]);
		}
		fore(k,0,2)sort(ALL(b[k]));
		vector<ll> bb;
		fore(i,0,SZ(b[1]))bb.pb(b[0][i]),bb.pb(b[1][i]);
		if(SZ(b[0])>SZ(b[1])){
			bb.pb(b[0].back());
		}
		sort(ALL(a));
		if(a==bb)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
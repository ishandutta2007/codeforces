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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll c[105];
		mset(c,0);
		fore(i,0,n)c[a[i]]++;
		vector<ll> res;
		fore(i,0,n){
			if(c[i]){
				res.pb(i);
				c[i]--;
			}else break;
		}
		fore(i,0,101){
			while(c[i]){
				res.pb(i);
				c[i]--;
			}
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}
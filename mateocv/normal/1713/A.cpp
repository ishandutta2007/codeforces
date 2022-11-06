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
		vector<ll> a={0},b={0};
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			if(x==0)a.pb(y);
			else b.pb(x);
		}
		sort(ALL(a));
		sort(ALL(b));
		ll res=0;
		res+=2ll*abs(a[0]-a.back());
		res+=2ll*abs(b[0]-b.back());
		cout<<res<<"\n";
	}
	
	return 0;
}
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
		sort(ALL(a));
		ll res=1e18;
		fore(k,0,2){
			ll c[2]={0,0};
			fore(i,0,n){
				ll d=a.back()-a[i]+k;
				c[0]+=(d&1);
				c[1]+=d/2;
			}
			vector<ll> v={0,c[1]};
			fore(i,-5,6){
				ll val=(c[1]-c[0])/3+i;
				if(val>=0&&val<=c[1])v.pb(val);
			}
			for(auto x:v){
				res=min(res,max(2ll*(c[0]+2ll*x)-1,2ll*(c[1]-x)));
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
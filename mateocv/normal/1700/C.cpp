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
		vector<ll> d={a[0]};
		fore(i,0,n-1)d.pb(a[i+1]-a[i]);
		a=d;
		//for(auto i:a)cout<<i<<" ";
		//cout<<"\n";
		ll res=0,va=0;
		if(a[0]>=0){
			res+=a[0];
			va+=a[0];
		}else{
			res+=-a[0];
		}
		fore(i,1,n){
			if(a[i]>=0){
				res+=a[i];
			}else{
				ll mini=min(-a[i],va);
				va-=mini;
				a[i]+=mini;
				res+=-2ll*a[i];
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
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
		vector<pair<ll,ll>> vg,vc;
		vector<ll> ng(n),nc(n);
		vg={{1e18,n}};
		for(ll i=n-1;i>=0;i--){
			while(a[i]>vg.back().fst)vg.pop_back();
			ng[i]=vg.back().snd;
			vg.pb({a[i],i});
		}
		vc={{-1,n}};
		for(ll i=n-1;i>=0;i--){
			while(a[i]<vc.back().fst)vc.pop_back();
			nc[i]=vc.back().snd;
			vc.pb({a[i],i});
		}
		ll res=0,pos=0;
		while(pos<n-1){
			res++;
			if(a[pos]<a[pos+1]){
				ll maxi=nc[pos];
				while(ng[pos]<maxi)pos=ng[pos];
			}else{
				ll maxi=ng[pos];
				while(nc[pos]<maxi)pos=nc[pos];
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
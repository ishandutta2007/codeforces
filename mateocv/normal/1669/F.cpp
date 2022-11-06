#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
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
		vector<ll> sump={0};
		for(auto i:a)sump.pb(sump.back()+i);
		map<ll,ll> mp;
		fore(i,0,SZ(sump))mp[sump[i]]=i;
		ll res=0;
		fore(i,0,SZ(sump)){
			if(2ll*sump[i]<=sump[n]){
				ll val=sump[n]-sump[i];
				if(mp.count(val)){
					res=max(res,i+n-mp[val]);
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
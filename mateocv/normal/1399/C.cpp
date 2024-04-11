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
		map<ll,ll> mp;
		fore(i,0,n)mp[a[i]]++;
		ll res=0;
		fore(i,1,2*n+1){
			ll va=0;
			for(auto j:mp){
				if(mp.count(i-j.fst))va+=min(j.snd,mp[i-j.fst]);
			}
			va/=2;
			res=max(res,va);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
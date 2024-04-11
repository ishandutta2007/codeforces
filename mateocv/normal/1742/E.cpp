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
		ll n,q; cin>>n>>q;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> maxp={0},sump={0};
		for(auto i:a){
			maxp.pb(max(i,maxp.back()));
			sump.pb(i+sump.back());
		}
		while(q--){
			ll k; cin>>k;
			ll l=0,r=n;
			while(l<=r){
				ll m=(l+r)/2;
				if(maxp[m]<=k)l=m+1;
				else r=m-1;
			}
			cout<<sump[r]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
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
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> maxp={0};
	ll s=0;
	fore(i,0,n){
		s+=a[i];
		ll val=(s+i)/(i+1);
		maxp.pb(max(val,maxp.back()));
	}
	ll q; cin>>q;
	while(q--){
		ll t; cin>>t;
		ll res=(s+t-1)/t;
		if(res>n||maxp[res]>t)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}
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

ll solve(vector<ll> a){
	if(SZ(a)&1){
		ll x=0,xa=0;
		fore(i,0,SZ(a))x^=i,xa^=a[i];
		return x^xa;
	}
	sort(ALL(a));
	vector<ll> b;
	fore(i,0,SZ(a)/2)b.pb(a[2*i]/2);
	return 2ll*solve(b);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll n=r-l+1;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		cout<<solve(a)<<"\n";
	}
	
	return 0;
}
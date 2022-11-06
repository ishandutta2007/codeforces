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
	ll maxi=1000000000;
	set<ll> st;
	fore(i,1,100005){
		if(i*i<=maxi)st.insert(i*i);
		if(i*i*i<=maxi)st.insert(i*i*i);
	}
	vector<ll> v;
	for(auto i:st)v.pb(i);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<lower_bound(ALL(v),n+1)-v.begin()<<"\n";
	}
	
	return 0;
}
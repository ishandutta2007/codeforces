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
		set<ll> st;
		st.insert(0);
		for(ll i=1;i*i<=n;i++){
			st.insert(n/i);
			st.insert(i);
		}
		cout<<SZ(st)<<"\n";
		for(auto i:st)cout<<i<<" "; cout<<"\n";
	}
	
	return 0;
}
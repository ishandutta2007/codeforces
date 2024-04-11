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
		fore(i,0,n)st.insert(i+1);
		priority_queue<ll> pq;
		fore(i,0,n){
			ll x; cin>>x;
			pq.push(x);
		}
		while(SZ(pq)){
			auto f=pq.top(); pq.pop();
			if(st.count(f))st.erase(f);
			else if(f)pq.push(f/2);
		}
		if(SZ(st))cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}
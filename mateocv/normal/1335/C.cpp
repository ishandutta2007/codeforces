#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
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
		set<ll> st;
		map<ll,ll> mp;
		fore(i,0,n){
			st.insert(a[i]);
			mp[a[i]]++;
		}
		ll maxi=0;
		for(auto i:mp)maxi=max(maxi,i.snd);
		if(maxi==SZ(st)){
			cout<<maxi-1<<"\n";
		}else{
			cout<<min(maxi,SZ(st))<<"\n";
		}
	}
	
	return 0;
}
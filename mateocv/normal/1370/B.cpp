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
		ll a[2*n];
		fore(i,0,2*n)cin>>a[i];
		vector<ll> v[2];
		fore(i,0,2*n)v[a[i]%2].pb(i);
		vector<pair<ll,ll>> res;
		fore(k,0,2)fore(i,0,SZ(v[k])/2)res.pb({v[k][2*i],v[k][2*i+1]});
		if(SZ(res)==n)res.pop_back();
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	
	return 0;
}
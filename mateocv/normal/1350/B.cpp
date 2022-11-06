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

vector<ll> d(ll n){
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			if(n/i!=i)res.pb(n/i);
		}
	}
	return res;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll res[n];
		mset(res,0);
		fore(i,0,n){
			auto v=d(i+1);
			for(auto j:v){
				if(a[j-1]<a[i])res[i]=max(res[i],res[j-1]);
			}
			res[i]++;
		}
		cout<<*max_element(res,res+n)<<"\n";
	}
	
	return 0;
}
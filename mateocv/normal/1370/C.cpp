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
 
vector<ll> div(ll n){
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			if(i!=n/i)res.pb(n/i);
		}
	}
	return res;
}
 
 
ll solve(ll n){
	if(n==1)return 1;
	if(n&1)return 0;
	if(n==2)return 0;
	auto d=div(n);
	if(n%4==0){
		for(auto i:d){
			if((i&1)&&(i>1))return 0;
		}
		return 1;
	}
	return SZ(d)<=4;
	
}
 
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(solve(n))cout<<"FastestFinger\n";
		else cout<<"Ashishgup\n";
	}
	
	return 0;
}
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

vector<pair<ll,ll>> fact(ll x){
	vector<pair<ll,ll>> res;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){ll cuenta=0;
			while(x%i==0){
				cuenta++; x/=i;	
			}
			pair<ll,ll> pr;
			pr.fst=i; pr.snd=cuenta;
			res.pb(pr);
		}
	}
	if(x>1){
	pair<ll,ll> pr;
	pr.fst=x; pr.snd=1;
	res.pb(pr);}
	return res;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		auto f=fact(n);
		pair<ll,ll> maxi={0,0};
		for(auto i:f)maxi=max(maxi,{i.snd,i.fst});
		cout<<maxi.fst<<"\n";
		ll va=1;
		fore(i,0,maxi.fst-1){
			cout<<maxi.snd<<" ";
			va*=maxi.snd;
		}
		cout<<n/va<<"\n";
	}
	
	return 0;
}
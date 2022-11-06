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
 
vector<ll> fact(ll n){
	vector<ll> res;
	for(ll i=2;i*i<=n;i++){
		ll par=1;
		while(n%i==0){
			par*=i;
			n/=i;
		}
		if(par>1)res.pb(par);
	}
	if(n!=1){
		res.pb(n);
	}
	return res;
}
 
int main(){FIN;
	ll x; cin>>x;
	vector<ll> f=fact(x);
	ll res=x;
	//cout<<SZ(f)<<" ";
	//for(auto i:f)cout<<i<<" ";
	fore(i,0,1<<SZ(f)){
		ll va=1;
		fore(j,0,SZ(f)){
			if((1<<j)&i)va*=f[j];
		}
		if(va>=x/va)res=min(res,va);
	}
	cout<<res<<" "<<x/res;
	return 0;
}
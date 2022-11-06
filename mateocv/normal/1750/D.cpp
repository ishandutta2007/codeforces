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

const ll MOD=998244353;

vector<ll> fact(ll n){
	vector<ll> res;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)res.pb(n);
	return res;
}

ll calc(ll c, vector<ll> p){
	ll res=0;
	fore(i,0,(1ll<<SZ(p))){
		auto sg=(__builtin_popcount(i)&1)?-1:1;
		ll pr=1;
		fore(j,0,SZ(p)){
			if((1ll<<j)&i)pr*=p[j];
		}
		res+=sg*c/pr;
	}
	return res%MOD;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll res=1;
		fore(i,1,n){
			if(a[i-1]%a[i]!=0){
				res=0; break;
			}
			ll c=m/a[i];
			res=res*calc(c,fact(a[i-1]/a[i]))%MOD;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
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

const ll MOD=1000000007;
 
ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

ll vp(ll x,ll p){
	ll sum=0;
	while(x>0){
		x/=p;
		sum+=x;
	}
	return sum;
}

ll esp(ll p){
	if(p==1)return 0;
	for(ll i=2;i*i<=p;i++){
		if(p%i==0)return 0;
	}
	return 1;
}

vector<ll> prim(ll n){
	vector<ll> res;
	if(esp(n)){
		return {n};
	}
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			if(esp(i))res.pb(i);
			if(esp(n/i)&&i!=n/i)res.pb(n/i);
		}
	}
	return res;
}

int main(){FIN;
	ll x,n; cin>>x>>n;
	vector<ll> v=prim(x);
	//for(auto i:v)cout<<i<<" "; cout<<"\n";
	ll res=1;
	fore(i,0,SZ(v)){
		res*=be(v[i],vp(n,v[i]),MOD);
		res%=MOD;
		//cout<<res<<"\n";
	}
	cout<<res;
	return 0;
}
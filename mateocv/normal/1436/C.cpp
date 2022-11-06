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

ll MOD=1000000007;

ll fact[1010];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*fpow(fact[k]*fact[n-k]%MOD,MOD-2)%MOD;
}

pair<ll,ll> cont(ll n, ll p){
	pair<ll,ll> res={0,0};
	ll l=0,r=n;
	while(l<r){
		ll m=(l+r)/2;
		if(m<=p){
			l=m+1;
			res.fst+=(m<p);
		}else{
			r=m;
			res.snd++;
		}
	}
	return res;
}

int main(){FIN;
	ll n,x,p; cin>>n>>x>>p; x--;
	fact[0]=1;
	fore(i,1,1010)fact[i]=fact[i-1]*i%MOD;
	auto c=cont(n,p);
	ll res=1;
	res=res*comb(x,c.fst)%MOD;
	res=res*fact[c.fst]%MOD;
	res=res*comb(n-1-x,c.snd)%MOD;
	res=res*fact[c.snd]%MOD;
	res=res*fact[n-1-c.fst-c.snd]%MOD;
	cout<<res<<"\n";
	return 0;
}
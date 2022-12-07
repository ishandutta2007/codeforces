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

ll MOD;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

const int MAXN=5050;

ll fact[MAXN],facti[MAXN];

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*(facti[n-k]*facti[k]%MOD)%MOD;
}

int main(){FIN;
	ll n; cin>>n>>MOD;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	facti[MAXN-1]=fpow(fact[MAXN-1],MOD-2);
	for(ll i=MAXN-2;i>=0;i--)facti[i]=(facti[i+1]*(i+1))%MOD;
	ll res=0;
	fore(i,n/2+1,n){
		ll c=n-i-1;
		fore(j,0,c+1){
			ll te=comb(c,j);
			if(i-1+j-1>=0)te=te*fact[i-1+j-1]%MOD;
			ll r=n/2;
			ll l=max(1ll,i-(n/2));
			//cout<<l<<" "<<r<<"\n";
			te=te*(r-l+1)%MOD;
			res=(res+te)%MOD;
			//cout<<i<<" "<<j<<" "<<res<<"\n";
		}
	}
	
	if(n&1){
		res=(res+fact[n-2]*0ll)%MOD;
	}else{
		res=(res+fact[n-2])%MOD;
	}
	
	res=res*n%MOD;
	cout<<res<<"\n";
	return 0;
}
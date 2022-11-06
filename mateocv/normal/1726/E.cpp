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

const int MAXN=300005,MOD=998244353;

ll fact[MAXN],facti[MAXN];

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
	return fact[n]*(facti[n-k]*facti[k]%MOD)%MOD;
}

ll cm[MAXN],cm2[MAXN];

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	facti[MAXN-1]=fpow(fact[MAXN-1],MOD-2);
	for(ll i=MAXN-2;i>=0;i--)facti[i]=(facti[i+1]*(i+1))%MOD;
	cm[0]=1,cm[1]=1;
	fore(i,2,MAXN){
		cm[i]=(cm[i-1]+(i-1)*cm[i-2])%MOD;
	}
	cm2[0]=1,cm2[1]=0;
	fore(i,2,MAXN){
		cm2[i]=(2ll*(i-1)*cm2[i-2])%MOD;
	}
	//fore(i,0,5)cout<<cm[i]<<" ";
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll res=0;
		fore(i,0,n/2+1){
			ll te=comb(n-i,i);
			te=te*cm2[i]%MOD;
			te=te*cm[n-2*i]%MOD;
			res=(res+te)%MOD;
			//cout<<res<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
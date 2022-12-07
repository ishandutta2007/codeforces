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

const int MAXN=2000006;
const ll MOD=1000000007;

ll fact[MAXN],facti[MAXN];

ll fpow(ll b, ll e){
	if(e<0)return 1;
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll comb(ll n, ll k){
	if(k>n||n<0)return 0;
	return fact[n]*(facti[n-k]*facti[k]%MOD)%MOD;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	facti[MAXN-1]=fpow(fact[MAXN-1],MOD-2);
	for(ll i=MAXN-2;i>=0;i--)facti[i]=(facti[i+1]*(i+1))%MOD;
	ll n,k; cin>>n>>k;
	if(k==0){
		cout<<fpow(3,n)<<"\n";
		return 0;
	}
	ll res=0;
	fore(i,1,k+1){
		//cout<<i<<":\n";
		ll c=k-i;
		ll te=comb(c+i-1,i-1);
		te=te*fpow(3,c)%MOD;
		//n+1
		res=(res+te*(comb((n+1-k-i)+i-1,i-1)*fpow(3,(n+1-k-i))%MOD))%MOD;
		//cout<<res<<"\n";
		//n
		res=(res+te*(comb((n-k-i)+i,i)*fpow(3,(n-k-i))%MOD))%MOD;
		//cout<<res<<"\n";
	}
	cout<<res<<"\n";
	
	return 0;
}
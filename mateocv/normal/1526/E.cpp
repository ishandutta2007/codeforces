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

ll fact[200005];

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

int main(){FIN;
	fact[0]=1;
	fore(i,1,200005)fact[i]=fact[i-1]*i%MOD;
	ll n,k; cin>>n>>k;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> u(n+1);
	fore(i,0,n)u[a[i]]=i;
	u[n]=-1;
	ll kk=1;
	fore(i,1,n){
		if(u[a[i]+1]<=u[a[i-1]+1])kk++;
	}
	ll res=0;
	fore(i,kk,k+1){
		res=(res+comb(k,i)*comb(n-kk,i-kk))%MOD;
	}
	cout<<res<<"\n";
	
	return 0;
}
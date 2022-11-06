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

const int MAXN=500005;

const ll MOD=1000000007;

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
	return fact[n]*(facti[k]*facti[n-k]%MOD)%MOD;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	fore(i,0,MAXN)facti[i]=fpow(fact[i],MOD-2);
	ll n; cin>>n;
	vector<ll> a(n+1);
	fore(i,0,n+1)cin>>a[i];
	ll res=0;
	fore(i,0,n+1){
		res=(res+comb(a[i]+i,i+1))%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
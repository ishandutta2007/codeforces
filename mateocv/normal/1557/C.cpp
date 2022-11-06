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

const int MAXN=200005;

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
	//assert(n<MAXN);
	if(k>n)return 0;
	return fact[n]*(facti[k]*facti[n-k]%MOD)%MOD;
}

ll dp[MAXN][3];

ll ci,cp;

ll f(ll x, ll y){
	assert(min(x,y)>=0);
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==0)return res=1;
	if(y==2){
		res=(cp+1)*f(x-1,2)%MOD;
	}else{
		if(y)res=(f(x-1,0)+cp*f(x-1,1))%MOD;
		else res=f(x-1,0)*(cp+ci+1)%MOD;
	}
	//cout<<"HOLAAAA"<<endl;
	return res;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	fore(i,0,MAXN)facti[i]=fpow(fact[i],MOD-2);
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		mset(dp,-1);
		ci=0;
		cp=0;
		fore(i,0,n){
			if(i&1)ci=(ci+comb(n,i))%MOD;
			else cp=(cp+comb(n,i))%MOD;
		}
		if(n&1)cout<<f(k,2)<<"\n";
		else cout<<f(k,1)<<"\n";
	}
	
	return 0;
}
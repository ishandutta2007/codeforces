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

const int MAXN=100005;

ll fact[MAXN];

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
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vector<ll> v;
		fore(i,0,SZ(s)){
			if(s[i]=='1'&&(i==0||s[i-1]=='0'))v.pb(1);
			else if(s[i]=='1')v[SZ(v)-1]++;
		}
		ll nn=n;
		ll k=0;
		for(auto i:v){
			k+=i/2;
			nn-=(i+1)/2;
		}
		cout<<comb(nn,k)<<"\n";
	}
	
	return 0;
}
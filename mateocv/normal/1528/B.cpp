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

const int MAXN=1000006;

/*----------------------CRIBA_LOGLOG-------------------------*/
bool isprime[MAXN];
vector<ll> prime;
int SPF[MAXN];
 
//Inicializar en true isprime
void sieve(int n){
    isprime[0] = isprime[1] = false;
    fore(i,2,n+1){
        if(isprime[i]) prime.push_back(i), SPF[i] = i;
        for(int j=0; j<SZ(prime)&&i*prime[j]<=n&&prime[j]<=SPF[i]; j++){
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

ll div(ll n){
	ll res=1;
	vector<pair<ll,ll>> v;
	while(n>1){
		ll s=SPF[n];
		if(SZ(v)==0||v.back().fst!=s)v.pb({s,1});
		else v[SZ(v)-1].snd++;
		n/=s;
	}
	for(auto i:v)res=res*(i.snd+1);
	return res;
}

const int MOD=998244353;

ll dp[MAXN],s[MAXN];

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	ll n; cin>>n;
	dp[0]=0;
	s[0]=0;
	fore(i,1,n+1){
		dp[i]=(div(i)+s[i-1])%MOD;
		s[i]=(dp[i]+s[i-1])%MOD;
	}
	cout<<dp[n]<<"\n";
	
	return 0;
}
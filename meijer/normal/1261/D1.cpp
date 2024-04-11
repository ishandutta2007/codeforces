#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=3e5, MOD=998244353;
ll n, k, h[MX], m=0;
ll dp[MX];

ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
ll fact[MX];
ll bico(ll N, ll k) {
    return (fact[N]*inv((fact[k]*fact[N-k])%MOD))%MOD;
}
void fillFact() {
    fact[0] = 1;
    REP(i,1,MX) fact[i] = (fact[i-1]*i)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    RE(i,n) cin>>h[i];
    RE(i,n) if(h[i] != h[(i+1)%n]) m++;
    if(m == 0 || k == 1) {
    	cout<<0<<endl;
    	return 0;
    }
    fillFact();
    ll ans=0;
    REI(i,1,m) {
    	REI(j,0,min(i-1,m-i)) {
    		ans += (((fact[m]*modpow(k-2,m-i-j))%MOD) *
					inv((((fact[i]*fact[j])%MOD)*fact[m-i-j])%MOD))%MOD;
    		ans %= MOD;
    	}
    }
    ans = (ans*modpow(k,n-m))%MOD;
    cout<<ans<<endl;
}
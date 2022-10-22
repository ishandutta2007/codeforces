#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=2e6, MOD=998244353;
string s;
int a=0, b=0, c=0, d=0;

ll mod(ll x_) {
	return (x_+MOD)%MOD;
}
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
	if(k < 0 || k > N) return 0;
    return (fact[N]*inv((fact[k]*fact[N-k])%MOD))%MOD;
}
void fillFact() {
    fact[0] = 1;
    REP(i,1,MX) fact[i] = (fact[i-1]*i)%MOD;
}
map<int, vll> dpm;

ll getdpm() {
	int x = b+d-a;
	if(x < 0) return 0;
	if(c+d < x) x = c+d;
	if(!dpm.count(c+d)) {
		vll& dp = dpm[c+d];
		dp.resize(c+d+1);
		dp[0] = 1;
		REP(i,1,c+d+1) {
			dp[i] = dp[i-1];
			dp[i] = mod(dp[i] + bico(c+d, i));
		}
	}
	return dpm[c+d][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    fillFact();
    for(char ch:s) if(ch == '?') d++;
    for(char ch:s) if(ch == ')') b++;
    ll ans = 0;
    for(char ch:s) {
    	if(ch == ')') b--;
    	if(ch == '(') a++;
    	if(ch == '?') {
    		d--; a++;
    		ans = mod(ans + getdpm());
    		c++; a--;
    	} else if(ch == '(') {
    		ans = mod(ans + getdpm());
    	}
    }
    cout<<ans<<endl;
}
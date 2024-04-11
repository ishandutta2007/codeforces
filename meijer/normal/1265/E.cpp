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

const int MX=4e5, MOD=998244353;
ll n, q, p[MX], add[MX], dp[MX], u;

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
ll mod(ll x_) {
	return (x_ + MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>p[i];
    ll curAns=0;
    ll inv100 = inv(100);
    RE(i,n) add[i] = 1*inv(mod(p[i]*inv100));
    REV(i,0,n+1) dp[i] = mod((i==0 ? 0 : add[i-1]) * (i==n ? 1 : dp[i+1]));
    RE(i,n+1) curAns = mod(curAns+dp[i]);
    cout<<curAns<<endl;
}
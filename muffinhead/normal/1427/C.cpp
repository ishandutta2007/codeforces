#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int R, N; cin >> R >> N;
    int T[N+1], X[N+1], Y[N+1]; FOR(i, 1, N+1) cin >> T[i] >> X[i] >> Y[i];
    T[0] = 0; X[0] = 1; Y[0] = 1;
    int dp[N+1]; F0R(i, N+1) dp[i] = -1000000000;
    int M[N+1]; F0R(i, N+1) M[i] = 0;
    dp[0] = 0;
    FOR(i, 1, N+1) {
        FOR(j, max(0, i - 1100), i) {
            if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= T[i] - T[j]) {
                ckmax(dp[i], dp[j] + 1);
            }
        }
        if (i >= 1100) ckmax(dp[i], M[i-1100] + 1);
        M[i] = max(dp[i], M[i-1]);
    }
    int ans = 0; F0R(i, N+1) ckmax(ans, dp[i]);
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
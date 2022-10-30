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
	
    int N, D, M; cin >> N >> D >> M;
    vi A, B;
    F0R(i, N) {
        int X; cin >> X;
        if (X > M) {
            A.pb(X);
        } else {
            B.pb(X);
        }
    }
    sort(all(A)); reverse(all(A)); sort(all(B)); reverse(all(B));

    int cur = (N+D)/(D+1);
    ll ans = 0;
    F0R(i, cur) if (i < sz(A)) ans += A[i];
    cur = N;
    ll val = 0;
    int p1 = 0, p2 = 0;
    while (p1 < sz(A) && cur >= D+1) {
        if (p1 > 0) {
            cur-=D+1;
        } else cur--;
        val += A[p1];
        p1++;
    }
    while (p2 < sz(B) && cur > 0) {
        cur--;
        val += B[p2];
        p2++;
    }

    ckmax(ans, val);
    while (p1 > 0) {
        cur += D+1;
        if (p1 == 0) cur -= D;
        p1--;
        val -= A[p1];
        while (p2 < sz(B) && cur > 0) {
            cur--;
            val += B[p2];
            p2++;
        }
        ckmax(ans, val);
    }

    cout << ans << nl;


	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
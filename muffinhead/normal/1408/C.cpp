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
	
    int T; cin >> T;
    while(T--) {
        int N, L; cin >> N >> L;
        ll A[N+2]; F0R(i, N) cin >> A[i+1];
        A[0] = 0; A[N+1] = L;
        ld X[N+2]; X[0] = 0;
        FOR(i, 1, N+2) {
            X[i] = X[i-1] + (A[i] - A[i-1]) / ((ld) i);
        }
        ld Y[N+2]; Y[N+1] = 0;
        F0Rd(i, N+1) {
            Y[i] = Y[i+1] + (A[i+1] - A[i]) / ((ld) (N+1-i));
        }
        int en = 0;
        F0R(i, N+2) {
            if (Y[i] <= X[i]) {
                en = i-1; break;
            }
        }
        ld tim = max(X[en], Y[en+1]);
        ld dist = A[en+1] - A[en];
        if (X[en] < Y[en+1]) {
            dist -= (Y[en+1] - X[en]) * (en+1);
        } else {
            dist -= (X[en] - Y[en+1]) * (N+1-en);
        }
        cout << setprecision(20) << tim + dist / (N+2) << nl;
        
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
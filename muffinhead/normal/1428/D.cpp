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
	
    int N; cin >> N;
    int A[N]; F0R(i, N) cin >> A[i];
    vpi ans;
    queue<pi> piv1; 
    queue<pi> piv2;
    F0Rd(i, N) {
        if (A[i] == 3) {
            if (sz(piv1) == 0 && sz(piv2) == 0) {
                cout << -1 << nl; return 0;
            }
            ans.pb({i, i});
            pi c;
            if (sz(piv2) == 0) {
                c = piv1.front(); piv1.pop();
            } else {
                c = piv2.front(); piv2.pop();
            }
            ans.pb({i, c.s});
            piv2.push({i, i});
        } else if (A[i] == 2) {
            if (sz(piv1) == 0) {
                cout << -1 << nl; return 0;
            }
            pi r = piv1.front(); piv1.pop();
            ans.pb({r.f, i});
            piv2.push({r.f, i});
        } else if (A[i] == 1) {
            ans.pb({i, i});
            piv1.push({i, i});
        }
    }

    cout << sz(ans) << nl;
    trav(a, ans) {
        cout << a.f+1 << " " << a.s+1 << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
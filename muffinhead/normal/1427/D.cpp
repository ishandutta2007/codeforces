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

int N;
vi A(MX);

void apply(vi op) {
    int p = 0;
    vector<vi> vals;
    trav(a, op) {
        vi cur;
        F0R(i, a) {
            cur.pb(A[p]); p++;
        }
        vals.pb(cur);
    }
    A.clear();
    F0Rd(i, sz(vals)) {
        trav(a, vals[i]) A.pb(a);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;

    F0R(i, N) cin >> A[i];
    vector<vi> ops;
    while (true) {
        bool bad = false;
        F0R(i, N-1) {
            if (A[i+1] < A[i]) bad = true;
        }
        if (!bad) break;
        int fir = 0;
        F0R(i, N) {
            if (A[i] != i+1) {
                fir = i; break;
            }
        }
        int lst = 0;
        F0Rd(i, N) {
            if (A[i] != i+1) {
                lst = N - i - 1; break;
            }
        }
        int pos = 0;
        F0R(i, N) {
            if (A[i] == A[fir] - 1) {
                pos = i;
            }
        }
        vi op;
        if (fir > 0) {
            op.pb(fir);
        }
        int blo = 1;
        while (pos-blo >= 0 && A[pos-blo] == A[pos] - blo) {
            blo++;
        }
        op.pb(pos-blo-fir+1);
        op.pb(blo);
        if (N-pos-1) op.pb(N-pos-1);
        apply(op);
        ops.pb(op);
    }
    cout << sz(ops) << nl;
    trav(a, ops) {
        cout << sz(a) << " ";
        trav(b, a) cout << b << " ";
        cout << nl;
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
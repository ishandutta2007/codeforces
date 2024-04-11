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
struct Seg { 
static const ll identity = 0;
static const ll SZ = 131072*4;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return max(A, B);
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = identity;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    vector<pair<pl, int> > A;
    set<int> used;
    F0R(i, N) {
        int L, R, T; cin >> L >> R >> T;
        A.pb({{R, L}, T});
        used.ins(L);
        used.ins(R);
    }
    map<int, int> com;
    trav(a, used) {
        com.ins({a, sz(com)+1});
    }
    F0R(i, N) {
        A[i].f.f = com[A[i].f.f];
        A[i].f.s = com[A[i].f.s];
    }
    Seg X, Y;
    F0R(i, 262144*4) {
        X.sum[i] = 0;
        Y.sum[i] = 0;
        X.lazy[i] = 0;
        Y.lazy[i] = 0;
    }

    sort(all(A));
    ll cur = 0;
    F0R(i, N) {
        if (A[i].s == 1) {
            X.update(0, A[i].f.s-1, 1);
        } else {
            Y.update(0, A[i].f.s-1, 1);
        }
        if (i == N-1 || A[i].f.f != A[i+1].f.f) {
            //query
            ckmax(cur, X.query(0, A[i].f.f-1));
            ckmax(cur, Y.query(0, A[i].f.f - 1));
            X.update(A[i].f.f, A[i].f.f, cur);
            Y.update(A[i].f.f, A[i].f.f, cur);
            if (i == N-1) {
                cout << cur << nl;
            }
            cur = 0;
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
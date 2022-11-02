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
struct Seg1 {

static const ll identity = 0;
static const ll SZ = 131072*4;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return min(A, B);
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

bool checkCondition(int index) {
    return sum[index] == 0;
}

ll query(int lo = 0, int hi = SZ-1, int index = 1, ll L = 0, ll R = SZ-1) { //returns first node satisfying con
    push(index, L, R);
    if (lo > R || L > hi) return -1;
    bool condition = checkCondition(index);
//    cout << L << " " << R << " " << condition << " " << sum[index] << nl;
    if (L == R) {
        return (condition ? L : -1);
    }
    int M = (L+R) / 2;
    push(2*index+1, M+1, R);
    if (checkCondition(2*index+1)) {
        return query(lo, hi, 2*index+1, M+1, R);
    }
    return query(lo, hi, 2*index, L, M); 
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

struct Seg2 {

static const ll SZ = 262144*2; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return a+b; }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, Q; cin >> N >> Q;
    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N) A[i] -= i+1;
    Seg1 seg1;
    Seg2 seg2;
    int SZ = 262144*2;
    F0R(i, 2*SZ) {
        seg1.sum[i] = 0;
        seg1.lazy[i] = 0;
        seg2.seg[i] = 0;
    }
    priority_queue<int> q;
    F0R(i, N) {
        if (A[i] < 0) {
            seg1.update(i, i, -A[i]);
        } else {
            seg1.update(i, i, SZ);
            if (A[i] == 0) q.push(i);
        }
    }
    FOR(i, N, SZ) {
        seg1.update(i, i, SZ);
    }

    vector<vi> rem(N);
    int lo = N+1;
    while (!q.empty()) {
        int x = q.top(); q.pop();
//        cout << "PROC " << x << nl;
        ckmin(lo, x);
        rem[lo].pb(x);
        seg2.update(x, 1);
        seg1.update(x+1, SZ-1, -1);
        while (seg1.query() != -1) {
            int val = seg1.query();
            q.push(val);
            seg1.update(val, val, SZ);
        }
    }

    vector<pair<pi, int> > qu(Q);
    F0R(i, Q) {
        int X, Y; cin >> X >> Y; qu[i] = {{X, Y}, i};
    }
    int p = 0;
    sort(all(qu));
    int ans[Q];
    F0R(i, Q) {
        while (p < qu[i].f.f) {
            trav(a, rem[p]) {
                seg2.update(a, 0);
            }
            p++;
        }
        ans[qu[i].s] = seg2.query(qu[i].f.f, N - 1 - qu[i].f.s);
    }
    F0R(i, Q) cout << ans[i] << nl;


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
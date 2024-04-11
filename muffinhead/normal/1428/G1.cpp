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
ll SZ = 262144; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return max(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ckmax(l, 0);
    ckmin(r, (int) SZ-1);
    if (l > r) {
        return -1e15;
    }
    ll resL = -1e15, resR = -1e15; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}

};
Seg seg[3];
vl trans(vl& cur, ll F, ll K) {
    F0R(i, 262144*2) {
        F0R(j, 3) {
            seg[j].seg[i] = -1e15;
        }
    }
    F0R(i, sz(cur)) {
        seg[i%3].update(i, cur[i] - F * ((i*10)/3));
    }
    vl res(10*sz(cur));
    F0R(i, sz(res)) {
        ll leastEff = (i - 9 * K + 18) / 10;
        res[i] = -10000000000000000;
        F0R(j, 3) {
            ckmax(res[i], seg[j].query(leastEff, i/10) + F * ((i-j)/3));
        }
//        cout << i << " " << res[i] << nl;
        F0R(j, 10) {
            if (i >= 9*K-9+j) {
                ll val = i - 9*K + 9 - j;
                if (val % 10) continue;
                val /= 10;
                val = cur[val];
                val += F * 3 * (K-1);
                if (j % 3 == 0) val += F * j/3;
                ckmax(res[i], val);
            }
        }
//        cout << res[i] << nl;
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll K; cin >> K;
    ll F[6]; F0R(i, 6) cin >> F[i];
    vl res = {0};
    FORd(i, 0, 6) {
        res = trans(res, F[i], K);
    }
/*    F0R(i, sz(res)) {
        cout << i << " " << res[i] << nl;
    }
    cout << nl;
    return 0;*/
    int Q; cin >> Q;
    while(Q--) {
        int X; cin >> X;
        cout << res[X] << nl;
    }

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
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
const int MX = 200001; //check the limits, dummy
 
template<int SZ> struct DSU {
    int parent[SZ], size[SZ], val[SZ];
    ll sum[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        ckmax(val[x], val[y]);
        sum[x] += sum[y];
        parent[y] = x;

    }
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    ll A[N], B[M]; F0R(i, N) cin >> A[i];
    F0R(i, M) cin >> B[i];
    vector<pair<int, pi> > vals;
    F0R(i, N) {
/*        int S; cin >> S;
        F0R(j, S) {
            int X; cin >> X; X--; in[i].pb({B[X], X});
        }
        sort(all(in[i])); reverse(all(in[i]));*/
        int S; cin >> S;
        F0R(j, S) {
            int X; cin >> X; X--; vals.pb({A[i]+B[X], {i, X}});
        }
    }
    DSU<MX> dsu;
    int rep[M]; F0R(i, M) rep[i] = -1;
    ll ans = 0;
    sort(all(vals)); reverse(all(vals));
    F0R(i, sz(vals)) {
        int s = vals[i].s.f;
        int x = vals[i].s.s;
        if (rep[x] == -1) {
            rep[x] = dsu.get(s);
        } else if (dsu.get(s) == dsu.get(rep[x])) {
            ans += A[s] + B[x];
        } else {
            dsu.unify(s, rep[x]);
        }
    }
    cout << ans << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
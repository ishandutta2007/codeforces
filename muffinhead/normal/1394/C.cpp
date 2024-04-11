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
const int MX = 500001; //check the limits, dummy
int N;
vpi A;

pi poss(int d) {
    int vals[6];
    F0R(i, 6) vals[i] = -MX * 4;
    priority_queue<pi> v[6];
    v[3].push({-MX*4, N+1});
    v[4].push({-MX*4, N+1});
    v[5].push({-MX*4, N+1});
    F0R(i, N) {
        ckmax(vals[3], A[i].f);
        v[3].push({A[i].f, i});
        ckmax(vals[4], A[i].s);
        v[4].push({A[i].s, i});
        ckmax(vals[5], A[i].f - A[i].s);
        v[5].push({A[i].f - A[i].s, i});
    }
    int p = 0;

    F0R(i, MX) {
        if (d == 0) {
//            cout << p << " " << A[p].f << " " << i << " TEST " << nl;
        }
        while (p < N && A[p].f == i) {
//            cout << "OK" << nl;
            ckmax(vals[0], -A[p].f);
            ckmax(vals[1], -A[p].s);
            ckmax(vals[2], A[p].s - A[p].f);
            p++;
        }
        FOR(j, 3, 6) {
            while (v[j].top().s < p) {
                v[j].pop();
            }
            vals[j] = v[j].top().f;
        }

        if (i + vals[0] > d) continue;
        if (vals[3] - i > d) continue;
        int lo = max(0, max(vals[4] - d, vals[2] + i - d));
        int hi = min(d+i-vals[5], d-vals[1]);
/*        if (d == 3 && lo <= hi) {
            cout << i << " " << p << nl;
            cout << lo << " " << hi << nl;
            F0R(i, 6) {
                cout << vals[i] << " ";
            }
            cout << nl;
        }*/
        if (lo <= hi && (i != 0 || hi > 0)) {
            if (i > 0) {
                return {i, lo};
            } else return {i, max(lo, 1)};
        }

    }
    return {-1, -1};
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    F0R(i, N) {
        string S; cin >> S;
        int X = 0; F0R(j, sz(S)) if (S[j] == 'B') X++;
        A.pb({X, sz(S) - X});
    }
    sort(all(A));
    int lo = 0, hi = MX * 4;
    pi def = {-1, -1};
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (poss(mid) != def) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    pi res = poss(lo);
    cout << lo << nl;
    F0R(i, res.f) cout << 'B';
    F0R(i, res.s) cout << 'N';
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
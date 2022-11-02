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

pair<vi, vi> solve(vi L) {
    int N = sz(L);
    int sum = 0; F0R(i, N) sum += L[i];
    if (sum % 2) {
        return {vi(), vi()};
    }
    sum /= 2;
    int lst[sum+1]; F0R(i, sum+1) lst[i] = -1;
    lst[0] = 0;
    int sumSF = 0;
    F0R(i, N) {
        F0Rd(j, min(sum - L[i], sumSF) + 1) {
            if (lst[j] != -1 && lst[j+L[i]] == -1) {
                lst[j+L[i]] = L[i];
            }
        }
        sumSF += L[i];
    }
    if (lst[sum] == -1) return {vi(), vi()};
    multiset<int> rem; trav(a, L) rem.ins(a);
    vi fir;
    int cur = sum;
    while (cur > 0) {
        fir.pb(lst[cur]);
        rem.erase(rem.find(lst[cur]));
        cur -= lst[cur];
    }
    vi sec; trav(a, rem) sec.pb(a);
    return {fir, sec};
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int H; cin >> H;
        vi L(H); F0R(i, H) cin >> L[i];
        int V; cin >> V;
        vi P(V); F0R(i, V) cin >> P[i];
        if (H != V) {
            cout << "No" << nl; continue;
        }
        pair<vi, vi> A = solve(L);
        pair<vi, vi> B = solve(P);
        if (sz(A.f) == 0 || sz(B.f) == 0) {
            cout << "No" << nl; continue;
        }
        if (sz(A.f) > sz(A.s)) {
            swap(A.f, A.s);
        }
        if (sz(B.f) < sz(B.s)) {
            swap(B.f, B.s);
        }
        sort(all(A.f)); sort(all(A.s)); reverse(all(A.f)); reverse(all(A.s));
        sort(all(B.f)); sort(all(B.s)); 
        vi hor; F0R(i, sz(A.f)) hor.pb(A.f[i]);
        F0R(i, sz(A.s)) hor.pb(-A.s[i]);
        vi ver; F0R(i, sz(B.f)) ver.pb(B.f[i]);
        F0R(i, sz(B.s)) ver.pb(-B.s[i]);
        int X = 0, Y = 0;
        cout << "Yes" << nl;
        F0R(i, H+V) {
            cout << X << " " << Y << nl;
            if (i % 2 == 0) {
                X += hor[i/2];
            } else {
                Y += ver[i/2];
            }
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
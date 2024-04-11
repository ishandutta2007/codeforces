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
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

struct mi {
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
    mi operator++(int) { mi temp; temp.v = v++; return temp; }
    mi operator--(int) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};


typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

void solve() {

    int N; cin >> N;
    int A[26]; F0R(i, 26) cin >> A[i];
    mi dp[N+1][N+1][3][3];
    mi nxt[N+1][N+1][3][3];
    dp[0][0][2][2] = 1;
    F0R(iter, N) {
        F0R(i, N+1) {
            F0R(j, N+1) {
                F0R(k, 3) {
                    F0R(l, 3) {
                        if (i < N && k != 0) {
                            nxt[i+1][j][l][0]+=dp[i][j][k][l];
                        }
                        if (j < N && k != 1) {
                            nxt[i][j+1][l][1] += dp[i][j][k][l];
                        } 
                        if (k != 2 || iter < 2)  {
                            nxt[i][j][l][2] += dp[i][j][k][l];
                        }
                        nxt[i][j][l][2] += dp[i][j][k][l] * 23;
                    }
                }
            }
        }
        F0R(i, N+1) F0R(j, N+1) F0R(k, 3) F0R(l, 3) dp[i][j][k][l] = nxt[i][j][k][l];
        F0R(i, N+1) F0R(j, N+1) F0R(k, 3) F0R(l, 3) nxt[i][j][k][l] = 0;
    }

    mi wayOne[N+1], wayTwo[N+1][N+1];
    F0R(i, N+1) {
        F0R(j, N+1) {
            F0R(k, 3) {
                F0R(l, 3) {
                    wayOne[i] += dp[i][j][k][l];
                    wayTwo[i][j] += dp[i][j][k][l];
                }
            }
        }
    }
    F0Rd(i, N) wayOne[i] += wayOne[i+1];
    F0Rd(i, N+1) {
        F0Rd(j, N+1) {
            if (i < N) {
                wayTwo[i][j] += wayTwo[i+1][j];
            }
            if (j < N) {
                wayTwo[i][j] += wayTwo[i][j+1];
            }
            if (i < N && j < N) wayTwo[i][j] -= wayTwo[i+1][j+1];
        }
    }
    mi ans = pow(mi(25), N-2) * 26 * 26;
    F0R(i, 26) {
        if (A[i] < N) ans -= wayOne[A[i]+1];
        FOR(j, i+1, 26) {
            if (A[i] + A[j] + 2 <= N) ans += wayTwo[A[i]+1][A[j]+1];
        }
    }
    cout << ans << nl;
    
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
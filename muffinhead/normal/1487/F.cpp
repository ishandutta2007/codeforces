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

void solve() {

    string S; cin >> S;
    S = "0" + S;
    int N = sz(S);
    int dp[N][101][2001];
    F0R(i, N) {
        F0R(j, 101) F0R(k, 2001) dp[i][j][k] = 1000000;
    }
    dp[0][50][1000] = 0;
    F0R(i, N-1) {
        F0R(j, 100) {
            F0R(k, 2000) {
                ckmin(dp[i][j+1][k+1], dp[i][j][k] + N-i);
            }
        }
        FORd(j, 1, 101) {
            FORd(k, 1, 2001) {
                ckmin(dp[i][j-1][k-1], dp[i][j][k]+N-i);
            }
        }
        F0R(j, 101) {
            F0R(k, 2001) {
                int nxt = 50 + (j-50)*10 - (S[i+1]-'0') + (k-1000);
                if (nxt < 101 && nxt >= 0) {
                    ckmin(dp[i+1][nxt][k], dp[i][j][k]);
                    /*if (i+1 == N-1 && nxt == 56 && k == 1003) {
                        cout << "TEST " << j << " " << k << endl;
                    }*/
                }
            }
        }
    }
    int ans = 1000000;
    F0R(i, 101) F0R(j, 2001) {
        ckmin(ans, dp[N-1][i][j] + abs(i-50));
        /*if (dp[N-1][i][j] + abs(i-50) == 20) {
            cout << i-50 << " " << j-1000 << nl;
        }*/
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
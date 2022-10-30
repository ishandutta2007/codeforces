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
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int A[N];
        F0R(i, N) {
            char C; cin >> C; A[i] = (C == 'L' ? 1 : 0);
        }
        int ans = N;
        F0R(a, 2) {
            F0R(b, 2) {
                int dp[N][2][2];
                F0R(i, N) {
                    F0R(j, 2) {
                        F0R(k, 2) {
                            dp[i][j][k] = N;
                        }
                    }
                }
                dp[0][a][0] = abs(a - A[0]);
                dp[1][b][(a==b?1:0)] = abs(a-A[0]) + abs(b-A[1]);

                FOR(i, 1, N-1) {
                    F0R(j, 2) {
                        F0R(k, 2) {
                            F0R(l, 2) {
                                int nk = (j==l?k+1:0);
                                if (nk == 2) continue;
                                ckmin(dp[i+1][l][nk], dp[i][j][k] + abs(l-A[i+1]));
                            }
                        }
                    }
                }

                F0R(c, 2) {
                    F0R(d, 2) {
                        if ((a == b && b == c) || (a == c && d == 1)) continue;
/*                        if (dp[N-1][c][d] == 2) {
                            cout << a << " " << b << " " << c << " " << d << nl;
                        }*/
                        ckmin(ans, dp[N-1][c][d]);
                    }
                }
/*                if (a == 1 && b == 0) {
                    cout << dp[1][0][0] << nl;
                }*/
            }
        }
        cout << ans << nl;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
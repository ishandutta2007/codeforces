// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1407/D

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 300005;

int n;
int h[MAXN];
int dp[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 1, n + 1) {
        cin >> h[i];
    }
    REP (i, 0, n + 1) {
        dp[i] = INF;
    }
    dp[1] = 0;
    vi mnstk, mxstk;
    mnstk.pb(1);
    mxstk.pb(1);
    REP (i, 2, n + 1) {
        {
            while (!mnstk.empty() && h[mnstk.back()] < h[i]) {
                int u = mnstk.back(); mnstk.pop_back();
                cerr << "mn: " << u << '\n';
                mnto(dp[i], dp[u] + 1);
            }
            if (!mnstk.empty()) {
                mnto(dp[i], dp[mnstk.back()] + 1);
                if (h[mnstk.back()] == h[i]) {
                    mnstk.pop_back();
                }
            }
            mnstk.pb(i);
        }
        {
            while (!mxstk.empty() && h[mxstk.back()] > h[i]) {
                int u = mxstk.back(); mxstk.pop_back();
                cerr << "mx: " << u << '\n';
                mnto(dp[i], dp[u] + 1);
            }
            if (!mxstk.empty()) {
                mnto(dp[i], dp[mxstk.back()] + 1);
                if (h[mxstk.back()] == h[i]) {
                    mxstk.pop_back();
                }
            }
            mxstk.pb(i);
        }
        cerr << i << ": " << dp[i] << '\n';
    }
    cout << dp[n] << '\n';
    return 0;
}
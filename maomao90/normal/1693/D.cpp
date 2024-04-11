// time-limit: 2000
// problem-url: https://codeforces.com/contest/1693/problem/D

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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
const int MAXN = 200005;

int n;
int p[MAXN];
int dp[MAXN], pd[MAXN], f[MAXN];
ll ans;

inline void add(int i) {
    if (i > n) {
        return;
    }
    int mx = -1, mn = INF;
    if (p[i - 1] < p[i]) {
        mxto(mx, dp[i - 1]);
    }
    if (pd[i - 1] < p[i]) {
        mxto(mx, p[i - 1]);
    }
    if (p[i - 1] > p[i]) {
        mnto(mn, pd[i - 1]);
    }
    if (dp[i - 1] > p[i]) {
        mnto(mn, p[i - 1]);
    }
    if (dp[i] == mx && pd[i] == mn) {
        return;
    }
    dp[i] = mx; pd[i] = mn;
    f[i] = 0;
    if (dp[i] != -1 || pd[i] != INF) {
        add(i + 1);
        f[i] = f[i + 1] + 1;
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 1, n + 1) {
        cin >> p[i];
    }
    RREP (i, n, 1) {
        dp[i] = INF;
        pd[i] = -1;
        add(i + 1);
        f[i] = f[i + 1] + 1;
        ans += f[i];
    }
    cout << ans << '\n';
    return 0;
}
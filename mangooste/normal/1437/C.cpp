#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define ts to_string
#define sts string ts
sts(string s) { return s; }
sts(bool b) { return b ? "true" : "false"; }
sts(char c) { return string(1, c); }
sts(const char* s) { return (string) s; }
template<class A, class B> sts(pair<A, B>);
template<class T> sts(T v) { string s = "{", sep = ""; for (auto x : v) { s += sep; sep = ", "; s += ts(x); } return s + "}"; }
template<class A, class B> sts(pair<A, B> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
void dbgPrint() { cerr << endl; }
template<class A, class... B> void dbgPrint(A a, B... b) { cerr << " " << ts(a); dbgPrint(b...); }
#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define pb emplace_back

const ll INF = (ll) 1e12;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nCases;
    cin >> nCases;
    while (nCases--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
            x--;
        }

        sort(all(a));
        vector<vector<ll>> dp(n, vector<ll>(3 * n, INF));
        for (int i = 0; i < 3 * n; i++) {
            dp[0][i] = abs(a[0] - i);
        }
        for (int i = 1; i < n; i++) {
            for (int j = i; j < 3 * n; j++) {
                for (int k = 0; k < j; k++) {
                    if (dp[i - 1][k] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - a[i]));
                    }
                }
            }
        }

        cout << *min_element(all(dp.back())) << '\n';
    }
}
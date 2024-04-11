#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int f(string s, string t) {
    int n = s.size(), m = t.size();
    constexpr int INF = 1001001001;
    VVI dp(n + 1, VI(m + 1, INF));
    dp[0][0] = 0;
    int res = INF;
    rep(i, n + 1) rep(j, m + 1) if (dp[i][j] != INF) {
        chmin(res, dp[i][j] + n - i + m - j);
        if (i < n && j < m && s[i] == t[j]) chmin(dp[i + 1][j + 1], dp[i][j]);
        if (i < n) chmin(dp[i + 1][j], dp[i][j] + 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int ans = 10;
        unsigned long long x = 1;
        rep(_, 64) {
            string t = to_string(x);
            chmin(ans, f(s, t));
            x <<= 1;
        }
        cout << ans << '\n';
    }
}
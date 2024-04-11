#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;

    auto read = [&]() {
        string s;
        cin >> s;
        vector<array<int, 26>> pref(n + 1);
        pref[0].fill(0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            pref[i + 1][s[i] - 'a']++;
        }
        return make_pair(s, pref);
    };

    const auto [s, pref_s] = read();
    const auto [t, pref_t] = read();

    if (pref_s.back() != pref_t.back()) {
        cout << "-1\n";
        return;
    }

    const int INF = n * n;
    vector<vector<int>> dp(n, vector<int>(n, -INF));
    for (int i = 0; i < n; i++)
        if (t[i] == s[0])
            dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        int possib = -INF;
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (i <= j && s[i] == t[j])
                dp[i][j] = max(dp[i][j], possib + 1);

            bool valid = true;
            for (int k = 0; k < 26 && valid; k++)
                valid &= pref_s[i][k] <= pref_t[j + 1][k];

            if (valid)
                possib = max(possib, dp[i - 1][j]);
        }
    }

    cout << n - dp[n - 1][n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = char(0) + s;

    auto get_best = [&](char c) -> char {
        return c == char('a' + k - 1) || c == 'a' ? 'a' : c - 1;
    };

    vector<string> dp(n + 1);

    auto relax = [&](int i, const string &str) {
        if (dp[i].empty() || dp[i] > str)
            dp[i] = str;
    };

    for (int i = 0; i < n; dp[i++] = "") {
        relax(i + 1, dp[i] + get_best(s[i + 1]));
        if (i + 2 <= n) {
            relax(i + 2, dp[i] + get_best(s[i + 2]) + s[i + 1]);
            relax(i + 2, dp[i] + s[i + 2] + get_best(s[i + 1]));

            if (!dp[i].empty()) {
                dp[i] += s[i + 2];
                dp[i] += s[i + 1];
                swap(dp[i][len(dp[i]) - 2], dp[i][len(dp[i]) - 3]);

                relax(i + 2, dp[i]);

                swap(dp[i][len(dp[i]) - 2], dp[i][len(dp[i]) - 3]);
                dp[i].pop_back();
                dp[i].pop_back();
            }
        }

        if (!dp[i].empty()) {
            dp[i] += s[i + 1];
            swap(dp[i].back(), dp[i][len(dp[i]) - 2]);
            relax(i + 1, dp[i]);
        }
    }

    cout << dp.back() << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

inline ll solve(ll r, int b) {
    if (r == 0) {
        return 0;
    }
    vec<int> dr;
    for (; r != 0; r /= b) {
        dr.push_back(r % b);
    }
    reverse(all(dr));
    ll ans = 0;
    vec<int> cur(b);
    int diff = 0;
    vec<vec<ll>> dp(len(dr), vec<ll>(b + 1));
    auto solve = [&]() {
        for (int i = 1; i < len(dr); i++) {
            for (int cur = 0; cur <= b; cur++) {
                if (cur != 0) {
                    dp[i][cur] += dp[i - 1][cur - 1] * (b - (cur - 1));
                }
                if (cur != b) {
                    dp[i][cur] += dp[i - 1][cur + 1] * (cur + 1);
                }
            }
        }
        ans += dp.back()[0];
    };
    for (int lcp = 0; lcp < len(dr); lcp++) {
        for (int x = (lcp == 0 ? 1 : 0); x < dr[lcp]; x++) {
            int new_diff = diff + (cur[x] == 0 ? 1 : -1);
            dp[lcp][new_diff]++;
        }
        diff -= cur[dr[lcp]];
        cur[dr[lcp]] ^= 1;
        diff += cur[dr[lcp]];
    }
    if (diff == 0) {
        ans++;
    }
    for (int st = 1; st < len(dr) - 1; st++) {
        dp[st][1] += b - 1;
    }
    solve();
    return ans;
}

inline void solve() {
    int b;
    ll l, r;
    cin >> b >> l >> r;
    cout << solve(r, b) - solve(l - 1, b) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n);
    for (auto &x : a) {
        char c;
        cin >> c;
        x = c < 'a';
    }

    int answer = n;
    for (int rot : {0, 1}) {
        vector<pair<ll, int>> dp(n);

        auto solve = [&](ll cost) {
            fill(all(dp), pair<ll, int>{LLONG_MAX, 0});
            for (int i = 0; i < n; i++) {
                dp[i] = {(i == 0 ? 0 : dp[i - 1].first) + a[i], i == 0 ? 0 : dp[i - 1].second};

                ll prev_cost = i - l >= 0 ? dp[i - l].first : 0;
                int prev_cnt = i - l >= 0 ? dp[i - l].second : 0;
                dp[i] = min(dp[i], pair<ll, int>{prev_cost + cost, prev_cnt + 1});
            }

            return dp[n - 1];
        };

        int l = 0, r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            (solve(mid).second > k ? l : r) = mid;
        }

        const auto [total, cnt] = solve(r);
        answer = min(answer, int(total - 1ll * k * r));

        for (auto &x : a)
            x ^= 1;
    }

    cout << max(0, answer) << '\n';
}
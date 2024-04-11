#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    ll k;
    string s;
    cin >> n >> m >> k >> s;

    vector<pair<int, int>> a;
    const int C = n * (n + 1) / 2;
    a.reserve(C);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            a.emplace_back(i, j);
        }
    }
    assert(len(a) == C);

    vector lcp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            } else {
                lcp[i][j] = 0;
            }
        }
    }

    sort(all(a), [&](const auto &a, const auto &b) {
        int len_a = a.second - a.first + 1, len_b = b.second - b.first + 1;
        int cur_lcp = min({len_a, len_b, lcp[a.first][b.first]});
        if (cur_lcp == len_a) {
            if (len_a == len_b) return a.first < b.first;
            return true;
        } else if (cur_lcp == len_b) {
            return false;
        }
        return s[a.first + cur_lcp] < s[b.first + cur_lcp];
    });

    vector id(n, vector<int>(n));
    for (int i = 0; i < len(a); i++) {
        id[a[i].first][a[i].second] = i;
    }

    constexpr ll INF = 3e18;

    auto add = [&](ll x, ll y) {
        x += y;
        return x > INF ? INF : x;
    };

    auto get = [&](int at_least) {
        vector<int> start_from(n + 1);
        start_from[n] = n + 1;
        for (int i = 0; i < n; i++) {
            int l = i - 1, r = n;
            while (r - l > 1) {
                int mid = (l + r) >> 1;
                (id[i][mid] >= at_least ? r : l) = mid;
            }
            start_from[i] = r + 1;
        }

        vector<ll> dp(n + 1), pref(n + 2);
        dp[0] = 1;
        for (int cnt = 0;; cnt++) {
            if (cnt == m) return dp[n];

            fill(all(pref), 0);
            for (int i = 0; i <= n; i++) {
                pref[start_from[i]] = add(pref[start_from[i]], dp[i]);
            }
            for (int i = 0; i <= n; i++) {
                pref[i + 1] = add(pref[i + 1], pref[i]);
                dp[i] = pref[i];
            }
        }
    };

    int l = -1, r = C;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (get(mid) < k ? r : l) = mid;
    }
    assert(l != -1);
    cout << s.substr(a[l].first, a[l].second - a[l].first + 1) << '\n';
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    int n = 1 << k;
    vector<int> dp(4 * n);
    string s;
    cin >> s;
    int sz = (int) s.size();
    vector<int> where(sz), pos(4 * n), depth(4 * n);
    vector<pii> ar;

    int V = (1 << (k + 1)) - 1;

    function<void(int, int)> build = [&](int v, int d) {
        if (d > k)
            return;
        depth[v] = d;
        if (d == k) {
        } else {
            ar.emplace_back(-d, v);
            build(v << 1, d + 1);
            build(v << 1 | 1, d + 1);
        }
    };

    build(1, 0);

    sort(ar.begin(), ar.end());
    for (int it = 0; it < (int) ar.size(); it++) {
        auto [d, v] = ar[it];
        pos[v] = it;
    }

    for (int v = V; v >= 1; v--) {
        if (depth[v] == k) {
            dp[v] = 1;
        } else {
            int p = pos[v];
            if (s[p] == '0') dp[v] = dp[v << 1];
            else if (s[p] == '1') dp[v] = dp[v << 1 | 1];
            else dp[v] = dp[v << 1] + dp[v << 1 | 1];
        }
    }

    int q;
    cin >> q;

    for (int iter = 0; iter < q; iter++) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        s[p] = c;
        int v = ar[p].second;
        while (1) {
            if (s[p] == '0') dp[v] = dp[v << 1];
            else if (s[p] == '1') dp[v] = dp[v << 1 | 1];
            else dp[v] = dp[v << 1] + dp[v << 1 | 1];
            if (v == 1) break;
            v >>= 1;
            p = pos[v];
        }
        cout << dp[1] << "\n";
    }

    return 0;
}
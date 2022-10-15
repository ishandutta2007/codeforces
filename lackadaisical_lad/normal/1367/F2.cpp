#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> piles;
    for (int i = 0; i < n; i++) {
        if (!i || a[i].first != a[i - 1].first) {
            piles.push_back({});
        }
        piles.back().push_back(a[i].second);
    }
    int m = piles.size();
    vector<int> pref(m + 1);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + piles[i - 1].size();
    }
    vector<int> jmp(m);
    int j = 0;
    for (int i = 0; i < m; i++) {
        j = max(j, i);
        while (j + 1 < m && piles[j + 1][0] > piles[j].back()) {
            j++;
        }
        jmp[i] = j;
    }

    int ans = 1;
    int nxt = 0;
    for (int it = 0; it < m; it++) {
        ans = max<int>(ans, piles[it].size());
        if (it + 1 == m) continue;
        int sum = lower_bound(piles[it].begin(), piles[it].end(), piles[it + 1][0]) - piles[it].begin();
        int nxt = jmp[it + 1];
        sum += pref[nxt + 1] - pref[it + 1];
        if (nxt + 1 < m) {
            sum += piles[nxt + 1].end() - lower_bound(piles[nxt + 1].begin(), piles[nxt + 1].end(), piles[nxt].back());
        }
        ans = max<int>(ans, sum);

        for (int j = 0; j < piles[it].size(); j++) {
            int cnt = piles[it + 1].end() - lower_bound(piles[it + 1].begin(), piles[it + 1].end(), piles[it][j]);
            ans = max<int>(ans, j + 1 + cnt);
        }
    }
    cout << n - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}
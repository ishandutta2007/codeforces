#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> len(n, vector<int>(m));
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> len[i][j];
            a.emplace_back(len[i][j], i * m + j);
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int x = a[i].second / m;
        int y = a[i].second % m;
        swap(len[x][i], len[x][y]);
        for (int j = i + 1; j < m; j++) {
            if (x * m + i == a[j].second) {
                a[j].second = a[i].second;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << len[i][j] << " \n"[j + 1 == m];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
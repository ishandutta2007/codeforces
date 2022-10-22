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

const int N = 2e5 + 5;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<ll> g(n);
    vector<bitset<N>> h(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') {
                g[i] |= 1ll << j;
                h[j][i] = 1;
            }
        }
    }

    vector<int> bit(1 << p);
    for (int i = 0; i < p; i++)
        bit[1 << i] = i;

    int n2 = (n + 1) / 2;

    mt19937 rnd(42);

    ll res = 0;
    ll best = 0;

    for (int it = 0; it < 20; it++) {
        int i = rnd() % n;
        vector<int> bits;
        for (int j = 0; j < m; j++) {
            if ((1ll << j) & g[i])
                bits.push_back(j);
        }
        int sz = (int) bits.size();
        vector<ll> value(1 << sz), f(1 << sz), dp(1 << sz);
        for (i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < sz; j++) {
                if ((1ll << bits[j]) & g[i])
                    mask |= 1 << j;
            }
            f[mask]++;
        }
        for (int mask = 0; mask < (1 << sz); mask++) {
            for (int sub = mask; sub < (1 << sz); sub = (sub + 1) | mask)
                dp[mask] += f[sub];
        }
        for (int mask = 1; mask < (1 << sz); mask++) {
            int b = bit[mask & -mask];
            value[mask] = (1ll << bits[b]) | value[mask ^ (1 << b)];
        }
        for (int mask = 0; mask < (1 << sz); mask++) {
            if (dp[mask] >= n2) {
                ll tmp = __builtin_popcount(mask);
                if (tmp > best) {
                    best = tmp;
                    res = value[mask];
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        cout << ((res >> j) & 1);
    }
    cout << "\n";

    return 0;
}
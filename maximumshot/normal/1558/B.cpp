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

inline void _add(int& x, int y, int m) {
    if ((x += y) >= m)
        x -= m;
}

inline void _dec(int& x, int y, int m) {
    if ((x -= y) < 0)
        x += m;
}

int slow(int n, int m) {
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n; i > 1; i--) {
        for (int j = 1; j < i; j++) {
            if ((dp[j] += dp[i]) > m)
                dp[j] -= m;
        }
        for (int q = 2; q <= i; q++) {
            int j = i / q;
            if ((dp[j] += dp[i]) > m)
                dp[j] -= m;
        }
    }
    return dp[1];
}

int fast(int n, int m) {
    vector<int> dp(n + 1), sf(n + 2);
    dp[n] = sf[n] = 1;
    for (int sm = dp[n], i = n - 1; i >= 1; i--) {
        _add(dp[i], sm, m);
        for (int ki = 2 * i, k = 2; ki <= n; k++, ki += i) {
//            for (int r = 0; r < k; r++) {
//                int j = ki + r;
//                if (j <= n)
//                    _add(dp[i], dp[j], m);
//            }
            int lj = ki;
            int rj = min(n, ki + k - 1);
            _add(dp[i], sf[lj], m);
            _dec(dp[i], sf[rj + 1], m);
//            for (int j = lj; j <= rj; j++)
//                _add(dp[i], dp[j], m);
//            for (int j = i + 1; j <= n; j++) {
//                if ((j - j % k) == ki)
//                    _add(dp[i], dp[j], m);
//            }
        }
//        for (int j = i + 1; j <= n; j++) {
//            for (int k = 2; k <= j; k++) {
//                if (j / k == i)
//                    _add(dp[i], dp[j], m);
//            }
//        }
        _add(sm, dp[i], m);
        sf[i] = dp[i];
        _add(sf[i], sf[i + 1], m);
    }
    return dp[1];
}

void work() {
    int n, m;
    cin >> n >> m;
    int res = fast(n, m);
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}
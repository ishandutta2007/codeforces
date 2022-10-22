#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 1e6 + 5;

int pw10[6];

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pw10[0] = 1;
    for (int i = 1; i < 6; i++)
        pw10[i] = pw10[i - 1] * 10;

    int k;
    cin >> k;

    vector<ll> f(6);
    for (int i = 0; i < 6; i++)
        cin >> f[i];

    vector<ll> dp(X, -inf64);
    dp[0] = 0;

    for (int i = 0; i < 6; i++) {
        ll c = 3ll * (k - 1);
        for (ll g = 1; c > 0; g <<= 1) {
            ll dc = min(c, g);

            ll weight = 1ll * pw10[i] * dc * 3;
            ll cost = 1ll * f[i] * dc;

            for (ll x = X - 1; x >= weight; x--)
                dp[x] = max(dp[x], dp[x - weight] + cost);

            c -= dc;
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int x = X - 1; x >= 0; x--) {
            for (int d = 1; d < 10; d++) {
                int y = x - d * pw10[i];
                ll cost = (d % 3 ? 0ll : 1ll * (d / 3) * f[i]);
                if (y >= 0)
                    dp[x] = max(dp[x], dp[y] + cost);
            }
        }
    }

    int q;
    cin >> q;

    for (int iter = 0; iter < q; iter++) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}
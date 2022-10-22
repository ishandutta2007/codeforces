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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p, k;
    cin >> n >> p >> k;
    vector<ll> a(n), aa = a;

    for (ll &x : a)
        cin >> x;

    vector<vector<ll>> s(n, vector<ll>(p)), ss = s;
    for (int i = 0; i < n; i++) {
        for (int j= 0; j < p; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    sort(perm.begin(), perm.end(), [&](int i, int j) { return a[i] > a[j]; });

    for (int i = 0; i < n; i++) {
        aa[i] = a[perm[i]];
        ss[i] = s[perm[i]];
    }

    a = aa;
    s = ss;

    vector<ll> dp(1 << p), nx;
    vector<int> cnt(1 << p);

    for (int i = 0; i < (int) cnt.size(); i++) {
        cnt[i] = __builtin_popcount(i);
    }

    for (int i = 0; i < n; i++) {
        nx = dp;
        for (int mask = 0; mask < (1 << p); mask++) {
            if (cnt[mask] > i)
                continue;
            if (i + 1 - cnt[mask] <= k) {
                nx[mask] = dp[mask] + a[i];
            } else {
                nx[mask] = dp[mask];
            }
        }
        for (int mask = 0; mask < (1 << p); mask++) {
            for (int j = 0; j < p; j++) {
                if ((1 << j) & mask)
                    continue;
                nx[mask | (1 << j)] = max(nx[mask | (1 << j)], dp[mask] + s[i][j]);
            }
        }
        dp = nx;
    }

    cout << dp[(1 << p) - 1] << "\n";

    return 0;
}
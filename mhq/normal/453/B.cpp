#include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
const int INF = (int)1e9;
int n;
vector < int > primes;
int f[maxN];
int a[maxN];
int dp[maxN][1 << 17];
int prv[maxN][1 << 17];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int lim = 58;
    for (int i = 2; i <= lim; i++) {
        bool ok = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok) primes.push_back(i);
    }
    int k = primes.size();
    for (int i = 2; i <= lim; i++) {
        for (int j = 0; j < primes.size(); j++) {
            if (i % primes[j] == 0) f[i] |= (1 << j);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int mask = 0; mask < (1 << k); mask++) {
            dp[i][mask] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i + 1 <= n; i++) {
        for (int mask = 0; mask < (1 << k); mask++) {
            for (int val = 1; val <= lim; val++) {
                if ((f[val] & mask) != 0) continue;
                if (dp[i + 1][mask | f[val]] > dp[i][mask] + abs(a[i + 1] - val)) {
                    dp[i + 1][mask | f[val]] = dp[i][mask] + abs(a[i + 1] - val);
                    prv[i + 1][mask | f[val]] = val;
                }
            }
        }
    }
    vector < int > ans;
    int mn = INF;
    int mask = 0;
    for (int nmask = 0; nmask < (1 << k); nmask++) {
        if (dp[n][nmask] < mn) {
            mn = dp[n][nmask];
            mask = nmask;
        }
    }
    for (int i = n; i >= 1; i--) {
        ans.push_back(prv[i][mask]);
        mask ^= f[prv[i][mask]];
    }
    reverse(ans.begin(), ans.end());
    for (int x: ans) cout << x << " ";
    return 0;
}
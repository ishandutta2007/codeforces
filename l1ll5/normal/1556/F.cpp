#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 14 + 2;
const int S = (1 << 14) + 5;
const int mod = 1000000000 + 7;
int n, q;
int dp[S], a[N], Win[N][N], Vis[N][S];
int Qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = (LL)ret * a % mod;
        }
        a = (LL)a * a % mod; b >>= 1;
    }
    return ret;
}
/*
    1-
*/
int rev[S];
int cnt[S];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int BIGS = 1 << n;
    for (int i = 0; i <= n; i += 1) {
        rev[(1 << i)] = i;
    }
    for (int i = 1; i < BIGS; i += 1) {
        cnt[i] = cnt[i - (i & (-i))] + 1;
    }
    for (int i = 0; i < n; i += 1)
        cin >> a[i];
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            Win[i][j] = (LL)a[i] * Qpow(a[i] + a[j], mod - 2) % mod;
        }
    }
    for (int p = 0; p < n; p += 1) {
        for (int i = 0; i < BIGS; i += 1) {
            Vis[p][i] = 1;
            int S = i;
            while (S) {
                int lowbit = S & (-S);
                Vis[p][i] = (LL)Vis[p][i] * Win[p][rev[lowbit]] % mod;
                S ^= lowbit;
            }
        }
    }
    for (int i = 0; i < BIGS; i += 1) {
        LL sum = 0;
        for (int j = (i - 1) & i; j != 0; j = (j - 1) & i) {
            LL cur = dp[j];

            int S = j;
            while (S) {
                int lowbit = S & (-S);
                cur = cur * Vis[rev[lowbit]][i - j] % mod;
                S ^= lowbit;
            }
            sum += cur;
            sum %= mod;

        }
        //cout << i << ' ' << sum << endl;
        dp[i] = (1 - sum + mod) % mod;
    }
    LL ans = 0;

    for (int i = 0; i < BIGS; i += 1) {
        LL cur = dp[i];
        int S = i;
        while (S) {
            int lowbit = S & (-S);
            cur = cur * Vis[rev[lowbit]][(BIGS - 1) - i] % mod;
            S ^= lowbit;
        }
        //cout << dp[i] << ' ' << cur << endl;
        ans += (cur * cnt[i] % mod);
        ans %= mod;
    }
    cout << ans << '\n';
}
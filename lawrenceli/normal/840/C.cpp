#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 305;
const int mod = 1e9 + 7;

int n, ar[maxn];
bool conn[maxn][maxn];
bool vis[maxn];

int dp[2][maxn][maxn]; // i, # bad adjacent, # bad adjacent equal number

void add(int& a, int b) { a = (a + b) % mod; }

void reset() {
    for (int j = 0; j < maxn; j++)
        for (int k = 0; k < maxn; k++)
            dp[0][j][k] = dp[1][j][k], dp[1][j][k] = 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            ll x = ll(ar[i]) * ar[j];
            ll t = ll(sqrt(ld(x)));
            if (t * t == x || (t - 1) * (t - 1) == x || (t + 1) * (t + 1) == x) conn[i][j] = 1;
        }

    int cnt = 0, m = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            for (int j = 0; j < n; j++)
                if (conn[i][j]) {
                    ar[m++] = cnt;
                    vis[j] = 1;
                }
            cnt++;
        }

    //for (int i = 0; i < n; i++) cout << ar[i] << ' '; cout << endl;

    assert(n == m);

    dp[0][0][0] = 1;
    int last = 0;
    for (int i = 0; i < n; i++) {
        bool same = (i != 0 && ar[i] == ar[i - 1]);
        if (!same) {
            for (int j = 0; j < maxn; j++)
                for (int k = 0; k < maxn; k++)
                    if (j + k < maxn)
                        add(dp[1][j + k][0], dp[0][j][k]);
            reset();
            last = i;
        }

        for (int j = 0; j < maxn; j++)
            for (int k = 0; k < maxn; k++)
                if (dp[0][j][k]) {
                    //place between two bad
                    if (j) add(dp[1][j - 1][k], ll(dp[0][j][k]) * j % mod);
                    //place next to same
                    int nump = 2 * (i - last) - k;
                    assert(nump >= 0);
                    add(dp[1][j][k + 1], ll(dp[0][j][k]) * nump % mod);
                    //place elsewhere
                    assert(i + 1 - j - nump >= 0);
                    add(dp[1][j][k], ll(dp[0][j][k]) * (i + 1 - j - nump) % mod);
                }

        reset();
    }

    cout << dp[0][0][0] << '\n';
}
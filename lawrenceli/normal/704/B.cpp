#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5005;
const ll inf = 1e18;

int n, s, e;
int x[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
ll dp[2][maxn][2][2];

void setmin(ll& l1, ll l2) { if (l1 > l2) l1 = l2; }

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> s >> e;
    s--, e--;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < maxn; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    dp[i][j][k][l] = inf;
    if (s == 0) dp[0][0][0][1] = -x[0] + d[0];
    else if (e == 0) dp[0][0][1][0] = -x[0] + b[0];
    else dp[0][0][1][1] = -2 * x[0] + b[0] + d[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    if (dp[0][j][k][l] < inf) {
                        ll v = dp[0][j][k][l];
                        if (s == i) {
                            assert(k);
                            setmin(dp[1][j][0][l], v + x[i] + c[i]);
                            setmin(dp[1][j + 1][0][l], v - x[i] + d[i]);
                        } else if (e == i) {
                            assert(l);
                            setmin(dp[1][j][k][0], v + x[i] + a[i]);
                            setmin(dp[1][j + 1][k][0], v - x[i] + b[i]);
                        } else {
                            if (j) {
                                setmin(dp[1][j + 1][k][l], v - 2 * x[i] + b[i] + d[i]);
                                setmin(dp[1][j][k][l], v + a[i] + d[i]);
                                setmin(dp[1][j][k][l], v + c[i] + b[i]);
                                setmin(dp[1][j - 1][k][l], v + 2 * x[i] + a[i] + c[i]);
                            }

                            if (k) {
                                setmin(dp[1][j][k][l], v + b[i] + c[i]);
                                setmin(dp[1][j + 1][k][l], v - 2 * x[i] + b[i] + d[i]);
                            }

                            if (l) {
                                setmin(dp[1][j][k][l], v + a[i] + d[i]);
                                setmin(dp[1][j + 1][k][l], v - 2 * x[i] + b[i] + d[i]);
                            }
                        }
                    }

        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    dp[0][j][k][l] = dp[1][j][k][l], dp[1][j][k][l] = inf;
    }

    cout << dp[0][0][0][0] << '\n';
}
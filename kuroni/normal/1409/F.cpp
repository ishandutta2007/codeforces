#include <bits/stdc++.h>
using namespace std;

const int N = 205, INF = 1E9 + 7;

int n, k, dp[N][N][N];
char s[N], t[N];

void maxi(int& u, int v) {
    u = max(u, v);
}

int mv(int nxt, char c) {
    if (nxt <= 2) {
        return c != t[nxt];
    } else {
        return c == t[1] || c == t[2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> (s + 1) >> (t + 1);
    t[3] = max(t[1], t[2]) + 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int s = 0; s <= n; s++) {
                dp[i][j][s] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                for (int nxt = 1; nxt <= 3; nxt++) {
                    int co = mv(nxt, s[i + 1]);
                    maxi(dp[i + 1][j + co][k + (t[nxt] == t[1])], dp[i][j][k] + k * (t[nxt] == t[2]));
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans;
}
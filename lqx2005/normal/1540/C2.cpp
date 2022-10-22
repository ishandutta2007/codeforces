#include <bits/stdc++.h>

using namespace std;
typedef double db;
typedef long long i64;
const int N = 100 + 10, P = 1e9 + 7;
int n, b[N], c[N];
int dp[N][N * N];
int ans[N];
int query(int x) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int s = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= s; j++) {
            (dp[i][j + c[i] + 1] += P - dp[i - 1][j]) %= P;
            (dp[i][j] += dp[i - 1][j]) %= P;
        }
        s += c[i];
        for(int j = 1; j <= s; j++) {
            (dp[i][j] += dp[i][j - 1]) %= P;
        }
        for(int j = 0; j <= s; j++) {
            if(j + sum < i * x) {
                dp[i][j] = 0;
            }
        }
        sum -= b[i];
    }
    int ans = 0;
    for(int j = 0; j <= s; j++) (ans += dp[n][j]) %= P;
    return ans;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i < n; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    int L = 0, R = N * N + N, s = 0, t = 0;
    for(int i = 1; i <= n; i++) {
        s += b[i - 1], t += c[i] - b[i - 1];
        L = max(L, s / i);
        R = min(R, (t - (t % i + i) % i) / i);
    }
    L = -L;
    for(int i = L - 1; i <= R; i++) ans[i - L + 1] = query(i);
    int q, x;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> x;
        if(x < L) {
            cout << ans[0] << endl;
        } else if(x > R) {
            cout << 0 << endl;
        } else {
            cout << ans[x - L + 1] << endl;
        }
    }
    return 0;
}
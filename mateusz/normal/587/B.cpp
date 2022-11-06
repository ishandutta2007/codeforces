#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, M = 1e9 + 7;

int n, x;
long long l;
int cnt[N], cnt2[N];
pair<int, int> tab[N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int k;

int main() {

    scanf("%d %I64d %d", &n, &l, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i].first);
        tab[i].second = i;
    }
    int rest = l % n;
    sort(tab + 1, tab + 1 + n);
    int in = 0;
    for (int i = 1; i <= n; i++) {
        if (tab[i].first != tab[i - 1].first) {
            in++;
        }
        cnt[in]++;
        if (tab[i].second <= rest) {
            cnt2[in]++;
        }
    }

    int dp[k + 5][n + 5];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }

    int i = 1;
    int ans = 0;
    long long div = l / n;
    int mxVal = min((long long)k, l / (long long)(i * n));
    for (i = 1; i <= mxVal; i++) {
        for (int j = 1; j <= n; j++) {
            add(dp[i][j], (long long)dp[i - 1][j] * cnt[j] % M);
            add(ans, (long long)((div - i + 1) % M) * ((long long)dp[i - 1][j] * cnt[j] % M) % M);
            add(ans, (long long)dp[i - 1][j] * cnt2[j] % M);
            add(dp[i][j], dp[i][j - 1]);
        }
    }
    if (i <= k) {
        for (int j = 1; j <= n; j++) {
            add(dp[i][j], dp[i][j - 1]);
            add(dp[i][j], (long long)dp[i - 1][j] * cnt2[j] % M);
        }
        add(ans, dp[i][n]);
    }

    printf("%d\n", ans);
    return 0;
}
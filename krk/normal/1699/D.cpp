#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Inf = 1000000000;

int T;
int n;
int a[Maxn];
bool good[Maxn][Maxn];
int cnt[Maxn];
int dp[Maxn];

bool Check(int l, int r)
{
    return l > r || good[l][r];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            int mx = 0;
            fill(cnt, cnt + n, 0);
            for (int j = i, s = 1; j < n; j++, s++) {
                cnt[a[j]]++;
                mx = max(mx, cnt[a[j]]);
                good[i][j] = s % 2 == 0 && 2 * mx <= s;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            if (Check(0, i - 1)) dp[i] = 1;
            else dp[i] = -Inf;
        for (int i = 0; i < n; i++) if (dp[i] >= 0) {
            if (Check(i + 1, n - 1)) res = max(res, dp[i]);
            for (int j = i + 1; j < n; j++) if (a[i] == a[j])
                if (Check(i + 1, j - 1)) dp[j] = max(dp[j], dp[i] + 1);
        }
        printf("%d\n", res);
    }
    return 0;
}
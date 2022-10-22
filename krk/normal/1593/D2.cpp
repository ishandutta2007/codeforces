#include <bits/stdc++.h>
using namespace std;

const int Maxn = 42;
const int Maxm = 21;

int T;
int n;
int a[Maxn];
set <int> dp[Maxn][Maxm];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            for (int j = 0; j < Maxm; j++)
                dp[i][j].clear();
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                for (int k = 1; k < n / 2; k++)
                    for (auto cur: dp[j][k]) {
                        int cand = gcd(cur, a[i] - a[j]);
                        dp[i][k + 1].insert(cand);
                    }
            dp[i][1].insert(0);
        }
        bool zer = false;
        int mx = 0;
        for (int i = 0; i < n; i++) if (!dp[i][n / 2].empty()) {
            if (*dp[i][n / 2].begin() == 0) zer = true;
            mx = max(mx, *dp[i][n / 2].rbegin());
        }
        printf("%d\n", zer? -1: mx);
    }
    return 0;
}
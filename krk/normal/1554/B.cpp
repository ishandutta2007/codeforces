#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 17;

int dp[1 << Maxm][2];
int T;
int n, k;
int a;

void Add(int ind, int val)
{
    if (val == 0 || dp[ind][0] == val || dp[ind][1] == val) return;
    if (val > dp[ind][0]) dp[ind][1] = dp[ind][0], dp[ind][0] = val;
    else if (val > dp[ind][1]) dp[ind][1] = val;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        int pw = 1;
        while (1 << pw <= n) pw++;
        fill((int*)dp, (int*)dp + (1 << pw) * 2, 0);
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            Add(a, i);
        }
        for (int i = 0; i < pw; i++)
            for (int j = 0; j < 1 << pw; j++)
                if (!(j & 1 << i)) {
                    Add(j | 1 << i, dp[j][0]);
                    Add(j | 1 << i, dp[j][1]);
                }
        ll res = -1000000000;
        for (int j = 0; j < 1 << pw; j++)
            if (dp[j][0] && dp[j][1])
                res = max(res, ll(dp[j][0]) * dp[j][1] - k * j);
        printf("%I64d\n", res);
    }
    return 0;
}
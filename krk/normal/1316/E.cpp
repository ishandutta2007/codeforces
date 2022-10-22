#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxp = 7;
const ll Inf = 1000000000000000000ll;

int bits[1 << Maxp];
int n, p, k;
int a[Maxn], seq[Maxn];
int s[Maxn][Maxp];
ll dp[Maxn][1 << Maxp];

bool Less(const int &fir, const int &sec)
{
    return a[fir] > a[sec];
}

int main()
{
    for (int i = 1; i < 1 << Maxp; i++)
        bits[i] = __builtin_popcount(i);
    scanf("%d %d %d", &n, &p, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        seq[i] = i;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &s[i][j]);
    sort(seq, seq + n, Less);
    fill((ll*)dp, (ll*)dp + Maxn * (1 << Maxp), -Inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1 << p; j++) if (dp[i][j] >= 0) {
            for (int k = 0; k < p; k++) if (!(j & 1 << k))
                dp[i + 1][j | 1 << k] = max(dp[i + 1][j | 1 << k], dp[i][j] + s[seq[i]][k]);
            int tk = i - bits[j];
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (tk < k? a[seq[i]]: 0));
        }
    cout << dp[n][(1 << p) - 1] << endl;
    return 0;
}
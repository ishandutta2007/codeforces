#include <iostream>
#include <cstdio>
using namespace std;

const int N = 12, MAX = 100;

int n, m, q, k, a[N], sum[1 << N], cnt[1 << N], dp[1 << N][MAX + 1];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = n - 1; i >= 0; i--)
        cin >> a[i];
    while (m--)
    {
        int tmp = 0;
        cin >> s;
        for (int i = 0; i < n; i++)
            (tmp <<= 1) ^= (s[i] - '0');
        cnt[tmp]++;
    }
    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            if (mask >> i & 1)
                sum[mask] += a[i];
    for (int i = 0; i < (1 << n); i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
            if (sum[mask] <= MAX)
                dp[i][sum[mask]] += cnt[((1 << n) - 1) ^ mask ^ i];
        for (int j = 1; j <= MAX; j++)
            dp[i][j] += dp[i][j - 1];
    }
    while (q--)
    {
        int tmp = 0;
        cin >> s >> k;
        for (int i = 0; i < n; i++)
            (tmp <<= 1) ^= (s[i] - '0');
        cout << dp[tmp][k] << '\n';
    }
}
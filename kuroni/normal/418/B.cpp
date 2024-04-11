#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 20;
const long long INF = 4E18 + 7;

int n, m, b, u, t;
long long dp[1 << M];

struct SFriend
{
    int x, k, msk;
} a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> b;
    fill(dp, dp + (1 << m), INF);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].k >> t;
        while (t--)
        {
            cin >> u;
            a[i].msk ^= (1 << (u - 1));
        }
    }
    sort(a + 1, a + n + 1, [](const SFriend &a, const SFriend &b) {
        return a.k > b.k;
    });
    for (int i = 1; i <= n; i++)
    {
        dp[a[i].msk] = min(dp[a[i].msk], a[i].x + 1LL * b * a[i].k);
        for (int msk = 1; msk < (1 << m); msk++)
        {
            int nxt = msk | a[i].msk;
            dp[nxt] = min(dp[nxt], dp[msk] + a[i].x);
        }
    }
    cout << (dp[(1 << m) - 1] == INF ? -1 : dp[(1 << m) - 1]);
}
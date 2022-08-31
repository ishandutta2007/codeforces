#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int max_n = 200009;

ll sum[max_n];
ll dp[max_n][2];
int m[max_n];

ll maxtree[4 * max_n];
ll mintree[4 * max_n];

void update_max(int cur, int l, int r, int pos, ll value)
{
    if (l == r)
    {
        maxtree[cur] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        update_max(cur * 2, l, mid, pos, value);
    }
    else
    {
        update_max(cur * 2 + 1, mid + 1, r, pos, value);
    }
    maxtree[cur] = max(maxtree[cur * 2], maxtree[cur * 2 + 1]);
}

void update_min(int cur, int l, int r, int pos, ll value)
{
    if (l == r)
    {
        mintree[cur] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        update_min(cur * 2, l, mid, pos, value);
    }
    else
    {
        update_min(cur * 2 + 1, mid + 1, r, pos, value);
    }
    mintree[cur] = min(mintree[cur * 2], mintree[cur * 2 + 1]);
}

ll getmax(int cur, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
    {
        return maxtree[cur];
    }
    if (ql > r || qr < l) return -1e10;

    int mid = (l + r) / 2;
    ll m1 = getmax(cur * 2, l, mid, ql, min(mid, qr));
    ll m2 = getmax(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr);
    return max(m1, m2);
}

ll getmin(int cur, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
    {
        return mintree[cur];
    }
    if (ql > r || qr < l) return 1e10;

    int mid = (l + r) / 2;
    ll m1 = getmin(cur * 2, l, mid, ql, min(mid, qr));
    ll m2 = getmin(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr);
    return min(m1, m2);
}

int main()
{
    for (int i = 0; i < 4*max_n; i++)
    {
        maxtree[i] = -1e10;
        mintree[i] = 1e10;
    }
    int n;
    scanf("%d", &n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", m + i);
        s += m[i];
        sum[i] = s;
    }

    dp[n][0] = 0;
    dp[n][1] = 0;
    ll maxx = -1e10;
    ll minn = 1e10;
    for (int i = n - 1; i > 0; i--)
    {
        //update_max(1, 0, n - 1, i, sum[i] + dp[i + 1][1]);
        //update_min(1, 0, n - 1, i, dp[i + 1][0] - sum[i]);
        maxx =max(maxx, sum[i] + dp[i + 1][1]);
        minn =min(minn, dp[i + 1][0] - sum[i]);
        //ll maxx = getmax(1, 0, n - 1, i, n - 1);
        //ll maxx = -1e10;
        /*for (int j = i; j < n; j++)
        {
            maxx = max(maxx, sum[j] + dp[j + 1][1]);
        }*/
        dp[i][0] = maxx;
        //ll minn = getmin(1, 0, n - 1, i, n - 1);
        //ll minn = 1e10;
        /*for (int j = i; j < n; j++)
        {
            minn = min(minn, dp[j + 1][0] - sum[j]);
        }*/
        dp[i][1] = minn;
    }
    cout << dp[1][0];
    return 0;
}
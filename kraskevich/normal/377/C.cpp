#include <bits/stdc++.h>

using namespace std;

#define PII pair<int, int>
#define F first
#define S second

const int N = 20;
const int INF = (int)1e9;

int a[111];
int dp[1 << N];
bool was[1 << N];
int n, m;
string type[N];
int team[N];

int getDp(int mask)
{
    int p = __builtin_popcount(mask);
    if (p == m)
        return 0;
    if (was[mask])
        return dp[mask];
    was[mask] = true;
    int &res = dp[mask];
    res = -INF;
    if (type[p] == "p")
    {
        int j = -1;
        for (int i = 0; i < m; i++)
            if (!(mask & (1 << i)))
            {
                j = i;
                break;
            }
        assert(j >= 0);
        if (p == m - 1 || team[p] == team[p + 1])
            res = a[j] + getDp(mask | (1 << j));
        else
            res = a[j] - getDp(mask | (1 << j));
    }
    else
    {
        bool same = true;
        if (p < m - 1 && team[p] != team[p + 1])
            same = false;
        for (int i = 0; i < m; i++)
            if (!(mask & (1 << i)))
            {
                if (same)
                    res = max(res, getDp(mask | (1 << i)));
                else
                    res = max(res, -getDp(mask | (1 << i)));
            }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    for (int i = 0; i < (1 << N); i++)
        was[i] = false;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> type[i] >> team[i];
    int res = getDp(0);
    if (team[0] == 2)
        res = -res;
    cout << res;

    return 0;
}
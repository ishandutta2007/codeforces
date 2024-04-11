#include <bits/stdc++.h>

using namespace std;

const int N = 3333;

long long dp[N][2];
long long a[N][3];
int n;

long long calc(int pos, int type)
{
    if (dp[pos][type] >= 0)
        return dp[pos][type];
    long long &res = dp[pos][type];
    if (pos == n - 1)
        res = a[pos][type];
    else
        res = max(a[pos][type] + calc(pos + 1, 1), a[pos][type + 1] + calc(pos + 1, 0));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);

    cin >> n;
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < n; i++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            dp[i][j] = -1;

    cout << calc(0, 0);

    return 0;
}
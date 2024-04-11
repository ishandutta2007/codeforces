#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <string.h>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

const int N = 200 * 1000;
bool pr[N];
int dp[N];
int row[N];
int col[N];
int a[1000][1000];

void solve()
{
    for (int i = 0; i < N; ++i)
        pr[i] = isPrime(i);
    int last = N - 1;
    for (int i = N - 1; i >= 0; --i)
    {
        if (pr[i])
            last = i;
        dp[i] = last - i;
    }


    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    for (int i = 0; i < n; ++i)
    {
        row[i] = 0;
        for (int j = 0; j < m; ++j)
            row[i] += dp[a[i][j]];
    }

    for (int j = 0; j < m; ++j)
    {
        col[j] = 0;
        for (int i = 0; i < n; ++i)
            col[j] += dp[a[i][j]];
    }

    int res = 1000 * 1000 * 1000;
    for (int i = 0; i < n; ++i)
        res = min(res, row[i]);
    for (int j = 0; j < m; ++j)
        res = min(res, col[j]);

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();


    return 0;

}
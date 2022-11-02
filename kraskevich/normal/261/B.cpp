#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <cctype>
#include <ctime>

using namespace std;



const int N = 55;
int a[N];
long double dp[N][N][N];
long double fact[N];
long double res = 0;
int n;
int p;

void solve()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            fill(dp[i][j], dp[i][j] + N, 0.0);
    fact[0] = 1.0;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i;
    dp[0][0][0] = 1.0;


    for (int cur = 0; cur < n; ++cur)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                fill(dp[i][j], dp[i][j] + N, 0.0);
        dp[0][0][0] = 1.0;

        for (int i = 0; i < n; ++i)
            for (int cnt = 0; cnt < n; ++cnt)
                for (int sum = 0; sum <= p; ++sum)
                {
                    dp[i + 1][cnt][sum] += dp[i][cnt][sum];
                    if (i != cur && a[i] + sum <= p)
                        dp[i + 1][cnt + 1][sum + a[i]] += dp[i][cnt][sum];
                }

        for (int cnt = 0; cnt < n; ++cnt)
            for (int sum = 0; sum <= p; ++sum)
                if (sum + a[cur] > p)
                    res += dp[n][cnt][sum] * fact[cnt] / fact[n] * fact[n - cnt - 1] * cnt;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> p;

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];

    if (sum <= p)
    {
        cout << n;
        return 0;
    }

    solve();

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res;


    return 0;
}
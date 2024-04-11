#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const int N = 100 * 1000 + 1;
const long long INF = (long long)1e18;
long long dp[N];
int v[N], c[N];
int n;
long long mx1;
long long mx2;

long long solve(int a, int b)
{
    fill(dp, dp + N, -INF);
    dp[0] = 0;
    mx1 = 0;
    mx2 = -INF;
    for (int i = 0; i < n; i++)
    {
        long long s = a * 1ll * v[i] + dp[c[i]];
        long long mx = (dp[c[i]] == mx1 ? mx2 : mx1);
        long long d = mx + b * 1ll * v[i];
        long long cur = max(s, d);
        if (cur <= dp[c[i]])
            continue;
        long long was = dp[c[i]];
        dp[c[i]] = cur;
        if (was == mx1)
        {
            mx1 = cur;
            continue;
        }
        if (was == mx2)
        {
            mx2 = cur;
            if (mx1 < mx2)
                swap(mx1, mx2);
            continue;
        }
        if (cur >= mx1)
        {
            mx2 = mx1;
            mx1 = cur;
            continue;
        }
        if (cur >= mx2)
        {
            mx2 = cur;
        }
    }
    return *max_element(dp, dp + N);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }

    return 0;
}
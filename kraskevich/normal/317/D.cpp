#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
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

/*map<int, int> dp;

int nimber(int mask)
{
    if (dp.count(mask))
        return dp[mask];
    set<int> was;
    for (int b = 0; b < 30; b++)
    {
        if ((mask & (1 << b)) == 0)
            continue;
        int to = mask;
        for (int i = b; i < 30; i += (b + 1))
            if (to & (1 << i))
                to = (to ^ (1 << i));
        was.insert(nimber(to));
    }
    dp[mask] = 0;
    while (was.count(dp[mask]))
        dp[mask]++;
    return dp[mask];
}*/


int g[] = {1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

set<int> u;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int q = n;
    int res = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (u.count(i))
            continue;
        long long b = 1;
        int curr = 0;
        for (;;)
        {
            b *= i;
            if (b > n)
                break;
            u.insert(b);
            curr++;
            q--;
        }
        res ^= g[curr - 1];
    }
    q %= 2;
    res ^= q;

    cout << (res == 0 ? "Petya" : "Vasya");

    return 0;
}
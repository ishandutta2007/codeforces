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

const int N = 100 * 1000 + 2;
unsigned int prev_dp[N >> 1], cur_dp[N >> 1];
string s;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    cin >> s;

    int q = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '?')
            q++;

    memset(prev_dp, 0, N << 1);
    prev_dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int f = i + 1;
        if (f > n - i)
            f = n - i;
        f++;
        cur_dp[0] = 0;
        if (s[i] == '?')
        {
            cur_dp[0] = prev_dp[1];
            for (int j = 1; j < f; j++)
                cur_dp[j] = prev_dp[j - 1] + prev_dp[j + 1];
        }
        else
        {
            for (int j = 1; j < f; j++)
                cur_dp[j] = prev_dp[j - 1];
        }
        memcpy(prev_dp, cur_dp, f << 2);
    }

    for (int i = 0; i < q - n / 2; i++)
        cur_dp[0] = cur_dp[0] * 25;

    cout << cur_dp[0];

    return 0;
}
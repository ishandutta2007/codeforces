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

#define PII pair<int, int>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __div__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;


const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000 + 1;
const int N = 24;

int sum[1 << N];
int dp[1 << N];
int k1, k2, n, k;
int a[N];

int add(int a, int b)
{
    int c = a + b;
    if (c > INF)
        c = INF;
    return c;
}

/*void go(int pos, int mask, int s)
{
    if (pos == n)
    {
        sum[mask] = s;
        return;
    }
    go(pos + 1, mask, s);
    go(pos + 1, mask | (1 << pos), add(s, a[pos]));
}*/


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    k1 = k2 = -1;
    if (k > 0)
        cin >> k1;
    if (k > 1)
        cin >> k2;
    //go(0, 0, 0);
    for (int i = 0; i < (1 << n); i++)
        dp[i] = 0;
    dp[0] = 1;
    sum[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
            {
                sum[mask] = add(sum[mask ^ (1 << i)], a[i]);
                break;
            }
        if (sum[mask] == k1 || sum[mask] == k2)
            continue;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                dp[mask] += dp[mask ^ (1 << i)];
                if (dp[mask] >= MOD)
                    dp[mask] -= MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1];


    return 0;
}
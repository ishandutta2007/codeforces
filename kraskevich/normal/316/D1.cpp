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
#define PLL pair<long long, long long>
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

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long double LD;

const long long MOD = 1000 * 1000 * 1000 + 7;
const int N = 1000 * 1000 + 10;

long long dp[N];

int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            c1++;
        else
            c2++;
    }
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= c1; i++)
        dp[i] = dp[i - 1] + dp[i - 2] * (i - 1);
    long long res = dp[c1];
    for (int i = c1 + 1; i <= c1 + c2; i++)
        res *= i, res %= MOD;

    cout << res;

    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <string.h>
#include <cctype>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;


//-----TEMPLATE STARTS HERE------//
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef long double LD;

#define MP make_pair
#define PB push_back
#define hash __hash__
#define left __left__
#define right __right__
#define link __link__
#define div __div__
#define next __next__
#define y0 y1005000
#define y1 y1005001
#define F first
#define S second
//-----TEMPLATE ENDS HERE------//
//--ACTUAL SOLUTION IS BELOW---//

const int N = 1000 * 1000 + 10;

int get(int n)
{
    int res = 0;
    while (n)
    {
        res = max(res, n % 10);
        n /= 10;
    }
    return res;
}

const LL INF = (LL)1e18;
int mx[N];
LL dp[N][10];
LL neg[N][10];

LL work(LL n)
{
    if (n == 0)
        return 0;
    if (n < 1000 * 1000)
        return work(n - mx[n]) + 1;
    LL div = n / (1000 * 1000);
    LL mod = n % (1000 * 1000);
    LL add = dp[mod][mx[div]];
    return work(div * 1000ll * 1000 + neg[mod][mx[div]]) + add;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    mx[0] = 0;
    for (int i = 1; i < N; i++)
        mx[i] = get(i);
    for (int i = 0; i < N; i++)
        for (int j = 1; j < 10; j++)
        {
            dp[i][j] = INF;
            int d = max(j, mx[i]);
            int to = i - d;
            if (to < 0)
            {
                dp[i][j] = 1;
                neg[i][j] = to;
            }
            else
            {
                dp[i][j] = dp[to][j] + 1;
                neg[i][j] = neg[to][j];
            }
        }

    LL n;
    cin >> n;
    cout << work(n);

    return 0;
}
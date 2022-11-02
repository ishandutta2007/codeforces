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


const int N = 300 * 1000 + 10;

LL sum[N], a[N];
map<LL, LL> dp;


int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    LL res = -1e18;
    int l, r;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + max(0ll, a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (!dp.count(a[i]))
        {
            dp[a[i]] = i - 1;
        }
        else
        {
            LL cur = sum[i] - sum[dp[a[i]]];
            if (a[i] < 0)
                cur += 2 * a[i];
            if (cur > res)
            {
                res = cur;
                r = i;
                l = dp[a[i]] + 1;
            }
        }
    }
    cout << res << " ";
    set<int> good;
    good.insert(l);
    good.insert(r);
    for (int i = 1; i <= n; i++)
        if (a[i] >= 0 && l <= i && i <= r)
            good.insert(i);
    cout << n - good.size() << endl;
    for (int i = 1; i <= n; i++)
        if (!good.count(i))
            cout << i << " ";

    return 0;
}
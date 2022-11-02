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


map<PLL, PLL> was;

PLL dp(LL d, LL n)
{
    PLL key(d, n);
    PLL res(0, 0);
    if (n == 0)
        return res;
    if (n < 10)
    {
        res.F++;
        res.S = min(n - d, 0ll);
        return res;
    }
    if (was.count(key))
        return was[key];
    while (n > 0)
    {
        LL p = 1;
        while (p <= n / 10)
            p *= 10;
        LL dd = max(d, n / p);
        LL mod = n % p;
        PLL go = dp(dd, mod);
        res.F += go.F;
        n -= mod;
        n += go.S;
        if (go.S == 0)
        {
            res.F++;
            n -= dd;
        }
    }
    res.S = n;
    was[key] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    LL n;
    cin >> n;
    cout << dp(0, n).F;

    return 0;
}
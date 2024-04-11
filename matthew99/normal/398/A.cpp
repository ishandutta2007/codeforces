#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <bitset>
#include <iostream>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

template<typename T> bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

const int maxn = 100000;

int n, m;
    
int main()
{
#ifndef ONLINE_JUDGE
    freopen("soccer.in", "r", stdin);
    freopen("soccer.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    if (!n)
    {
        cout << -(LL)m * m << endl;
        REP(i, 0, m) printf("x");
        return 0;
    }
    else if (!m)
    {
        cout << (LL)n * n << endl;
        REP(i, 0, n) printf("o");
        return 0;
    }
    LL ans = -0x3f3f3f3f3f3f3f3fLL;
    int best = 1, bestlyc = -1;
    REP(i, 1, min(n, m) + 1)
    {
        int lyc = m / (i + 1);
        int zxo = m % (i + 1);
        LL tmp = (LL)lyc * lyc * (i + 1 - zxo) + (LL)(lyc + 1) * (lyc + 1) * zxo;
        LL tmp0 = LL(n - i + 1) * (n - i + 1) + (i - 1);
        if (chkmax(ans, tmp0 - tmp)) best = i, bestlyc = lyc;
        else if (tmp0 - tmp == ans)
        {
            if (chkmin(bestlyc, lyc)) best = i;
        }
    }
    cout << ans << endl;
    int lyc = m / (best + 1), zxo = m % (best + 1);
    REP(i, 0, best << 1 | 1)
    {
        if (i & 1)
        {
            if (i == 1) REP(j, 0, n - best + 1) printf("o");
            else printf("o");
        }
        else
        {
            REP(j, 0, lyc + (best - (i >> 1) < zxo)) printf("x");
        }
    }
    return 0;
}
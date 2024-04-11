#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf64 / 100 + 7;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}
int sign(LD x) {return (x >= 0?1 : -1);}

using namespace std;

bool solve()
{   
    LL n, m, c1, c2;

    cin >> n >> m;

    LL ans = 0, tmp = -inf64;

    for(int i(0);i <= n;i++)
    {
        ans = min((LL)i, m / 2);

        LL tn = n - ans;
        LL tm = m - 2 * ans;

        ans += min(tm, tn / 2);

        tmp = max(tmp, ans);
    }

    cout << tmp << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}
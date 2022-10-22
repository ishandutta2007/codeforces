#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    int n, m;

    cin >> n >> m;

    vec<LL> v(n);
    LL ans = 0;

    for(int i(0);i < n;i++) cin >> v[i];

    for(int x, y, i(0);i < m;i++)
    {
        cin >> x >> y;
        x--, y--;
        ans += min(v[x], v[y]);
    }

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}
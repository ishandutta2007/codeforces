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
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}

using namespace std;

bool solve()
{
    LL n, l;

    cin >> n >> l;

    vec<LL> a(n + 2);
    a[0] = 0;
    a[n + 1] = l;

    for(int i(1);i <= n;i++) cin >> a[i];

    sort(ALL(a));

    LD ans = max(a[1], a[n + 1] - a[n]);

    for(int i(2);i <= n;i++)
        ans = max(ans, LD(a[i] - a[i - 1]) / 2.0);
    
    cout.precision(25);
    cout << fixed;

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}
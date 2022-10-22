#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <queue>
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
int sign(LD x) {return (x >= 0?1 : -1);}

using namespace std;

bool solve()
{
    int n;

    cin >> n;

    vec< pair<LL, LL> > a(n + 1);
    LL sum = 0;

    for(int i(1);i <= n;i++) cin >> a[i].first >> a[i].second, sum += a[i].first;

    vec<LL> mx(n + 2, -inf64);

    mx[n] = a[n].second;
    for(int i(n - 1);i >= 1;i--) mx[i] = max(a[i].second, mx[i + 1]);

    LL tmp = -inf64;

    for(int i(1);i <= n;i++)
    {
        cout << (sum - a[i].first) * (max(tmp, mx[i + 1])) << ' ';
        tmp = max(tmp, a[i].second);
    }

    return true;
}

int main()
{
    //while(solve());
    solve();
    
    return 0;
}
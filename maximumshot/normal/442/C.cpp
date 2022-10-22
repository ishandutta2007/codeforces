#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>

#define vec vector
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    int n;

    cin >> n;

    vec<int> a(n), l(n, -1), r(n, -1);
    vec<bool> can(n, 1);
    vec< pair<int, int> > b(n);

    for(int i(0);i < n;i++) cin >> a[i], b[i] = mp(a[i], i);
    sort(ALL(b));

    for(int i(1);i < n;i++) l[i] = i - 1;
    for(int i(0);i < n - 1;i++) r[i] = i + 1;

    int u, d;
    d = 0, u = n - 1;
    LL ans = 0;

    for(int i(0);i < n - 2;i++)
    {
        if(b[i].second == d) ans += b[i].first, d = r[d];
        else if(b[i].second == u) ans += b[i].first, u = l[u];
        else
        {
            ans += min(a[l[b[i].second]], a[r[b[i].second]]);
            r[l[b[i].second]] = r[b[i].second];
            l[r[b[i].second]] = l[b[i].second];
        }
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
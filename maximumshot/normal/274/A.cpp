#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <cmath>
#include <map>
#include <set>

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

map<LL, bool> g, used;
LL cnt, n, k;

void dfs(LL v)
{
    used[v] = 1;
    cnt++;
    if(g[k * v] && !used[k * v]) dfs(k * v);
}

bool solve()
{
    cin >> n >> k;

    vec<LL> a(n);

    for(int i(0);i < n;i++) cin >> a[i], g[a[i]] = 1;
    sort(ALL(a));

    LL ans = 0;

    for(int i(0);i < n;i++)
    {
        cnt = 0;
        if(!used[a[i]]) dfs(a[i]);
        ans += cnt / 2 + cnt % 2;
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
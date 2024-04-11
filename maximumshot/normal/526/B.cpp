#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

int n;
vec<int> a;
vec<LL> cnt;
LL ans = 0;

bool is_leafe(int x)
{
    return ((1ll << n) <= x && x < (1ll << (n + 1)));
}

void dfs(int v)
{
    if(is_leafe(v)) cnt[v] = 0;
    else {
        int x, y;
        x = v << 1;
        y = v << 1 | 1;
        dfs(x);
        dfs(y);
        LL CountLeft, CountRight;
        CountLeft = cnt[x] + a[x];
        CountRight = cnt[y] + a[y];
        cnt[v] = max(CountLeft, CountRight);
        ans += (CountLeft >= CountRight?CountLeft - CountRight : CountRight - CountLeft);
        //cout << v << ' ' << "{" << CountLeft << ", " << CountRight << " }\n";
    }
}

bool solve()
{
    scanf("%d", &n);

    a.resize((1ll << (n + 1)), 0);
    cnt.resize((1ll << (n + 1)), 0);

    for(int i(2);i < (1ll << (n + 1));i++)
        scanf("%d", &a[i]);

    dfs(1);

    printf("%I64d\n", ans);

    return true;
}   

int main()
{
    //while(solve());
    solve();

    return 0;
}
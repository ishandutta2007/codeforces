#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

const LL N = 100100;

bool solve()
{
    LL n, m, b;

    cin >> n >> m >> b;
    
    vec< pair< pair<LL, LL>, pair<LL, LL> > > f(n); 

    for(int i(0);i < n;i++)
    {
        cin >> f[i].first.second >> f[i].first.first >> f[i].second.first;
        f[i].second.second = 0;
        for(LL x, j(0);j < f[i].second.first;j++)
        {
            cin >> x;
            f[i].second.second |= (1 << (x - 1));
        }
    }

    sort(ALL(f));

    vec< LL > dp(1ll << m, inf64 * 4);
    dp[0] = 0;

    LL ans = inf64 * 4;

    for(int i(0);i < n;i++)
    {
        for(int j(0);j < (1 << m);j++)
        {
            if(dp[j] + f[i].first.second < dp[j | f[i].second.second])
                dp[j | f[i].second.second] = dp[j] + f[i].first.second;
            LL tmp = dp[(1 << m) - 1] + f[i].first.first * b;
            ans = min(ans, tmp);
        }
    }

    cout << (ans == inf64 * 4? -1 : ans) << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}
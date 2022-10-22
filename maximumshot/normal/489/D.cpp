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

bool solve()
{
    int n, m;

    cin >> n >> m;

    vec< vec<int> > g(n);
    vec<int> cnt;

    LL ans = 0;

    for(int a, b, i(0);i < m;i++)
    {
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }

    for(int i(0);i < n;i++)
    {
        cnt.assign(n, 0);
        
        for(int j(0);j < (int)g[i].size();j++)
            for(int z(0);z < (int)g[g[i][j]].size();z++)
                if(g[g[i][j]][z] != i) cnt[g[g[i][j]][z]]++;
        
        for(int j(0);j < n;j++)
            ans += cnt[j] * (cnt[j] - 1);
    }

    cout << ans / 2 << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}
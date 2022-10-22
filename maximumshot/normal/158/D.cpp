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
    int n;

    cin >> n;

    LL tmp, ans = 0;

    vec<LL> t(n);

    for(int i(0);i < n;i++) cin >> t[i], ans += t[i];

    for(int i(3);i <= n;i++)
    {
        if(n % i) continue;
        for(int j(0);j < n / i;j++)
        {
            tmp = 0;
            for(int z(j);z < n; z += n / i)
                tmp += t[z];
            ans = max(ans, tmp);
        }
    }

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve()) {}
    solve();

    return 0;
}
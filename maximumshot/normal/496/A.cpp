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

bool solve()
{
    LL n, ans = inf64, tmp;

    cin >> n;

    vec<LL> a(n);

    for(int i(0);i < n;i++) cin >> a[i];

    for(int i(1);i < n - 1;i++)
    {
        tmp = 0;

        for(int j(0);j < n - 1;j++)
        {
            if(j + 1 == i) tmp = max(tmp, a[j + 2] - a[j]), j++;
            else tmp = max(tmp, a[j + 1] - a[j]);
        }
        ans = min(ans, tmp);
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
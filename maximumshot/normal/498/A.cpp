// by maximumSHOT
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
const LL base = inf / 10ll;

bool solve()
{
    LL x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int n;

    cin >> n;

    vec< pair<LL, pair<LL, LL> > > p(n);

    for(int i(0);i < n;i++) cin >> p[i].first >> p[i].second.first >> p[i].second.second;

    int ans = 0;

    for(int i(0);i < n;i++)
    {
        LL a, b, c;

        a = p[i].first;
        b = p[i].second.first;
        c = p[i].second.second;

        if(a * x1 + b * y1 + c > 0 && a * x2 + b * y2 + c < 0) ans++;
        else if(a * x1 + b * y1 + c < 0 && a * x2 + b * y2 + c > 0) ans++;
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
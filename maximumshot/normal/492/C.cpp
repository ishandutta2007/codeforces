#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    LL n, r, avg, sum = 0;

    cin >> n >> r >> avg;

    vec< pair<LL, LL> > a(n);
    
    for(int i(0);i < n;i++) cin >> a[i].second >> a[i].first, sum += a[i].second;

    sort(ALL(a));

    LL ans = 0;

    for(int i(0);i < n && sum < n * avg;i++)
    {
        ans += a[i].first * min(n * avg - sum, r - a[i].second);
        sum += min(n * avg - sum, r - a[i].second); 
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
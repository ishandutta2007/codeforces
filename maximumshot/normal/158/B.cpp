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

    vec<int> cnt(5, 0);

    for(int x, i(0);i < n;i++) cin >> x, cnt[x]++;

    int ans = cnt[4];

    ans += cnt[3];

    cnt[1] = max(0, cnt[1] - cnt[3]);

    ans += cnt[2] / 2;
    cnt[2] %= 2;

    if(cnt[2]) ans++, cnt[1] = max(0, cnt[1] - 2 * cnt[2]);

    ans += (cnt[1] / 4) + (cnt[1] % 4 != 0);

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve()) {}
    solve();

    return 0;
}
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

bool solve()
{
    LL a, b;

    cin >> a >> b;

    LL ans = 0;

    while(a > 0 && b > 0)
    {
        ans += a / b;
        a %= b;
        if(a <= b) swap(a, b);
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
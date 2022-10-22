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
typedef long double LD;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    LL a, b, c, ans = 0;

    cin >> a >> b;

    if(a == b) {cout << "infinity"; return true;}
    if(a < b) {cout << 0 << '\n'; return true;}

    c = a - b;

    for(LL i(1);i * i <= c;i++)
    {
        if(c % i) continue;

        LL x = c / i;

        if(a % i == b) ans++;
        if(a % x == b && x != i) ans++;
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
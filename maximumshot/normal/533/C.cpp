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

bool solve()
{
    int xp, yp, xv, yv;

    cin >> xp >> yp >> xv >> yv;

    if(xp == xv)
    {
        if(yp < yv) puts("Polycarp");
        else puts("Vasiliy");
    }else if(yp == yv)
    {
        if(xp < xv) puts("Polycarp");
        else puts("Vasiliy");
    }else if(xp < xv && yp < yv)
        puts("Polycarp");
    else if(xv < xp && yv < yp)
        puts("Vasiliy");
    else
    {
        int sp = xp + yp;
        int sv = max(xv, yv);

        if(sp <= sv) puts("Polycarp");
        else puts("Vasiliy");
    }

    return true;
}   

int main()
{
    //while(solve());
    solve();

    return 0;
}
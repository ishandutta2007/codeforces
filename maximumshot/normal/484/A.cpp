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
#include <stdio.h>
 
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
 
LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    LL n, l, r, x;

    cin >> n;

    while(n--)
    {
        cin >> l >> r;

        x = l;

        for(int i(0);i < 63;i++)
        {
            LL tmp = 1ll << i;
            if(tmp & x) continue;
            if((x | tmp) <= r) x |= tmp;
        }

        cout << x << '\n';
    }

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}
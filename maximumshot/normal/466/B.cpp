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
    LL n, a, b, ans = -1, ansa, ansb;
    
    cin >> n >> a >> b;

    if(a * b >= 6ll * n) {cout << a * b << '\n' << a << ' ' << b << '\n'; return true;}

    bool f = 0;

    if(a > b) f = 1, swap(a, b);

    for(LL i(a);i * i <= 6 * n;i++)
    {
        LL j = 6ll * n / i + (6ll * n % i != 0);
        if(j < b) continue;
        if(ans == -1 || ans > i * j) ans = i * j, ansa = i, ansb = j;
    }

    if(f) swap(ansa, ansb);

    cout << ans << '\n' << ansa << ' ' << ansb << '\n';

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}
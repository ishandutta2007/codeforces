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
    LL n, S = 0;

    cin >> n;

    vec<LL> a(n), preff(n), suff(n);

    for(int i(0);i < n;i++) cin >> a[i], S += a[i];

    if(S % 3) {cout << 0 << '\n'; return true;} 
    S /= 3;

    preff[0] = a[0];
    for(int i(1);i < n;i++) preff[i] = preff[i - 1] + a[i];
    
    suff[n - 1] = a[n - 1];
    for(int i(n - 2);i >= 0;i--) suff[i] = suff[i + 1] + a[i];

    vec<LL> r(n);

    r[n - 1] = (a[n - 1] == S);
    for(int i(n - 2);i >= 0;i--) r[i] = r[i + 1] + (suff[i] == S);

    LL ans = 0;

    for(int i(0);i < n - 2;i++)
    {
        if(preff[i] != S) continue;
        ans += r[i + 2];
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
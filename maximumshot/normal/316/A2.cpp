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
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    string a;

    cin >> a;

    vec<int> is(26);

    int n = (int)a.size();
    
    for(int i(0);i < n;i++) if(a[i] >= 'A' && a[i] <= 'Z')is[a[i] - 'A'] = 1;

    int cnt = count(ALL(is), 1), cnt2 = count(ALL(a), '?');
    bool f = 0, q = 0;

    if(cnt > 10) {cout << 0 << '\n'; return true;}

    LL ans = (a[0] == '?' || (a[0] >= 'A' && a[0] <= 'Z')?9 : 1), start = 10;
    f = (a[0] >= 'A' && a[0] <= 'Z');
    q = (a[0] == '?');
    cnt -= f;
    cnt2 -= q;

    if(f) start--;

    for(start;cnt;cnt--, start--) ans *= start;

    cout << ans;

    for(int i(0);i < cnt2;i++) cout << 0;

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}
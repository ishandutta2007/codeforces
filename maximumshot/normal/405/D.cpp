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
    int n;
    vec<int> ans, a, b;
    
    vec<bool> is(1000100, false), was(1000100, false), t(1000100, false);

    scanf("%d", &n);

    a.resize(n);

    for(int i(0);i < n;i++) scanf("%d", &a[i]), is[a[i]] = was[a[i]] = 1;

    for(int i(1);i <= 1000000;i++)
        if(!is[i] && !is[1000000 - i + 1]) b.push_back(i), b.push_back(1000000 - i + 1), is[i] = is[1000000 - i + 1] = 1;

    reverse(ALL(b));

    for(int i(0);i < n;i++)
    {
        if(t[a[i]]) continue;
        if(!was[1000000 - a[i] + 1]) ans.push_back(1000000 - a[i] + 1), t[a[i]] = 1;
        else
        {
            ans.push_back(b.back());
            b.pop_back();
            ans.push_back(b.back());
            b.pop_back();
            t[1000000 - a[i] + 1] = 1;
        }
    }

    printf("%d\n", (int)ans.size());

    for(int i(0);i < (int)ans.size();i++) printf("%d ", ans[i]);

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}
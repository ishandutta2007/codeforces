#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

LL Abs (LL x) {return (x >= 0ll?x : -x);};

bool solve()
{
    int n, k;
    LL ans = -inf64;

    cin >> n >> k;
    
    vec<int> a(n);

    for(int i(0);i < n;i++) cin >> a[i];

    for(int i(0);i < n;i++)
    {
        for(int j(i);j < n;j++)
        {
            int l, r;
            LL sum = 0;
            vec<int> ta, tb;

            l = i;
            r = j;

            for(int z(l);z <= r;z++) sum += a[z], ta.push_back(a[z]);
            for(int z(0);z < l;z++) tb.push_back(a[z]);
            for(int z(r + 1);z < n;z++) tb.push_back(a[z]);

            sort(ALL(ta));
            sort(ALL(tb));

            int cnt = k, sa = (int)ta.size(), sb = (int)tb.size();

            l = 0;
            r = sb - 1;

            while(cnt-- && l < sa && r >= 0 && ta[l] < tb[r]) sum = sum - ta[l] + tb[r], l++, r--;

            ans = max(ans, sum);
        }
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
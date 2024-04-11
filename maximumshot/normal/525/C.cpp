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
    int n;

    scanf("%d", &n);

    vec<int> a(n);
    vec<LL> c(1e6 + 10, 0), c2(1e6 + 10);

    for(int i(0);i < n;i++)
    {
        scanf("%d", &a[i]);
        c[a[i]]++;
    }

    for(int i(1e6);i >= 2;i--)
    {
        if((c[i] + c2[i]) % 2 == 0) continue;
        if(c[i]) c2[i - 1]++, c[i]--;
    }
    for(int i(1);i <= 1e6;i++)
    {
        c[i] += c2[i];
        if(c[i] % 2) c[i]--;
    }

    LL ans = 0;
    a.clear();
    
    for(int i(1);i <= 1e6;i++)
    {
        for(int j(0);j < c[i] / 2;j++)
            a.push_back(i);
    }

    for(int i((int)a.size() - 1);i >= 1;i -= 2)
    {
        LL x = a[i];
        LL y = a[i - 1];
        ans += x * y;
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
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
typedef pair<int, int> pii;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

bool solve()
{
    int n, k, q, sz = -1, x;

    scanf("%d%d", &n, &k);

    vec<int> a(n), is;
    for(int i(0);i < n;i++) scanf("%d", &a[i]), sz = max(sz, a[i] + 1);

    is.resize(sz);
    for(int i(0);i < n;i++) is[a[i]] = 1;

    scanf("%d", &q);

    while(q--)
    {
        scanf("%d", &x);

        int ans = inf;

        for(int k1(1);k1 <= k;k1++)
        {
            for(int i(0);i < n;i++)
            {
                LL sum = a[i] * k1;
                if(sum > x) continue;
                if(sum == x) ans = min(ans, k1);
                else
                {
                    sum = x - sum;
                    for(int k2(1);k1 + k2 <= k;k2++)
                    {
                        if(sum % k2) continue;
                        sum /= k2;
                        if(sum >= 0 && sum < (int)is.size() && is[sum]) ans = min(ans, k1 + k2);
                        sum *= k2;
                    }
                }
            }
        }

        if(ans != inf) printf("%d\n", ans);
        else puts("-1");
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}
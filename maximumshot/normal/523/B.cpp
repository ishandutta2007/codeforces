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

LD my_abs(LD x)
{
    return (x >= 0.0?x : -x);
}

bool solve()
{
    int n, t;
    LD c;

    scanf("%d %d %Lf", &n, &t, &c);

    vec< LL > a(n + 2), sum(n + 1);

    for(int i(1);i <= n;i++) scanf("%I64d", &a[i]);
    for(int i(1);i <= n;i++) sum[i] = sum[i - 1] + a[i];
    
    vec<LD> ans(n + 1);

    for(int i(1);i <= n;i++) ans[i] = (ans[i - 1] + (LD)a[i] / (LD)t) / (LD)c;

    int m;

    scanf("%d", &m);

    for(int i(0);i < m;i++)
    {
        int q;
        scanf("%d", &q);

        LD approax, real, error;

        real = LD(sum[q] - sum[q - t]) / (LD)t;
        approax = ans[q];
        error = fabs(approax - real) / real;
        printf("%.6Lf %.6Lf %.6Lf\n", real, approax, error);
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}
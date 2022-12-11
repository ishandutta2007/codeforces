//
//  main.cpp
//  Time to Raid Cowavans
//
//  Created by Sokol Kostya's MacBook on 30.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

struct Tquery
{
    int a, b, num;
    Tquery()
    {
        a = b = num = -1;
    }
};

bool cmp(Tquery q1, Tquery q2)
{
    if (q1.b < q2.b) return true;
    return false;
}

Tquery qq[333333];

int n, m, mx = 540;
long long f[333333], ans, aa[333333], out[333333];

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &aa[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        qq[i].a = a;
        qq[i].b = b;
        qq[i].num = i;
    }
    sort(qq + 1, qq + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int ii = qq[i].num;
        int a = qq[i].a;
        int b = qq[i].b;
        if (b >= mx)
        {
            ans = 0;
            for (int j = a; j <= n; j += b) ans += aa[j];
            out[ii] = ans;
            continue;
        }
        if (b != qq[i - 1].b)
        {
            for (int j = n; j > 0; j--)
            {
                f[j] = aa[j];
                if (j + b <= n) f[j] += f[j + b];
            }
        }
        out[ii] = f[a];
    }
    for (int i = 1; i <= m; i++) printf("%I64d\n", out[i]);
    return 0;
}
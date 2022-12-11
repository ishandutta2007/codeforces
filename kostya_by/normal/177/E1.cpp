//
//  main.cpp
//  task5
//
//  Created by Sokol Kostya's MacBook on 21.04.11.
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
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int a[11111], b[11111], n, c;
ull ll1, rr1;

ull fun(ull x)
{
    ull res = n;
    for (int i = 0; i < n; i++)
    {
        ull aa = a[i];
        ull bb = b[i];
        res += (aa * x) / bb;
    }
    return res;
}

void bin1(ull ll, ull rr)
{
    if (ll > rr) return;
    ull xx = (ll + rr) / 2;
    if (fun(xx) <= c)
    {
        rr1 = max(rr1, xx);
        bin1(xx + 1, rr);
    } else bin1(ll, xx - 1);
}

void bin2(ull ll, ull rr)
{
    if (ll > rr) return;
    ull xx = (ll + rr) / 2;
    if (fun(xx) >= c)
    {
        ll1 = min(ll1, xx);
        bin2(ll, xx - 1);
    } else bin2(xx + 1, rr);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
    rr1 = 0;
    ull lim = 1e10;
    bin1(1, lim);
    ll1 = lim;
    bin2(1, lim);
    if (ll1 == 1 && rr1 == lim)
    {
        cout << -1;
        return 0;
    }
    cout << rr1 - ll1 + 1;
    return 0;
}
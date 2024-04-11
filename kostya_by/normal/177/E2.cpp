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
ull ll1, rr1, cc;

bool check(ull a, ull b)
{
    double l1 = log10( 1.0 * a );
    double l2 = log10( 1.0 * b );
    double l3 = log10( 1e18 + 1e18 );
    if (l1 + l2 > l3) return true;
    return false;
}

ull fun(ull x)
{
    ull res = n;
    for (int i = 0; i < n; i++)
    {
        ull aa = a[i];
        if (aa == 0) continue;
        ull bb = b[i];
        if ( check( aa, x ) == true ) return (inf);
        res += (aa * x) / bb;
        if (res > cc) return (inf);
    }
    return res;
}

void bin1(ull ll, ull rr)
{
    if (ll > rr) return;
    ull xx = (ll + rr) / 2;
    if (fun(xx) <= cc)
    {
        rr1 = max(rr1, xx);
        bin1(xx + 1, rr);
    } else bin1(ll, xx - 1);
}

void bin2(ull ll, ull rr)
{
    if (ll > rr) return;
    ull xx = (ll + rr) / 2;
    if (fun(xx) >= cc)
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
    cc = c;
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
    bool fl = true;
    for (int i = 0; i < n; i++) if (a[i] != 0) fl = false;
    if (fl == true && c == n)
    {
        cout << -1;
        return 0;
    }
    if (fl == true && c != n)
    {
        cout << 0;
        return 0;
    }
    if (c < n)
    {
        cout << 0;
        return 0;
    }
    rr1 = 0;
    ull lim = 1e18 + 1e17;
    bin1(1, lim);
    ll1 = lim;
    bin2(1, lim);
    ull nl = 0;
    ull res = max( rr1 - ll1 + 1, nl );
    
    cout << res;
    return 0;
}
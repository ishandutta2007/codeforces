//
//  main.cpp
//  lift
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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

int s, f, t, n, m, xx, res1, res2, tt;

bool fun1(int x)
{
    long long st = xx - 1;
    long long aa = x;
    long long bb = 2 * m - 2;
    st += aa * bb;
    if (st >= tt) return true;
    return false;
}

void find1(int ll, int rr)
{
    if (ll > rr) return;
    int xx = (ll + rr) / 2;
    if (fun1(xx) == true) 
    {
        res1 = min(res1, xx);
        find1(ll, xx - 1);
    } else find1(xx + 1, rr);
}

bool fun2(int x)
{
    long long st = m - 1 + (m - xx);
    long long aa = x;
    long long bb = 2 * m - 2;
    st += aa * bb;
    if (st >= tt) return true;
    return false;
}

void find2(int ll, int rr)
{
    if (ll > rr) return;
    int xx = (ll + rr) / 2;
    if (fun2(xx) == true) 
    {
        res2 = min(res2, xx);
        find2(ll, xx - 1);
    } else find2(xx + 1, rr);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &s, &f, &t);
        if (s == f)
        {
            printf("%d\n", t);
            continue;
        }
        xx = s;
        tt = t;
        res1 = 1000000000;
        find1(0, 1000000000);
        res2 = 1000000000;
        find2(0, 1000000000);
       // cout << res1 << " " << res2 << endl;
        long long t1 = 1ll * (s - 1 + res1 * (2 * m - 2 )); 
        long long t2 = 1ll * (m - 1 + (m - s) + res2 * (2 * m - 2));
        tt = min( t1, t2 );
       // cout << tt << " - ";
        xx = f;
        res1 = 1000000000;
        find1(0, 1000000000);
        res2 = 1000000000;
        find2(0, 1000000000);
        t1 = 1ll * (f - 1 + res1 * (2 * m - 2 )); 
        t2 = 1ll * (m - 1 + (m - f) + res2 * (2 * m - 2));
        tt = min( t1, t2 );
        printf("%d\n", tt);
    }
    return 0;
}
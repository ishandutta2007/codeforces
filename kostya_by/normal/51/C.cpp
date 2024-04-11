//
//  main.cpp
//  three_base_stations
//
//  Created by Sokol Kostya's MacBook on 08.02.11.
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

const long double eps = 1e-7;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, a[211111];
bool used[211111];
double ans = 1000000000, xx1, xx2, xx3;

bool ok(double xx)
{
    for (int i = 0; i < n; i++) used[i] = false;
    double x1 = a[0] + xx;
    int ii = -1;
    for (int i = 0; i < n; i++)
    {
        if (fabs(x1 - a[i]) < xx + eps) used[i] = true;
        if (used[i] == false && ii == -1) ii = i;
    }
    if (ii == -1)
    {
        if (xx < ans)
        {
            ans = xx;
            xx1 = x1;
            xx2 = 0;
            xx3 = 0;
        }
        return true;
    }
    double x2 = a[ii] + xx;
    ii = -1;
    for (int i = 0; i < n; i++)
    {
        if (fabs(x2 - a[i]) < xx + eps) used[i] = true;
        if (used[i] == false && ii == -1) ii = i;
    }
    if (ii == -1)
    {
        if (xx < ans)
        {
            ans = xx;
            xx1 = x1;
            xx2 = x2;
            xx3 = 0;
        }
        return true;
    }
    double x3 = a[ii] + xx;
    ii = -1;
    ii = -1;
    for (int i = 0; i < n; i++)
    {
        if (fabs(x3 - a[i]) < xx + eps) used[i] = true;
        if (used[i] == false && ii == -1) ii = i;
    }
    if (ii == -1)
    {
        if (xx < ans)
        {
            ans = xx;
            xx1 = x1;
            xx2 = x2;
            xx3 = x3;
        }
        return true;
    }
  //  cout << x1 << " " << x2 << " " << x3 << endl;
    return false;
}

void findf(double ll, double rr)
{
    if (rr - ll < eps) return;
    double xx = 1.0 * (ll + rr) / 2;
    if (ok(xx))
    {
        findf(ll, xx);
    } else findf(xx, rr);
}

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    findf(0, 1000000000);
    cout << fixed << setprecision(6) << ans << endl;
    cout << fixed << setprecision(6) << xx1 << " " << xx2 << " " << xx3 << endl; 
    return 0;
}
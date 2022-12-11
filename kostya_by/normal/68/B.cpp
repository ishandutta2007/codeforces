//
//  main.cpp
//  energy
//
//  Created by Sokol Kostya's MacBook on 30.05.11.
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

const long double eps = 1e-7;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, k, a[11111];
double ans = 0;

bool fun(double val)
{
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (1.0 * a[i] > val)
        {
            sum1 += (1 - 1.0 * k / 100) * (a[i] - val);
        } else sum2 += val - a[i];
    }
    if (sum1 >= sum2) return true;
    return false;
}

void bin(double ll, double rr)
{
    if (ll + eps > rr)
    {
        ans = 1.0 * (ll + rr) / 2;
        return;
    }
    double xx = 1.0 * (ll + rr) / 2;
    if (fun(xx) == true) bin(xx, rr); else bin(ll, xx);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    bin(0.0, 1000.0);
    cout << fixed << setprecision(7) << ans;
    return 0;
}
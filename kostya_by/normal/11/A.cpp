//
//  main.cpp
//  rising sequence
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

int n, ii;
long long d, a[2222];
long long ans = 0, cur;

void find(long long ll, long long rr)
{
    if (ll > rr) return;
    long long xx = (ll + rr) / 2;
    if (a[ii - 1] < a[ii] + d * xx)
    {
        cur = min(cur, xx);
        find(ll, xx - 1);
    } else find(xx + 1, rr);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1]) continue;
        cur = 1e10;
        ii = i;
        find(1, cur);
        a[i] += cur * d;
        ans += cur;
    }
    cout << ans;
    return 0;
}
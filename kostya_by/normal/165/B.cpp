//
//  main.cpp
//  night_work
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

long long n, k, ans;

long long fun(long long x)
{
    long long xx = x, kk = 1, res = 0;
    while (xx / kk > 0)
    {
        res += xx / kk;
        kk *= k;
    }
    return res;
}

void find(int l, int r)
{
    if (l > r) return;
    int x = (l + r) / 2;
    if (fun(x) >= n)
    {
        ans = min(ans, 1ll * x);
        find(l, x - 1);
    } else find(x + 1, r);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    ans = n;
    find( 1, n - 1 );
    cout << ans;
    return 0;
}
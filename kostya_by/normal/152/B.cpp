//
//  main.cpp
//  steps
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

int n, m, xc, yc, k, dx, dy, cur = 0;
long long ans = 0;

bool fun(int x)
{
    long long xx = x;
    long long ddx = dx;
    long long ddy = dy;
    long long nn = n;
    long long mm = m;
    long long xxc = xc;
    long long yyc = yc;
    if (xxc + ddx * xx < 1 || xxc + ddx * xx > nn) return false;
    if (yyc + ddy * xx < 1 || yyc + ddy * xx > mm) return false;
    return true;
}

void find(int ll, int rr)
{
    if (ll > rr) return;
    int xx = (ll + rr) / 2;
    if (fun(xx) == true) { find(xx + 1, rr); cur = max( xx, cur) ; } else find(ll, xx - 1);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> xc >> yc;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &dx, &dy);
        cur = 0;
        find(1, 1000000000);
        ans += 1ll * cur;
        xc += dx * cur;
        yc += dy * cur;
    }
    cout << ans;
    return 0;
}
//
//  main.cpp
//  pete and divisors
//
//  Created by Sokol Kostya's MacBook on 25.01.11.
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

int last[111111], n, x, y, ans;

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        ans = 0;
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j != 0) continue;
            if (last[j] < i - y) ++ans;
            if (last[x / j] < i - y && j != x / j) ++ans;
            last[j] = last[x / j] = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
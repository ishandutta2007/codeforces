//
//  main.cpp
//  trees
//
//  Created by Sokol Kostya's MacBook on 07.01.11.
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


typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int a[1000000], n, val[1000000];

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        int ii;
        if (i <= n / 2) ii = i; else ii = n - i + 1;
        a[i] -= ii - 1;
        if (a[i] <= 0) continue;
        val[a[i]]++;
    }
    int ans = n;
    for (int i = 0; i < 1000000; i++)
    {
        int now = n - val[i];
        ans = min(ans, now);
    };
    cout << ans;
    return 0;
}
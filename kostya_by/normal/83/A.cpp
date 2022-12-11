//
//  main.cpp
//  magical array
//
//  Created by Sokol Kostya's MacBook on 13.05.11.
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

int n, a[111111], f[111111];
long long ans = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] == a[i]) f[i] = f[i - 1]; else f[i] = i;
        long long a = f[i];
        ans += 1ll * i - a + 1;
    }
    cout << ans + 1;
    return 0;
}
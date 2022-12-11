//
//  main.cpp
//  sled
//
//  Created by Sokol Kostya's MacBook on 28.04.11.
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

int n, r[1111];
double ans = 0;

int main (int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> r[i];
    sort( r, r + n, greater<int>() );
    for (int i = 0; i < n; i++)
    {
        double cur = 1.0 * pi * r[i] * r[i];
        if (i % 2 == 0) ans += cur; else ans -= cur;
    }
    cout << fixed << setprecision(6) << ans;
    return 0;
}
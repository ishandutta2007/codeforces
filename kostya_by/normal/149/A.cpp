//
//  main.cpp
//  cf106task1
//
//  Created by Sokol Kostya's MacBook on 10.02.11.
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

int f[22][2222], k, a[22];

int main (int argc, const char * argv[])
{
    cin >> k;
    for (int i = 1; i <= 12; i++) cin >> a[i];
    for (int i = 0; i < 22; i++)
        for (int j = 0; j < 2222; j++)
            f[i][j] = -1;
    f[0][0] = 0;
    for (int i = 1; i <= 12; i++)
        for (int j = 0; j < 2222; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j < a[i]) continue;
            int f1 = f[i - 1][j - a[i]];
            if (f1 == -1) continue;
            if (f[i][j] == -1) f[i][j] = f1 + 1;
            f[i][j] = min(f[i][j], f1 + 1);
        }
    int res = -1;
    for (int i = k; i < 2222; i++)
    {
        if (f[12][i] == -1) continue;
        if (res == -1) res = f[12][i];
        res = min(res, f[12][i]);
    }
    cout << res;
    return 0;
}
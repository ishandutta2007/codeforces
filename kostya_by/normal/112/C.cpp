//
//  main.cpp
//  pete and inequiations
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

long long x, y, a[111111], res = 0;
int n;

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n >> x >> y;
    if (y < n)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) a[i] = 1;
    a[n - 1] = y - n + 1;
    for (int i = 0; i < n; i++) res += a[i] * a[i];
    if (res >= x)
    {
        for (int i = 0; i < n; i++) 
        {
            int aa = int(a[i]);
            printf("%d\n", aa);
        }
        return 0;
    }
    cout << -1;
    return 0;
}
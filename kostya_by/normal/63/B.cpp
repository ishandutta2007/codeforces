//
//  main.cpp
//  trainings
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

int a[111], n, k, b[111], ans = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    a[n] = k;
    while (a[0] != k)
    {
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i];
            if (a[i] != a[i + 1]) b[i]++;
        }
        for (int i = 0; i < n; i++) a[i] = b[i];
        ++ans;
    }
    cout << ans;
    return 0;
}
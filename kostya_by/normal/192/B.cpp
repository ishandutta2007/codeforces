//
//  main.cpp
//  walking under rain
//
//  Created by Sokol Kostya's MacBook on 30.05.11.
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

int f[1111], a[1111], n;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[i] = -5000;
        cin >> a[i];
    }
    f[1] = a[1];
    f[2] = min(a[1], a[2]);
    for (int i = 2; i <= n; i++)
    {
        f[i] = min( a[i], max( f[i - 1], f[i - 2] ) );
    }
    cout << f[n];
    return 0;
}
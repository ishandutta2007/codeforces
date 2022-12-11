//
//  main.cpp
//  general coming
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

int a[111], p1, p2, n;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    p1 = 1;
    for (int i = 1; i <= n; i++) if ( a[p1] < a[i] ) p1 = i;
    p2 = n;
    for (int i = n; i >= 1; i--) if ( a[p2] > a[i] ) p2 = i;
    if (p1 < p2)
    {
        cout << p1 - 1 + (n - p2);
        return 0;
    }
    cout << p1 + n - p2 - 2;
    return 0;
}
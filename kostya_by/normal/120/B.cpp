//
//  main.cpp
//  what where when
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

int n, k, a[1111];

int main (int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while ( a[k] == 0 )
    {
        ++k;
        if (k == n + 1) k = 1;
    }
    cout << k;
    return 0;
}
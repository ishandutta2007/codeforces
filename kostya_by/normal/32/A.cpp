//
//  main.cpp
//  razvedka2
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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

int ans = 0, a[1111], n, d;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort( a, a + n );
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] - a[i] <= d) ++ans;
    cout << ans * 2;
    return 0;
}
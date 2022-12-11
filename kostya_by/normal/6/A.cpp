//
//  main.cpp
//  triangle
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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

int a[4], ans = 0; // 0 - impossible, 1 - segment, 2 - triangle

void check(int ii, int kk)
{
    int jj = ii + 1;
    if (a[kk] < a[ii] + a[jj])
    {
        ans = max(ans, 2);
    }
    if (a[kk] == a[ii] + a[jj])
    {
        ans = max(ans, 1);
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    check(0, 2); check(1, 3);
    if (ans == 0) cout << "IMPOSSIBLE";
    if (ans == 1) cout << "SEGMENT";
    if (ans == 2) cout << "TRIANGLE";
    return 0;
}
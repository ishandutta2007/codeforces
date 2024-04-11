//
//  main.cpp
//  homework
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

int n, a, b, arr[2222], x1, x2;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> arr[i];
    x1 = 1000000001;
    int l = 1, r = 1000000000;
    while (l <= r)
    {
        int cur = 0;
        int x = (l + r) / 2;
        for (int i = 0; i < n; i++) if (arr[i] > x) cur++;
        if (cur <= a)
        {
            x1 = min( x1, x );
            r = x - 1;
        } else l = x + 1;
    }
    x2 = 0;
    l = 1, r = 1000000000;
    while (l <= r)
    {
        int cur = 0;
        int x = (l + r) / 2;
        for (int i = 0; i < n; i++) if (arr[i] <= x) cur++;
        if (cur <= b)
        {
            x2 = max( x2, x );
            l = x + 1;
        } else r = x - 1;
    }
    //cout << x1 << " " << x2 << endl;
    cout << max(0, x2 - x1 + 1);
    return 0;
}
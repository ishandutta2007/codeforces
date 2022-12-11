//
//  main.cpp
//  taskB
//
//  Created by Sokol Kostya's MacBook on 04.03.11.
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

int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a, n, ans = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == 1) ++a1;
        if (a == 2) ++a2;
        if (a == 3) ++a3;
        if (a == 4) ++a4;
    }
    ans = a4;
    
    ans += a3;
    a1 -= a3;
    a1 = max(a1, 0);
    
    ans += a2 / 2;
    a2 = a2 % 2;
    ans += a2;
    a1 -= 2 * a2;
    a2 -= a2;
    a1 = max(0, a1);
    
    ans += a1 / 4;
    if (a1 % 4 != 0) ++ans;
    cout << ans;
    return 0;
}
//
//  main.cpp
//  lucky min
//
//  Created by Sokol Kostya's MacBook on 13.05.11.
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

int n, n4 = -1, n7 = -7, c4, c7;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        c4 = i;
        if (n - c4 * 4 < 0) break;
        c7 = n - c4 * 4;
        if (c7 % 7 != 0) continue;
        c7 /= 7;
        if (n4 == -1)
        {
            n4 = c4;
            n7 = c7;
        }
        if (n4 + n7 > c4 + c7)
        {
            n4 = c4;
            n7 = c7;
        }
    }
    if (n4 == -1)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n4; i++) printf("4");
    for (int i = 0; i < n7; i++) printf("7");
    return 0;
}
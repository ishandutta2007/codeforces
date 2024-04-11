//
//  main.cpp
//  random_period
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

int last[111111];
int a, b, m, r;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a >> b >> m >> r;
    last[r] = 1;
    for (int i = 2;; i++)
    {
        r = (a * r + b) % m;
        if (last[r] != 0)
        {
            cout << i - last[r];
            return 0;
        }
        last[r] = i;
    }
    return 0;
}
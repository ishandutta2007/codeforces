//
//  main.cpp
//  plus and xor
//
//  Created by Sokol Kostya's MacBook on 17.03.11.
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

ull x, y, a, b;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a >> b;
    if (a < b || (a - b) % 2 == 1) 
    {
        cout << -1;
        return 0;
    }
    x = (a - b) / 2;
    y = b ^ x;
    if ((x ^ y) == b) cout << x << " " << y; else cout << -1;
    return 0;
}
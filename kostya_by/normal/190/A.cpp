//
//  main.cpp
//  petya and buses
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

int a, b;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a >> b;
    if (b == 0)
    {
        cout << a << " " << a;
        return 0;
    }
    if (a == 0)
    {
        cout << "Impossible";
        return 0;
    }
    int mx = a - 1 + b;
    int mn = a + b - min(b, a);
    cout << mn << " " << mx;
    return 0;
}
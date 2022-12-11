//
//  main.cpp
//  o nulls
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a, b, c, aa = 0, bb = 0, cc = 0;
    vector<int> ca;
    cin >> a >> b;
    c = a + b;
    
    ca.clear();
    while (a > 0)
    {
        if (a % 10 != 0)
        {
            ca.pb( a % 10 );
        }
        a /= 10;
    }
    for (int i = ca.size() - 1; i >= 0; i--) aa = (10 * aa) + ca[i];
    
    ca.clear();
    while (b > 0)
    {
        if (b % 10 != 0)
        {
            ca.pb( b % 10 );
        }
        b /= 10;
    }
    for (int i = ca.size() - 1; i >= 0; i--) bb = (10 * bb) + ca[i];
    
    ca.clear();
    while (c > 0)
    {
        if (c % 10 != 0)
        {
            ca.pb( c % 10 );
        }
        c /= 10;
    }
    for (int i = ca.size() - 1; i >= 0; i--) cc = (10 * cc) + ca[i];
    if (aa + bb == cc) cout << "YES"; else cout << "NO";
    return 0;
}
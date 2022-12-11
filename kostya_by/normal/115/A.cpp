//
//  main.cpp
//  party
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

int n, p[2222], f[2222], mx = 0;

int fun(int x)
{
    if (f[x] != -1) return f[x];
    if (p[x] == -2) f[x] = 1; else f[x] = fun( p[x] ) + 1;
   // cout << f[x] << endl;
    return f[x];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 0; i < 2222; i++) f[i] = -1;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) mx = max( mx, fun(i) );
    cout << mx;
    return 0;
}
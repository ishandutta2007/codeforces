//
//  main.cpp
//  tetraider
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
const int mod = 1000000007;

using namespace std;

int n, f[2][4], ss;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    f[0][0] = 1;
    ss = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[1][0] = (ss - f[0][0] + mod) % mod;
        f[1][1] = (ss - f[0][1] + mod) % mod;
        f[1][2] = f[1][3] = f[1][1];
        ss = f[1][0];
        ss += f[1][1];
        ss %= mod;
        ss += f[1][1];
        ss %= mod;
        ss += f[1][1];
        ss %= mod;
        f[0][0] = f[1][0];
        f[0][1] = f[1][1];
        f[0][2] = f[1][2];
        f[0][3] = f[1][3];
    }
    cout << f[0][0];
    return 0;
}
//
//  main.cpp
//  numbers
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

int n, ans = 0, aa, bb;

int gcd(int a, int b)
{
    if (a != 0) return gcd(b % a, a); else return b;
}

int fun(int x, int base)
{
    int res = 0;
    while (x > 0)
    {
        res += x % base;
        x /= base;
    }
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 2; i < n; i++) ans += fun(n, i);
    aa = ans;
    bb = n - 2;
    int gg = gcd(aa, bb);
    cout << aa / gg << "/" << bb / gg;
    return 0;
}
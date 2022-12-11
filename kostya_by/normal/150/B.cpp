//
//  main.cpp
//  task2_full
//
//  Created by Sokol Kostya's MacBook on 17.02.11.
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
const long long mod = 1000000007;

using namespace std;

int n, k;
long long m;
long long res;

int main (int argc, const char * argv[])
{
    cin >> n >> m >> k;
    if (k > n)
    {
        res = m;
        for (int i = 1; i < n; i++)
        {
            res *= m;
            res %= mod;
        }
        cout << res;
        return 0;
    }
    if (n == k)
    {
        if (n % 2 == 1) n = n / 2 + 1; else n = n / 2;
        res = m;
        for (int i = 1; i < n; i++)
        {
            res *= m;
            res %= mod;
        }
        cout << res << endl;
        return 0;
    }
    if (k % 2 == 0)
    {
        cout << m;
        return 0;
    }
    if (k == 1)
    {
        res = m;
        for (int i = 1; i < n; i++)
        {
            res *= m;
            res %= mod;
        }
        cout << res << endl;
        return 0;
    }
    cout << m * m;
    return 0;
}
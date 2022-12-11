//
//  main.cpp
//  coins_codeforces
//
//  Created by Sokol Kostya's MacBook on 07.01.11.
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


typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

vector<int> divisors;
int f[2000], g[2000];
bool used[2000000];

int main (int argc, const char * argv[])
{
    int n, m;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int a = i, b = n / i;
            used[a] = used[b] = true;
        }
    }
    for (int i = 1; i < 2000000; i++)
    {
        if (used[i]) divisors.pb(i);
    }
    m = divisors.size();
    for (int i = 0; i < m; i++)
    {
        int res = 0, pos = -1;
        for (int j = 0; j < i; j++) if (divisors[i] % divisors[j] == 0 && f[j] > res)
        {
            res = f[j];
            pos = j;
        }
        f[i] = res + 1;
        g[i] = pos;
    }
    int pp = 0;
    for (int i = 1; i < m; i++) if (f[i] > f[pp]) pp = i;
    while (g[pp] != -1)
    {
        cout << divisors[pp] << " ";
        pp = g[pp];
    }
    cout << divisors[pp];
    return 0;
}
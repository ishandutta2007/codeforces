//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 22.06.11.
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

long long k, b, n, t;
long long pp[1111111];

bool check(long long st)
{
    if (k == 1)
    {
        long long val1 = t + b * st;
        long long val2 = 1 + b * n;
        if (val1 >= val2) return true; return false;
    }
    int val = int( n - st );
    long long cur = t, mn = 1;
    for (; val >= 0; val-- )
    {
        if ( pp[val] == -1 ) return false;
        cur -= pp[val] * mn;
        if (cur < 0) return false;
        mn = b;
    }
    return true;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> k >> b >> n >> t;
    pp[0] = 1;
    for (int i = 1; i < 1111111; i++)
    {
        if (pp[i - 1] == -1)
        {
            pp[i] = -1;
            continue;
        }
        pp[i] = pp[i - 1] * k;
        if (pp[i] > t) pp[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (check( i ) == true)
        {
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}
//
//  main.cpp
//  very interesting game
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

void fun(int x)
{
    int len = 0;
    if (x == 0)
    {
        len = 1;
    } else
    {
        while (x > 0) 
        {
            len++;
            x /= 10;
        }
    }
    for (int i = 0; i < 9 - len; i++) cout << 0;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a, b, mod;
    cin >> a >> b >> mod;
    long long mm = mod;
    for (int i = 0; i <= min(a, mod - 1); i++)
    {
        long long cur = i;
        cur *= 1ll * 1000000000;
        cur %= mm;
        long long need = mm - cur;
        if (need % mm > b)
        {
            cout << 1 << " ";
            fun( i );
            cout << i;
            return 0;
        }
    }
    cout << 2;
    return 0;
}
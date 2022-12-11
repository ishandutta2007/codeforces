//
//  main.cpp
//  sum_of_numbers
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

char st[111111];
int n, sum = 0;

int fun(int x)
{
    if (x < 10) return 0;
    int xx = x, tt = 0;
    while (xx > 0)
    {
        tt += xx % 10;
        xx /= 10;
    }
    return fun(tt) + 1;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets(st);
    n = strlen( st );
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int cur = st[i] - '0';
        sum += cur;
    }
    cout << fun( sum ) + 1;
    return 0;
}
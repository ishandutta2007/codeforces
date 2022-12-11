//
//  main.cpp
//  lucky_mask
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

int mask(int x)
{
    vector<int> res;
    while (x > 0)
    {
        if (x % 10 == 4 || x % 10 == 7) res.pb(x % 10);
        x /= 10;
    }
    if (res.size() == 0) return -4;
    int num = 0;
    for (int i = res.size() - 1; i >= 0; i--) num = (10 * num) + res[i];
    return num;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a, b;
    cin >> a >> b;
    for (int i = a + 1; ; i++)
    {
        if (mask(i) == b)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
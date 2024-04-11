//
//  main.cpp
//  borze
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

string st, ans = "";
char from[222];
bool f[222];
int n;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> st;
    n = st.size();
    f[0] = true;
    for (int i = 1; i <= n; i++)
    {
        if (st[i - 1] == '.' && f[i - 1] == true)
        {
            f[i] = true;
            from[i] = '0';
            continue;
        }
        if (i == 1) continue;
        if (st[i - 2] == '-' && st[i - 1] == '.' && f[i - 2] == true)
        {
            f[i] = true;
            from[i] = '1';
            continue;
        }
        if (st[i - 2] == '-' && st[i - 1] == '-' && f[i - 2] == true)
        {
            f[i] = true;
            from[i] = '2';
            continue;
        }
    }
    while (n != 0)
    {
        ans = from[n] + ans;
        if (from[n] == '0')
        {
            n--;
            continue;
        }
        n -= 2;
        continue;
    }
    cout << ans;
    return 0;
}
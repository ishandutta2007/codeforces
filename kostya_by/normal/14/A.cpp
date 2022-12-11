//
//  main.cpp
//  letter_for_brother
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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

int n, m;
char st[55][55];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i1, i2, j1, j2;
    cin >> n >> m; gets( st[0] );
    for (int i = 0; i < n; i++) gets( st[i] );
    i1 = 0;
    for (int i = 0; i < n; i++)
    {
        bool fl = true;
        for (int j = 0; j < m; j++) if (st[i][j] != '.') fl = false;
        if (fl == true)
        {
            i1 = i + 1;
            continue;
        }
        break;
    }
    i2 = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        bool fl = true;
        for (int j = 0; j < m; j++) if (st[i][j] != '.') fl = false;
        if (fl == true)
        {
            i2 = i - 1;
            continue;
        }
        break;
    }
    j1 = 0;
    for (int j = 0; j < m; j++)
    {
        bool fl = true;
        for (int i = 0; i < n; i++) if (st[i][j] != '.') fl = false;
        if (fl == true)
        {
            j1 = j + 1;
            continue;
        }
        break;
    }
    j2 = m - 1;
    for (int j = m - 1; j >= 0; j--)
    {
        bool fl = true;
        for (int i = 0; i < n; i++) if (st[i][j] != '.') fl = false;
        if (fl == true)
        {
            j2 = j - 1;
            continue;
        }
        break;
    }
    for (int i = i1; i <= i2; i++)
    {
        for (int j = j1; j <= j2; j++) putchar( st[i][j] );
        printf("\n");
    }
    return 0;
}
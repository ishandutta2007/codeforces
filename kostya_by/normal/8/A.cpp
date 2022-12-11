//
//  main.cpp
//  pete and train
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

char st[111111], a[111], b[111];
int p1 = -1, p2 = -1, n, m, k, mask;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st ); gets( a ); gets( b );
    n = strlen( st );
    m = strlen( a );
    k = strlen( b );
    for (int i = 0; i < n; i++)
    {
        if (i + m - 1 >= n) break;
        bool fl = true;
        for (int j = 0; j < m; j++) if (st[i + j] != a[j]) fl = false;
        if (fl == true)
        {
            p1 = i;
            break;
        }
    }
    if (p1 != -1)
    {
        for (int i = p1 + m; i < n; i++)
        {
            if (i + k - 1 >= n) break;
            bool fl = true;
            for (int j = 0; j < k; j++) if (st[i + j] !=  b[j]) fl = false;
            if (fl == true)
            {
                p2 = i;
                break;
            }
        }
    }
    if (p2 != -1) mask = 1;
    p1 = -1; p2 = -1;
    int l = 0, r = n - 1;
    while (l < r) swap( st[l++], st[r--] );
    for (int i = 0; i < n; i++)
    {
        if (i + m - 1 >= n) break;
        bool fl = true;
        for (int j = 0; j < m; j++) if (st[i + j] != a[j]) fl = false;
        if (fl == true)
        {
            p1 = i;
            break;
        }
    }
    if (p1 != -1)
    {
        for (int i = p1 + m; i < n; i++)
        {
            if (i + k - 1 >= n) break;
            bool fl = true;
            for (int j = 0; j < k; j++) if (st[i + j] !=  b[j]) fl = false;
            if (fl == true)
            {
                p2 = i;
                break;
            }
        }
    }
    if (p2 != -1) mask ^= 2;
    if (mask == 3) cout << "both";
    if (mask == 2) cout << "backward";
    if (mask == 1) cout << "forward";
    if (mask == 0) cout << "fantasy";
    return 0;
}
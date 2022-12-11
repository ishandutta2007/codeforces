//
//  main.cpp
//  domino_cf
//
//  Created by Sokol Kostya's MacBook on 03.05.11.
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

bool ff[111][20];
int n, from[111][20];
vector<int> aa;

bool check(int mask)
{
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        a[i] = mask % 2;
        mask /= 2;
    }
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == 1) continue;
        if (a[i + 1] == 1) return false;
        a[i] = a[i + 1] = 1;
    }
    if (a[3] == 0) return false;
    return true;
}

int ans[111][111], ii = 1, tt = 1;

void repair(int mask)
{
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        a[i] = mask % 2;
        mask /= 2;
        //cout << a[i] << " ";
    }
   // cout << endl;
    for (int i = 0; i < 4;)
    {
        if (a[i] == 0 && ans[i][ii] == 0)
        {
            ans[i][ii] = tt;
            ans[i + 1][ii] = tt++;
            i += 2;
            continue;
        }
        if (a[i] == 0)
        {
            i++;
            continue;
        }
        ans[i][ii] = tt;
        ans[i][ii + 1] = tt++;
        i++;
    }
    ++ii;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    if (n == 1)
    {
        cout << "a" << endl << "a" << endl << "b" << endl << "b" << endl;
        return 0;
    }
    for (int i = 1; i < 16; i++) if (check(i) == true) ff[1][i] = true;
    for (int i = 2; i < n; i++)
        for (int mask1 = 1; mask1 < 16; mask1++)
        {
            ff[i][mask1] = false;
            for (int mask2 = 1; mask2 < 16; mask2++)
            {
                if ((mask1 & mask2) != 0) continue;
                if ( check( mask1 | mask2 ) == true && ff[i - 1][mask2] == true)
                {
                    ff[i][mask1] = true;
                    from[i][mask1] = mask2;
                }
            }
        }
    int mask = -1;
    for (int i = 1; i < 16; i++) if ( check(i) == true && ff[n - 1][i] == true )
    {
        mask = i;
    }
    if (mask == -1)
    {
        cout << -1;
        return 0;
    }
    for (int i = n - 1; i > 0; i--)
    {
        aa.pb( mask );
        mask = from[ i ][ mask ];
    }
    for (int i = aa.size() - 1; i >= 0; i--)
    {
        //cout << aa[i] << " ";
        repair( aa[i] );
    }
    for (int i = 0; i < 4;)
    {
        if (ans[i][ii] == 0)
        {
            ans[i][ii] = tt;
            ans[i + 1][ii] = tt++;
            i += 2;
            continue;
        }
        ++i;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char cc = ans[i][j] % 26 + 'a';
            cout << cc;
        }
        cout << endl;
    }
    return 0;
}
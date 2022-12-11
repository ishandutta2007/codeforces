//
//  main.cpp
//  anagram_finder
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

char s[111111], p[111111];
int n, m, a[30], b[30], ans = 0, h = 0, t, bad = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s ); gets( p );
    n = int( strlen( s ) );
    m = int( strlen( p ) );
    if (n < m)
    {
        cout << 0;
        return 0;
    }
    t = m - 1;
    for (int i = 0; i < m; i++)
    {
        b[ p[i] - 'a' ]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (s[i] == '?') continue;
        int ii = s[i] - 'a';
        if ( a[ii] == b[ii] ) ++bad;
        a[ii]++;
    }
    if (bad == 0) ++ans;
    while (t != n - 1)
    {
        if (s[h] != '?')
        {
            int ii = s[h] - 'a';
            if ( a[ ii ] - 1 == b[ ii ] ) --bad;
            a[ ii ]--;
        }
        if (s[t + 1] != '?')
        {
            int jj = s[t + 1] - 'a';
            if ( a[jj] == b[jj] ) ++bad;
            a[ jj ]++;
        }
        ++h;
        ++t;
        if (bad == 0) ++ans;
    }
    cout << ans;
    return 0;
}
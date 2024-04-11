//
//  main.cpp
//  cubes
//
//  Created by Sokol Kostya's MacBook on 22.04.11.
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

vector<int> pos[111111];
int pref[111111];
int a, n, x, ans = 0, m, k, ii, jj;

void bin(int l, int r)
{
    if (l > r) return;
    int x = (l + r) / 2;
    if ( ii - pref[x] <= k )
    {
        jj = min( jj, x );
        bin( l, x - 1 );
    } else bin( x + 1, r );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        pos[ a ].pb( i );
    }
    for (int i = 1; i <= m; i++)
    {
        if (pos[i].size() == 0) continue;
        pref[0] = 0;
        for (int j = 1; j < pos[i].size(); j++) pref[j] = pref[j - 1] + ( pos[i][j] - pos[i][j - 1] - 1);
        for (int j = 0; j < pos[i].size(); j++)
        {
            ii = pref[ j ];
            jj = j;
            bin( 0, j - 1 );
            ans = max( ans, j - jj + 1 );
        }
    }
    cout << ans;
    return 0;
}
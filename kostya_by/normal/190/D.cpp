//
//  main.cpp
//  non-secret chifer
//
//  Created by Sokol Kostya's MacBook on 16.05.11.
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
const int ii = 123456789;

using namespace std;

map<int, int> mmp;
vector<int> pp[444444];
int a[444444], n, k, ff[444444], h = 1;
long long ans = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 0; i < 444444; i++) ff[i] = ii;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if ( mmp[ a[i] ] == 0 )
        {
            mmp[ a[i] ] = h++;
        }
        a[i] = mmp[ a[i] ];
        pp[ a[i] ].pb( i );
    }
    for (int i = 1; i < h; i++)
    {
        for (int j = 0; j < pp[i].size(); j++)
        {
            if (j + k - 1 >= pp[i].size()) break;
            ff[ pp[i][j] ] = pp[i][ j + k - 1 ];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ff[i] = min( ff[i], ff[i + 1] );
        if (ff[i] == ii) continue;
        ans += 1ll * (n - ff[i]);
    }
    cout << ans;
    return 0;
}
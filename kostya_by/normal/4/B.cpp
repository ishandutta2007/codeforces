//
//  main.cpp
//  before_the_exam
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

bool ff[33][255];
int gg[33][255], n, sum, mn[33], mx[33];
int ans[33];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> sum;
    for (int i = 1; i <= n; i++) cin >> mn[i] >> mx[i];
    for (int i = 0; i < 33; i++)
        for (int j = 0; j < 255; j++)
            ff[i][j] = false;
    ff[0][0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            for (int k = mn[i]; k <= mx[i]; k++)
            {
                if (j - k < 0) continue;
                ff[i][j] = ff[i][j] | ff[i - 1][j - k];
                if (ff[i - 1][ j - k ] == true) gg[i][j] = k;
            }
    if (ff[n][sum] == false)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = n; i > 0; i--)
    {
        ans[ i ] = gg[ i ][ sum ];
        sum -= gg[ i ][ sum ];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
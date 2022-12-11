//
//  main.cpp
//  phone_callings
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

int ff[4444][4444], n, k, t[4444], d[4444], ans = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &t[i], &d[i]);
    }
    for (int i = 0; i < 4444; i++)
        for (int j = 0; j < 4444; j++)
            ff[i][j] = -1;
    ff[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i <= k) ff[i][0] = 1; else ff[i][0] = -1;
        for (int j = 1; j <= min( n - k, i ); j++)
        {
            int res1 = ff[i - 1][j - 1];
            int res2 = ff[i - 1][j];
            if (res1 != -1)
            {
                int tt = t[i];
                tt = max(tt, res1);
                res1 = tt + d[i];
            }
            ff[i][j] = res1;
            if (res1 == -1) ff[i - 1][j - 1] = res2; else if (res2 != -1) ff[i][j] = min( res1, res2 );
        }
    }
   /* for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++) cout << ff[i][j] << " ";
        cout << endl;
    }
    cout << ff[n][n - k] << endl;*/
    //cout << ff[n][n - k] << endl;
    ans = max( ans, 86400 - ff[n][n - k] + 1 );
    //cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++) 
        {
            if (ff[i - 1][j] == -1) continue;
            if ( (n - i + 1) + j < n - k) continue;
            //cout << t[i] - ff[i - 1][j] << " " << ff[i - 1][j] << endl;
            ans = max(ans, t[i] - ff[i - 1][j]);
        }
    }
    cout << ans;
    return 0;
}
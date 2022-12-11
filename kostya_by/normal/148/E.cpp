//
//  main.cpp
//  task5_cf_105
//
//  Created by Sokol Kostya's MacBook on 02.02.11.
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
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int aa[111], pref[111], suff[111], val[111][111], ss[111], n, m, f[111][11111];

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ss[i];
        for (int j = 1; j <= ss[i]; j++) cin >> aa[j];
        pref[0] = 0;
        for (int j = 1; j <= ss[i]; j++) pref[j] = pref[j - 1] + aa[j];
        suff[0] = 0;
        for (int j = 1; j <= ss[i]; j++) suff[j] = suff[j - 1] + aa[ss[i] - j + 1];
        val[i][0] = 0;
        for (int j = 1; j <= ss[i]; j++)
        {
            val[i][j] = 0;
            for (int k = 0; k <= j; k++) val[i][j] = max(val[i][j], pref[k] + suff[j - k]);
        }
    }
    for (int i = 0; i < 111; i++)
        for (int j = 0; j < 11111; j++)
            f[i][j] = -1;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= ss[i]; k++)
            {
                if (j - k < 0) break;
                int f1 = f[i - 1][j - k];
                if (f1 == -1) continue;
                f1 += val[i][k];
                f[i][j] = max(f[i][j], f1);
            }
        }
    }
    cout << f[n][m];
    return 0;
}
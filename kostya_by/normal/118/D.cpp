//
//  main.cpp
//  cesar legion
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
const int mod = 100000000;

using namespace std;

int f[111][111][2], n1, n2, k1, k2;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n1 >> n2 >> k1 >> k2;
    f[0][0][0] = f[0][0][1] = 1;
    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++)
            for (int k = 0; k < 2; k++)
            {
                if (k == 0)
                {
                    for (int l = 1; l <= k1; l++)
                    {
                        if (i - l < 0) break;
                        f[i][j][0] += f[i - l][j][1];
                        f[i][j][0] %= mod;
                    }
                }
                if (k == 1)
                {
                    for (int l = 1; l <= k2; l++)
                    {
                        if (j - l < 0) break;
                        f[i][j][1] += f[i][j - l][0];
                        f[i][j][1] %= mod;
                    }
                }
            }
    cout << (f[n1][n2][1] + f[n1][n2][0]) % mod;
    return 0;
}
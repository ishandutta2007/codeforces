//
//  main.cpp
//  comb
//
//  Created by Sokol Kostya's MacBook on 03.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const long long inf = 1e18;

long long f[2000][2000], f1[2000][2000], f2[2000][2000], sum[2000][2000], a[2000][2000];
int n, m;

int main (int argc, const char * argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
             scanf("%I64d",&a[i][j]);
    for (int i = 1; i <= n; i++)
    {
        sum[i][1] = a[i][1];
        for (int j = 2; j <= m; j++) sum[i][j] = sum[i][j - 1] + a[i][j]; 
    }
    for (int i = 1; i <= m; i++)
    {
        f[1][i] = sum[1][i];
    }
    f1[1][1] = -inf;
    f1[1][2] = f[1][1];
    for (int i = 3; i <= m; i++)
    {
        f1[1][i] = max(f1[1][i - 1], f[1][i - 1]);
    }
    f2[1][m] = -inf;
    f2[1][m - 1] = f[1][m];
    for (int i = m - 2; i >= 1; i--)
    {
        f2[1][i] = max(f2[1][i + 1], f[1][i + 1]);
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i % 2 == 0)
            {
                if (f2[i - 1][j] == -inf)
                {
                    f[i][j] = -inf;
                    continue;
                }
                f[i][j] = f2[i - 1][j] + sum[i][j];
            }
            if (i % 2 == 1)
            {
                if (f1[i - 1][j] == -inf)
                {
                    f[i][j] = -inf;
                    continue;
                }
                f[i][j] = f1[i - 1][j] + sum[i][j];
            }
        }
        f1[i][1] = -inf;
        f1[i][2] = f[i][1];
        for (int j = 3; j <= m; j++)
        {
            f1[i][j] = max(f1[i][j - 1], f[i][j - 1]);
        }
        f2[i][m] = -inf;
        f2[i][m - 1] = f[i][m];
        for (int j = m - 2; j >= 1; j--)
        {
            f2[i][j] = max(f2[i][j + 1], f[i][j + 1]);
        }
    }
    long long ans = -inf;
   /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << f[i][j] << " ";
        cout << endl;
    }
    cout << "------------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << f2[i][j] << " ";
        cout << endl;
    }*/
    for (int i = 1; i <= m; i++) ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}
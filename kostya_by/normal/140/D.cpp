//
//  main.cpp
//  round100task4
//
//  Created by Sokol Kostya's MacBook on 04.01.11.
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

typedef unsigned long long ull;
#define mp make_pair

const long double eps = 1e-7;
const long long inf = 1e18;

using namespace std;

int f[101][101][1000];
int a[101], n;

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
   // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 1000; k++)
                f[i][j][k] = -1;
    f[0][0][10] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k <= 720; k++)
            {
                f[i][j][k] = f[i][j - 1][k];
                if (a[j] > k) continue;
                if (i == 0) continue;
                if (f[i - 1][j - 1][k - a[j]] == -1) continue;
               // cout << i << " " << j << " " << k << endl;
                int aa = f[i - 1][j - 1][k - a[j]];
                if (k > 360) aa += k - 360;
                if (f[i][j][k] == -1) f[i][j][k] = aa; else f[i][j][k] = min(f[i][j][k], aa);
            }
        }
    }
    //cout << f[0][0][10] << endl;
   // cout << f[1][1][40] << endl;
   // cout << f[2][2][370] << endl;
    for (int i = n; i >= 0; i--)
    {
        int res = 10050000;
        for (int j = 0; j <= 720; j++)
        {
            if (f[i][n][j] == -1) continue;
            res = min(res, f[i][n][j]);
        }
        if (res != 10050000)
        {
            cout << i << " " << res << endl;
            return 0;
        }
    }
    return 0;
}
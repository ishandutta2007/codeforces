//
//  main.cpp
//  iris
//
//  Created by Sokol Kostya's MacBook on 02.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

char s[1000];
int a[1000], b[1000], n, aa, bb, f[2001][2001], f1[2001][2001], f2[2001][2001], f3[2001][2001];

int main (int argc, const char * argv[])
{
    cin >> n;
    gets(s); gets(s);
    for (int i = 1; i <= 2000; i++)
    {
        f[1][i] = i;
        f1[1][i] = 1;
    }
    f1[1][1] = -1;
    for (int i = 2000; i > 0; i--)
    {
        f2[1][i] = i + 1;
    }
    f2[1][2000] = -1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 2000; j++)
        {
            if (s[i - 2] == 'L')
            {
                if (f2[i - 1][j] == -1)
                {
                    f[i][j] = f3[i][j] = -1;
                    continue;
                }
                f[i][j] = f[i - 1][f2[i - 1][j]] + j;
                f3[i][j] = f2[i - 1][j];
            }
            if (s[i - 2] == 'R')
            {
                if (f1[i - 1][j] == -1)
                {
                    f[i][j] = f3[i][j] = -1;
                    continue;
                }
                f[i][j] = f[i - 1][f1[i - 1][j]] + j;
                f3[i][j] = f1[i - 1][j];
            }
            if (s[i - 2] == '=')
            {
                if (f[i - 1][j] == -1)
                {
                    f[i][j] = f3[i][j] = -1;
                    continue;
                }
                f[i][j] = f[i - 1][j] + j;
                f3[i][j] = j;
            }
        }
        f1[i][1] = -1;
        for (int j = 2; j <= 2000; j++)
        {
            if (f1[i][j - 1] == f[i][j - 1] && f[i][j - 1] == -1) 
            {
                f1[i][j] = -1;
                continue;
            }
            f1[i][j] = f1[i][j - 1];
            if (f[i][j - 1] == -1) continue;
            if (f1[i][j - 1] == -1) 
            {
                f1[i][j] = j - 1;
                continue;
            }
            if (f[i][j - 1] < f[i][f1[i][j]]) f1[i][j] = j - 1;
        }
        f2[i][2000] = -1;
        for (int j = 1999; j >= 1; j--)
        {
            if (f2[i][j + 1] == f[i][j + 1] && f[i][j + 1] == -1) 
            {
                f2[i][j] = -1;
                continue;
            }
            f2[i][j] = f2[i][j + 1];
            if (f[i][j + 1] == -1) continue;
            if (f2[i][j + 1] == -1) 
            {
                f2[i][j] = j + 1;
                continue;
            }
            if (f[i][j + 1] < f[i][f2[i][j]]) f2[i][j] = j + 1;
        }
    }
    int ans = 500000000, res = 1000, aa[10000];
    for (int i = 1; i <= 2000; i++) if (f[n][i] != -1) 
    {   
        if (f[n][i] < ans)
        {
            ans = f[n][i];
            res = i;
        }
    }
    aa[n - 1] = res;
    for (int i = n - 2; i >= 0; i--)
    {
        res = f3[i + 2][res];
        aa[i] = res;
    }
    //cout << f[4][4] << endl;
    for (int i = 0; i < n; i++) cout << aa[i] << " ";
    return 0;
}
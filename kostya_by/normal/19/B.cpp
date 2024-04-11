//
//  main.cpp
//  checkout assistant
//
//  Created by Sokol Kostya's MacBook on 23.05.11.
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

int n, t[2222];
long long ff[2][22222], c[2222];

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%I64d", &t[i], &c[i]);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 22222; j++)
            ff[i][j] = -1;
    for (int i = 0; i < n; i++) t[i]++;
    ff[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 22222; j++)
        {
            ff[1][j] = ff[0][j];
            if ( j < t[i] ) continue;
            long long f = ff[0][ j - t[i] ];
            if (f == -1) continue;
            f += c[i];
            if (ff[1][j] == -1) ff[1][j] = f;
            ff[1][j] = min(f, ff[1][j]);
        }
        for (int j = 0; j < 22222; j++) ff[0][j] = ff[1][j], ff[1][j] = -1;
    }
    long long res = -1;
    for (int i = n; i < 22222; i++)
    {
        if ( ff[0][i] == -1 ) continue;
        if (res == -1) res = ff[0][i];
        res = min(res, ff[0][i]);
    }
    cout << res;
    return 0;
}
//
//  main.cpp
//  max_on_spiral
//
//  Created by Sokol Kostya's MacBook on 06.04.11.
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
const int inf = 1e9;

using namespace std;

int ff[505][505][255], n, m, sum[505][505], len[255], a[505][505], ans = -inf;

int fsum(int ii1, int jj1, int ii2, int jj2)
{
    return sum[ii2][jj2] - sum[ii1 - 1][jj2] - sum[ii2][jj1 - 1] + sum[ii1 - 1][jj1 - 1];
}

int fun(int ii, int jj, int kk)
{
    if (ff[ii][jj][kk] != -inf) return ff[ii][jj][kk];
    int ll = len[kk];
    if (ii + ll - 1 > n || jj + ll - 1 > m) return -inf;
    int inow = ii + ll - 1;
    int jnow = jj + ll - 1;
    if (kk == 1)
    {
        ff[ii][jj][kk] = fsum(ii, jj, inow, jnow) - a[ii + 1][jj] - a[ii + 1][jj + 1];
        return ff[ii][jj][kk];
    }
    if (kk == 2)
    {
        ff[ii][jj][kk] = fsum(ii, jj, inow, jnow);
        ff[ii][jj][kk] -= fsum(ii + 1, jj, ii + 1, jnow - 1);
        ff[ii][jj][kk] -= a[ii + 2][jj + 3];
        ff[ii][jj][kk] -= fsum(ii + 3, jj + 1, ii + 3, jnow - 1);
        return ff[ii][jj][kk];
    }
    ff[ii][jj][kk] = fun( ii + 2, jj + 2, kk - 2 );
    ff[ii][jj][kk] += fsum( ii, jj, ii, jnow );
    ff[ii][jj][kk] += fsum( ii + 1, jnow, inow, jnow);
    ff[ii][jj][kk] += fsum( ii + 2, jj, inow, jj);
    ff[ii][jj][kk] += fsum( inow, jj + 1, inow, jnow - 1);
    ff[ii][jj][kk] += a[ii + 2][jj + 1];
    return ff[ii][jj][kk];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < 505; i++)
        for (int j = 0; j < 505; j++)
            for (int k = 0; k < 255; k++)
                ff[i][j][k] = -inf;
    len[1] = 3;
    for (int i = 2; i < 255; i++) len[i] = len[i - 1] + 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k < 255; k++)
                ans = max(ans, fun(i, j, k));
    cout << ans;
    return 0;
}
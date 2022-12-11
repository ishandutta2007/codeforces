//
//  main.cpp
//  algorace
//
//  Created by Sokol Kostya's MacBook on 10.05.11.
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

int pp[66][66], n, m, r, graf[66][66], ff[66][66][66];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < 66; i++)
        for (int j = 0; j < 66; j++)
            graf[i][j] = 1000001;
    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &pp[i][j]);
            }
        }
        for (int kk = 0; kk < n; kk++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    pp[i][j] = min( pp[i][j], pp[i][kk] + pp[kk][j] );
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graf[i][j] = min( graf[i][j], pp[i][j] );
    }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << graf[i][j] << " ";
        cout << endl;
    }*/
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k <= n; k++)
                ff[i][j][k] = 1000001;
    for (int i = 0; i < n; i++)
            ff[i][i][0] = 0;
    for (int i = 0; i < n; i++)
        for (int it = 0; it < n; it++)
            for (int j = 0; j < n; j++)
                for (int k = 1; k <= n; k++)
                    for (int l = 0; l < n; l++)
                        ff[i][j][k] = min( ff[i][j][k], ff[i][l][k - 1] + graf[l][j] );
    /*for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) cout << ff[i][j][k] << " ";
            cout << endl;
        }
        cout << "-------------------" << endl;
    }*/
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b;
        c = min(c + 1, n);
        int ans = 1000001;
        for (int j = 0; j <= c; j++) ans = min(ans, ff[a][b][j]);
        printf("%d\n", ans);
    }
    return 0;
}
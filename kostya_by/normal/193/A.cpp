//
//  main.cpp
//  figures
//
//  Created by Sokol Kostya's MacBook on 03.06.11.
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

int a[55][55], n, m, cc = 0, ans = 4000000, xb, yb;
int dx[4] = { 0, 0, 1,-1};
int dy[4] = { 1,-1, 0, 0};
char st[55];
bool used[55][55];

void fill()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            used[i][j] = false;
}

void dfs(int ii, int jj)
{
    if (used[ii][jj] == true) return;
    if (a[ii][jj] == 0) return;
    if (ii == xb && jj == yb) return;
    used[ii][jj] = true;
    for (int i = 0; i < 4; i++)
    {
        int x = ii + dx[i];
        int y = jj + dy[i];
        if (x == -1 || y == -1 || x == n || y == m) continue;
        dfs( x, y );
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        gets( st );
        for (int j = 0; j < m; j++)
        {
            if ( st[j] == '#' )
            {
                a[i][j] = 1;
                ++cc;
            }
        }
    }
    if (cc < 3)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0) continue;
            int now = 0;
            for (int k = 0; k < 4; k++)
            {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (ii == -1 || jj == -1 || ii == n || jj == m) continue;
                now += a[ii][jj];
            }
            ans = min( ans, now );
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0) continue;
            fill();
            xb = i;
            yb = j;
           // cout << "---------" << endl;
            bool fl = false;
            for (int ii = 0; ii < n; ii++)
            {
                for (int jj = 0; jj < m; jj++)
                {
                    if (xb == ii && yb == jj) continue;
                    if (a[ii][jj] == 0) continue;
                    dfs( ii, jj );
                    //cout << ii << " " << jj << endl;
                    fl = true;
                    break;
                }
                if (fl == true) break;
            }
           //// cout << "---------" << endl;
            int now = 0;
            //cout << xb << " " << yb << endl;
            for (int ii = 0; ii < n; ii++)
            {
                for (int jj = 0; jj < m; jj++)
                {
                   // cout << used[ii][jj] << " ";
                    now += used[ii][jj];
                }
               // cout << endl;
            }
            if (now + 1 != cc) 
            {
                ans = 1;
               // cout << xb << " " << yb << endl;
            }
        }
    }
    cout << ans;
    return 0;
}
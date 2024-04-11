//
//  main.cpp
//  round102task2
//
//  Created by Sokol Kostya's MacBook on 12.01.11.
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

int num[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 2, 2, 4, 0, 0, 0, 0},
    {0, 0, 0, 2, 3, 4, 5, 0, 0, 0},
    {0, 0, 0, 3, 4, 5, 6, 8, 0, 0},
    {0, 0, 0, 3, 4, 6, 7, 9, 10, 12},
    {0, 0, 0, 4, 5, 7, 8, 10, 12, 13},
};

int table[10][10], n, m, now = 0, ans = 0, tans[10][10], color = 1, ones = 0;
bool fl = true;

void rec(int ii, int jj)
{
    if (fl == false) return;
    //cout << ii << " " << jj << endl;
    if (ii == n && jj == m)
    {
        if (now > ans)
        {
            ans = now;
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= m; j++)
                    tans[i][j] = table[i][j];
        }
        if (ans == num[n][m])
        {
            cout << ans << endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++) 
                {
                    char ch;
                    if (tans[i][j] == 0) ch = '.'; else ch = 'A' + tans[i][j] - 1;
                    cout << ch;
                }
                cout << endl;
            }
            cout << endl;
            fl = false;
        }
        return;
    }
    int inext = ii, jnext = jj + 1;
    //cout << inext << " " << jnext << endl;
    if (jnext > m)
    {
        jnext = 1;
        inext++;
    }
    int num = (ii - 1) * m + jj;
    if (table[ii][jj] != 0)
    {
        rec(inext, jnext);
        return;
    }
    if (ii + 2 <= n && jj + 1 <= m && jj - 1 > 0)
    {
        if (table[ii + 1][jj] == 0 && table[ii + 2][jj] == 0 && table[ii][jj + 1] == 0 && table[ii][jj - 1] == 0)
        {
            table[ii][jj] = table[ii + 1][jj] = table[ii + 2][jj] = table[ii][jj + 1] = table[ii][jj - 1] = color;
            color++;
            now++;
            if (ii <= 3) ones++; 
            rec(inext, jnext);
            if (ii <= 3) ones--;
            --color;
            now--;
            table[ii][jj] = table[ii + 1][jj] = table[ii + 2][jj] = table[ii][jj + 1] = table[ii][jj - 1] = 0;
        }
    }
    if (fl == false) return;
    if (ii + 2 <= n && jj + 1 <= m && jj - 1 > 0)
    {
        if (table[ii + 1][jj] == 0 && table[ii + 2][jj] == 0 && table[ii + 2][jj + 1] == 0 && table[ii + 2][jj - 1] == 0)
        {
            table[ii][jj] = table[ii + 1][jj] = table[ii + 2][jj] = table[ii + 2][jj + 1] = table[ii + 2][jj - 1] = color;
            ++color;
            now++;
            if (ii <= 3) ones++; 
            rec(inext, jnext);
            if (ii <= 3) ones--;
            --color;
            now--;
            table[ii][jj] = table[ii + 1][jj] = table[ii + 2][jj] = table[ii + 2][jj + 1] = table[ii + 2][jj - 1] = 0;
        }
    }
    if (fl == false) return;
    if (ii + 2 <= n && jj + 2 <= m)
    {
        if (table[ii + 1][jj] == 0 && table[ii + 2][jj] == 0 && table[ii + 1][jj + 1] == 0 && table[ii + 1][jj + 2] == 0)
        {
            table[ii][jj] = table[ii + 1][jj] = table[ii + 2][jj] = table[ii + 1][jj + 1] = table[ii + 1][jj + 2] = color;
            ++color;
            now++;
            if (ii <= 3) ones++; 
            rec(inext, jnext);
            if (ii <= 3) ones--;
            --color;
            now--;
            table[ii][jj] = table[ii][jj] = table[ii + 1][jj] = table[ii + 2][jj] = table[ii + 1][jj + 1] = table[ii + 1][jj + 2] = 0;
        }
    }
    if (fl == false) return;
    if (ii + 2 <= n && jj - 2 > 0)
    {
        if (table[ii + 1][jj] == 0 && table[ii + 2][jj] == 0 && table[ii + 1][jj - 1] == 0 && table[ii + 1][jj - 2] == 0)
        {
            table[ii][jj] = table[ii + 1][jj] = table[ii + 2][jj] = table[ii + 1][jj - 1] = table[ii + 1][jj - 2] = color;
            ++color;
            now++;
            if (ii <= 3) ones++; 
            rec(inext, jnext);
            if (ii <= 3) ones--;
            --color;
            now--;
            table[ii][jj] = table[ii + 1][jj] = table[ii + 2][jj] = table[ii + 1][jj - 1] = table[ii + 1][jj - 2] = 0;
        }
    }
    if (fl == false) return;
    rec(inext, jnext);
}

int main (int argc, const char * argv[])
{
    cin >> n >> m;
    num[n][m] = num[m][n] = max(num[n][m], num[m][n]);
    rec(1, 1);
    /*cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << tans[i][j] << " ";
        cout << endl;
    }*/
    return 0;
}
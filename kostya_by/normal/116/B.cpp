//
//  main.cpp
//  pigs and wolves
//
//  Created by Sokol Kostya's MacBook on 28.04.11.
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

char st[11][11];
int n, m, ans = 0;
int dx[4] = { 0, 0, 1,-1};
int dy[4] = {-1, 1, 0, 0};

int main (int argc, const char * argv[])
{
    cin >> n >> m; gets(st[0]);
    for (int i = 0; i < n; i++)
    {
        gets( st[i] );
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (st[i][j] != 'W') continue;
            bool fl = false;
            for (int k = 0; k < 4; k++)
            {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (ii == -1 || jj == -1 || ii == n || jj == m) continue;
                if (st[ii][jj] == 'P') fl = true;
            }
            ans += fl;
        }
    }
    cout << ans;
    return 0;
}
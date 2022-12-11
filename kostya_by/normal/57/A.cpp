//
//  main.cpp
//  square land
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

using namespace std;

int n;
int dx[4] = { 0, 0, 1,-1};
int dy[4] = {-1, 1, 0, 0};
queue< pair<int,int> > qq;
int dd[1111][1111];

bool check(int x, int y)
{
    if ((x == 0 || x == n) && (y >= 0 && y <= n)) return true;
    swap(x, y);
    if ((x == 0 || x == n) && (y >= 0 && y <= n)) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < 1111; i++)
        for (int j = 0; j < 1111; j++)
            dd[i][j] = 10000000;
    dd[x1][y1] = 0;
    qq.push( mp( x1, y1 ) );
    while (qq.size() != 0)
    {
        pair<int, int> cur = qq.front();
        qq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ii = cur.first + dx[i];
            int jj = cur.second + dy[i];
            if (check(ii, jj) == false) continue;
            if (dd[ii][jj] != 10000000) continue;
            dd[ii][jj] = dd[cur.first][cur.second] + 1;
            qq.push( mp(ii, jj) );
        }
    }
    cout << dd[x2][y2];
    return 0;
}
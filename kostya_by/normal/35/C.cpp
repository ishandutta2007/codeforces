//
//  main.cpp
//  fire in the forest
//
//  Created by Sokol Kostya's MacBook on 08.02.11.
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

queue< pair<int, int> > qq;
pair<int, int> now, ans;
int val[2222][2222];
int n, m, kk, mx = 0;
int dx[4] = { 1,-1, 0, 0};
int dy[4] = { 0, 0,-1, 1};

int main (int argc, const char * argv[])
{
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < 2222; i++)
        for (int j = 0; j < 2222; j++)
            val[i][j] = -1;
    cin >> kk;
    for (int i = 0; i < kk; i++)
    {
        int x, y;
        cin >> x >> y;
        val[x][y] = 0;
        ans = mp(x, y);
        qq.push( mp(x, y) );
    }
    while (qq.size() != 0)
    {
        now = qq.front();
        qq.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = now.first + dx[i];
            int yy = now.second + dy[i];
            if (xx * yy == 0) continue;
            if (xx > n || yy > m) continue;
            if (val[xx][yy] != -1) continue;
            val[xx][yy] = val[now.first][now.second] + 1;
            qq.push( mp(xx, yy) );
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (val[i][j] > mx)
            {
                mx = val[i][j];
                ans = mp(i, j);
            }
        }
    cout << ans.first << " " << ans.second;    
    return 0;
}
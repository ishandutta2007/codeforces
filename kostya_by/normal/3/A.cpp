//
//  main.cpp
//  shortest_path
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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

int dx[8] = { 0, 0, 1,-1, 1, 1,-1,-1};
int dy[8] = { 1,-1, 0, 0, 1,-1, 1,-1};
int xx, yy, fx, fy;
int from[8][8];
int dd[8][8];
queue< pair<int, int> > qq;
vector<int> ans;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char st[2];
    gets(st);
    xx = st[0] - 'a';
    yy = st[1] - '1';
    gets(st);
    fx = st[0] - 'a';
    fy = st[1] - '1';
    qq.push( mp(xx, yy) );
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            dd[i][j] = 1111;
    dd[xx][yy] = 0;
    from[xx][yy] = -1;
    while (qq.size() != 0)
    {
        pair<int, int> cur = qq.front();
        qq.pop();
        for (int i = 0; i < 8; i++)
        {
            int ii = cur.first + dx[i];
            int jj = cur.second + dy[i];
            if (ii == -1 || jj == -1 || ii == 8 || jj == 8) continue;
            if (dd[ii][jj] <= dd[cur.first][cur.second] + 1) continue;
            qq.push( mp(ii, jj) );
            dd[ii][jj] = dd[cur.first][cur.second] + 1;
            from[ii][jj] = i;
        }
    }
    cout << dd[fx][fy] << endl;
    if (dd[fx][fy] == 0) return 0;
    while (from[fx][fy] != -1)
    {
        ans.pb( from[fx][fy] );
        int ii = from[fx][fy];
        fx -= dx[ii];
        fy -= dy[ii];
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        int ii = ans[i];
        if (dx[ii] == 1) cout << 'R';
        if (dx[ii] == -1) cout << 'L';
        if (dy[ii] == 1) cout << 'U';
        if (dy[ii] == -1) cout << 'D';
        cout << endl;
    }
    return 0;
}

//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 22.06.11.
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

queue< pair<int, int> > qq;
int ff[222222][2], n, k;
char wall[2][222222];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d\n", &n, &k);
    gets( wall[0] ); gets( wall[1] );
    for (int i = 0; i < 222222; i++)
        for (int j = 0; j < 2; j++)
            ff[i][j] = -1;
    ff[1][0] = 0;
    qq.push( mp(1, 0) );
    while (qq.size() != 0)
    {
        pair<int, int> cur = qq.front();
        int f = ff[ cur.first ][ cur.second ];
        qq.pop();
        if ( cur.first != 1 )
        {
            int ii = cur.first - 1;
            int jj = cur.second;

            if ( f + 1 < ii && wall[jj][ii - 1] != 'X' && ff[ii][jj] == -1 )
            {
                ff[ii][jj] = f + 1;
                qq.push( mp(ii, jj) );
            }
        }
        int ii = cur.first + 1;
        int jj = cur.second;
        if ( wall[jj][ii - 1] != 'X' && ff[ii][jj] == -1 )
        {
            ff[ii][jj] = f + 1;
            qq.push( mp(ii, jj) );
            if (ii > n)
            {
                cout << "YES";
                return 0;
            }
        }
        ii = cur.first + k;
        jj = (cur.second + 1) % 2;
        if ( wall[jj][ii - 1] != 'X' && ff[ii][jj] == -1 )
        {
            ff[ii][jj] = f + 1;
            qq.push( mp(ii, jj) );
            if (ii > n)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
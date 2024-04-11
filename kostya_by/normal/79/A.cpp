//
//  main.cpp
//  bus_game
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

vector< pair<int,int> > cc, hh;

void gen() 
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 100; j++)
        {
            if (100 * i + 10 * j != 220) continue;
            cc.pb( mp(i, j) );
            hh.pb( mp(j, i) );
        }
}

int fun(int xx, int yy, int turn)
{
    if (turn == 0)
    {
        for (int i = 0; i < cc.size(); i++)
        {
            if (xx >= cc[i].first && yy >= cc[i].second) return fun(xx - cc[i].first, yy - cc[i].second, 1);
        }
        return 1;
    }
    if (turn == 1)
    {
        for (int i = 0; i < hh.size(); i++)
        {
            if (yy >= hh[i].first && xx >= hh[i].second) return fun(xx - hh[i].second, yy - hh[i].first, 0);
        }
        return 0;
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gen();
    sort( cc.begin(), cc.end(), greater< pair<int, int> >() );
    sort( hh.begin(), hh.end(), greater< pair<int, int> >() );
    int x, y;
    cin >> x >> y;
    int val = fun(x, y, 0);
    if (val == 0) cout << "Ciel"; else cout << "Hanako";
    return 0;
}
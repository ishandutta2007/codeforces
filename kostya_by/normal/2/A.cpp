//
//  main.cpp
//  berlogging
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

int n, a, h = 0, ii, val[1111], m;
vector< pair<int, int> > pts[1111], pp;
string names[1111], cur;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pts[i].pb( mp(0, 0) );
        cin >> cur >> a;
        bool fl = false;
        for (int j = 0; j < h; j++) if (names[j] == cur)
        {
            fl = true;
            ii = j;
        }
        if (fl == false)
        {
            ii = h;
            names[h] = cur;
            ++h;
        }
        pair<int, int> ll = pts[ii].back();
        pts[ii].pb( mp( ll.first + a, i + 1 ) );
        val[ii] = ll.first + a;
    }
    //for (int i = 0; i < h; i++) cout << val[i] << " "; cout << endl;
    sort(val, val + h, greater<int>());
    m = val[0];
    for (int i = 0; i < h; i++) if (pts[i].back().first == m) pp.pb( mp( 100000, i ) );
    for (int i = 0; i < pp.size(); i++)
    {
        int ii = pp[i].second;
        for (int j = 0; j < pts[ii].size(); j++) 
            if (pts[ii][j].first >= m) pp[i].first = min(pp[i].first, pts[ii][j].second );
    }
    sort(pp.begin(), pp.end());
    cout << names[ pp[0].second ];
    return 0;
}
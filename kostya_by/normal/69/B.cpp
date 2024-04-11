//
//  main.cpp
//  bids
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

pair<int, int> seg[111];
int n, m, l, r, t, c, ans = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 0; i < 111; i++) seg[i] = mp( 10000, 0 );
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r >> t >> c;
        for (int j = l; j <= r; j++) 
        {
            if (seg[j].first <= t) continue;
            seg[j].first = t;
            seg[j].second = c;
        }
    }
    for (int i = 0; i < 111; i++) if (seg[i].first != 10000) ans += seg[i].second;
    cout << ans;
    return 0;
}
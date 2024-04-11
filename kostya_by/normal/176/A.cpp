//
//  main.cpp
//  TradeDeal
//
//  Created by Sokol Kostya's MacBook on 20.04.11.
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

int n, k, m;
int a[11][111], b[11][111], c[11][111], ans = 0;
vector< pair<int, int> > pp;
string name;

int main (int argc, const char * argv[])
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        for (int j = 0; j < m; j++) cin >> a[i][j] >> b[i][j] >> c[i][j];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            pp.clear();
            int kk = k;
            for (int k = 0; k < m; k++) if (b[j][k] - a[i][k] > 0) pp.pb( mp( b[j][k] - a[i][k], c[i][k] ) );
            sort( pp.begin(), pp.end(), greater< pair<int, int> >() );
            int cur = 0;
            for (int k = 0; k < pp.size(); k++)
            {
                int aa = pp[k].first;
                int bb = pp[k].second;
                bb = min(bb, kk);
                cur += aa * bb;
                kk -= bb;
            }
            //cout << i << " " << j << " - " << cur << endl;
            ans = max(ans, cur);
        }
    cout << ans;
    return 0;
}
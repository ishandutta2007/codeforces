//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 11.03.11.
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

set<int > sst;
set<int>::iterator ii;
map<int, vector<int> > mmp;
int a[111111], b[111111], n, m, x, y;
vector< pair< int, int > > ans;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    cin >> n >> m >> x >> y;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sst.insert( a[i] );
        mmp[ a[i] ].pb( i + 1 );
    }
    
    for (int i = 0; i < m; i++)
    {
        
        scanf("%d", &b[i]);
        int now = b[i] - y;
        ii = sst.lower_bound( now );
        if (ii == sst.end()) continue;
        now = *ii;
        if (b[i] < now - x) continue;
        ans.pb( mp( mmp[ now ].back(), i + 1 ) );
        mmp[ now ].pop_back();
        if (mmp[ now ].size() == 0)
        {
            sst.erase( now );
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
//
//  main.cpp
//  hot
//
//  Created by Sokol Kostya's MacBook on 08.08.11.
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
long long m, t, T, x, cost;
long long ans = 0, best;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cost);
        long long per_bus = max( T - t, 0ll );
        if ( per_bus == 0 )
        {
            ans += 1ll * ( m * x + cost );
            //cout << m * x + cost << endl;
            continue;
        }
        
        long long all = m / per_bus;
        if ( m % per_bus != 0 ) ++all;
        if ( all == 1 )
        {
            ans += 1ll * ( cost );
            //cout << cost << endl;
            continue;
        }
        best = 1ll * ( all * cost );
        int right_bound = all - 1;
        long long br1 = 1ll * ( cost - x * per_bus );
        if ( br1 < 0 )
        {
            ans += min( best, 1ll * ( m * x + right_bound * br1 + per_bus * x ) );
           // cout << min( best, 1ll * ( m * x + right_bound * br1 ) ) << endl;
            continue;
        }
        ans += min( best, 1ll * ( m * x + br1 + per_bus * x ) );
       // cout << min( best, 1ll * ( m * x + br1 * x ) ) << endl;
    }
    cout << ans;
    return 0;
}
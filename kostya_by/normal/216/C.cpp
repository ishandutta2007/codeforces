//
//  main.cpp
//  task3
//
//  Created by Sokol Kostya's MacBook on 14.08.11.
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

int timet[ 11111 ], n, m, k;
vector< int > ans;

void add( int day )
{
    ans.pb( day );
    for (int i = day; i <= day + n - 1; i++) timet[ i ]++;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    
    if ( k == 1 )
    {
        
        int cur = 1;
        while ( cur <= n + m )
        {
            add( cur );
            cur += n - 1;
        }
        
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) printf("%d ", ans[ i ]);
        
        return 0;
    }
    
    for (int i = 1; i <= k; i++) add( 1 ); 
    
    int cur = n + 1;
    while ( cur <= n + m )
    {
        
        for (int i = 1; i <= k - 1; i++) add( cur );
        cur += n;
    }
    
    cur = n;
    while ( cur <= n + m )
    {
        add( cur );
        cur += n;
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[ i ]);
    return 0;
}
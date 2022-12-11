//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 19.04.11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
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

int n, m, k;
map< int, int > mm;
vector< int > v;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    for ( int i = 0; i < n; i++ )
    {
        int a; scanf("%d", &a);
        mm[a]++;
    }
    for ( int i = 0; i < m; i++ )
    {
        int b; scanf("%d", &b);
        mm[b]--;
    }
    for ( map< int, int >::iterator it = mm.begin(); it != mm.end(); it++ )
    {
        if ( it->second == 0 ) continue;
        v.pb( it->second );
    }
    int sum = 0;
    reverse( v.begin(), v.end() );
    for ( int i = 0; i < v.size(); i++ )
    {
        sum += v[i];
        if ( sum > 0 )
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
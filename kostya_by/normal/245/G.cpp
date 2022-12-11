//
//  main.cpp
//  possible_fr
//
//  Created by Sokol Kostya's MacBook on 19.11.11.
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

map< string, int > id;
pair< int, int > p[ 5555 ];
set< pair< int, int > > s;
vector< string > v;
int m, h = 1, deg[ 11111 ];
vector< int > mm[ 11111 ];
int lst[ 11111 ], lnum[ 111111 ];

void check( int id1, int id2 )
{
    if ( id1 == id2 ) return;
    if ( s.find( mp( id1, id2 ) ) != s.end() ) return;
    if ( s.find( mp( id2, id1 ) ) != s.end() ) return;
    mm[id1].pb( id2 );
    mm[id2].pb( id1 );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &m);
    v.pb("1as");
    for ( int i = 0; i < m; i++ )
    {
        string a, b;
        cin >> a >> b;
        if ( id[a] == 0 ) id[a] = h++, v.pb( a ), lst[h - 1] = -1;
        if ( id[b] == 0 ) id[b] = h++, v.pb( b ), lst[h - 1] = -1;
        p[i] = mp( id[a], id[b] );
        deg[ p[i].first ]++;
        deg[ p[i].second ]++;
        s.insert( p[i] );
    }
    for ( int i = 0; i < m; i++ )
        for ( int j = i + 1; j < m; j++ )
        {
            if ( p[i].first == p[j].first ) check( p[i].second, p[j].second );
            if ( p[i].first == p[j].second ) check( p[i].second, p[j].first );
            if ( p[i].second == p[j].first ) check( p[i].first, p[j].second );
            if ( p[i].second == p[j].second ) check( p[i].first, p[j].first );
        }
    cout << v.size() - 1 << endl;
    for ( int i = 1; i < v.size(); i++ )
    {
        cout << v[i] << " ";
        int cnt = v.size() - 2 - mm[i].size() - deg[i], num1 = 0;
        for ( int j = 0; j < mm[i].size(); j++ )
        {
            int cur = mm[i][j];
            if ( lst[ cur ] != i )
            {
                lst[ cur ] = i;
                lnum[ cur ] = 1;
            } else lnum[ cur ]++;
            if ( lnum[ cur ] > num1 )
            {
                num1 = lnum[ cur ];
                cnt = 0;
            }
            if ( lnum[ cur ] == num1 ) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
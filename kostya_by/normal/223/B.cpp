//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 16.09.11.
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

char s[ 222222 ], t[ 222222 ];
int n, m, lim;
vector< int > cur;
int pls[ 26 ][ 200011 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s ); gets( t );
    n = strlen( s );
    m = strlen( t );
    int pnt = 0;
    for ( int i = 0; i < m; i++ )
    {
        while ( pnt != n )
        {
            if ( s[ pnt ] == t[i] ) break;
            ++pnt;
        }
        if ( pnt == n )
        {
            cout << "No";
            return 0;
        }
        cur.pb( pnt );
        ++pnt;
    }
    lim = n;
    while ( cur.size() != 0 )
    {
        int id = cur.back();
        int ch = s[ id ] - 'a';
        pls[ ch ][ id ]++;
        pls[ ch ][ lim ]--;
        --lim;
        while ( s[ lim ] - 'a' != ch ) --lim;
        cur.pop_back();
    }
    
    for ( int i = 0; i < 26; i++ )
    {
        int tmp = 0;
        for ( int j = 0; j < n; j++ )
        {
            tmp += pls[i][j];
            pls[i][j] = tmp;
        }
    }
    
    for ( int i = 0; i < n; i++ ) if ( pls[ s[i] - 'a' ][ i ] == 0 )
    {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}
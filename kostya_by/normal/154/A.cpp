//
//  main.cpp
//  hometask
//
//  Created by Sokol Kostya's MacBook on 14.01.11.
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

char st[ 111111 ], cur[ 5 ];
int n, k, f[ 111111 ][ 27 ];
bool ok[ 27 ][ 27 ];

void upd( int &a, int b )
{
    a = min( a, b );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st ); n = strlen( st );
    scanf("%d\n", &k);
    for ( int i = 0; i < k; i++ )
    {
        gets( cur );
        int id1 = cur[0] - 'a';
        int id2 = cur[1] - 'a';
        ok[id1][id2] = ok[id2][id1] = true;
    }
    for ( int i = 0; i < 111111; i++ )
        for ( int j = 0; j < 27; j++ )
            f[i][j] = 1000000000;
    f[0][26] = 0;
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < 27; j++ )
        {
            int id = st[i] - 'a';
            if ( ok[id][j] == false ) upd( f[i + 1][id], f[i][j] );
            upd( f[i + 1][j], f[i][j] + 1 );
        }
    int ans = 1000000000;
    for ( int i = 0; i < 27; i++ ) ans = min( ans, f[n][i] );
    cout << ans << endl;
    return 0;
}
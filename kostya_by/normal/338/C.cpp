//
//  main.cpp
//  task3
//
//  Created by Sokol Kostya's MacBook on 16.08.2013.
//  Copyright (c) 2013 Sokol Kostya's MacBook. All rights reserved.
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
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, best = 1000000000;
long long a[ 8 ], mul[ 256 ];
int sum[ 256 ];
int d[ 8 ], lim;
int f[ 9 ][ 256 ];
vector< int > p;

int main (int argc, const char * argv[])
{
    time_t start = clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> a[i];
    random_shuffle( a, a + n );
    for ( int i = 0; i < n; i++ )
    {
        long long aa = a[i];
        while ( aa % 2 == 0 ) d[i]++, aa /= 2;
        for ( long long j = 3; j * j <= a[i]; j += 2 ) while ( aa % j == 0 ) d[i]++, aa /= j;
        if ( aa > 1 ) d[i]++;
        p.pb( i );
    }
    lim = 1 << n;
    do
    {
        for ( int i = 0; i < lim; i++ )
        {
            mul[i] = 1;
            sum[i] = 0;
            for ( int j = 0; j < n; j++ )
            {
                if ( ( 1 << j ) & i )
                {
                    sum[i] += d[ p[j] ];
                    long double aa = mul[i];
                    long double bb = a[ p[j] ];
                    if ( aa * bb > 1e15 )
                    {
                        mul[i] = -1;
                        break;
                    }
                    mul[i] *= a[ p[j] ];
                }
            }
        }
        for ( int i = 0; i <= n; i++ )
            for ( int msk = 0; msk < lim; msk++ )
                f[i][msk] = 1000000000;
        f[0][0] = 0;
        int bg = 0;
        for ( int i = 0; i < n; i++ )
        {
            for ( int msk = bg; msk < ( 1 << i ); msk++ )
            {
                if ( f[i][msk] == 1000000000 ) continue;
                //int cm = msk - bg + 1;
                //if ( cm & ( cm - 1 ) ) continue;
                int curm = msk;
                while ( true )
                {
                    int jj = msk ^ curm ^ ( 1 << i );
                    if ( mul[curm] != -1 && ( a[ p[i] ] % mul[curm] == 0 ) )
                        f[i + 1][jj] = min( f[i + 1][jj], f[i][msk] + d[ p[i] ] - sum[curm] + 1 );
                    if ( curm == 0 && d[ p[i] ] == 1 ) f[i + 1][jj] = min( f[i + 1][jj], f[i][msk] + 1 );
                    if ( curm == 0 ) break;
                    curm = ( curm - 1 ) & msk;
                }
            }
            bg = 1 << i;
        }
        for ( int i = 0; i < lim; i++ )
        {
            int ones = __builtin_popcount( i );
            best = min( best, f[n][i] + ( ones > 1 ? 1 : 0 ) );
        }
        if ( 1.0 * ( clock() - start ) / CLOCKS_PER_SEC > 0.480 ) break;
    } while ( next_permutation( p.begin(), p.end() ) );
    cout << best << endl;
    return 0;
}
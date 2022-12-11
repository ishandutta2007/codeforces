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
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, a[ 500500 ], p[ 500500 ], f[ 500500 ], g[ 500500 ], aa[ 500500 ], bb[ 500500 ];
map< int, int > m;
vector< int > tree[ 4 * 500500 ];

void init( int v, int l, int r )
{
    if ( l == r )
    {
        tree[v].resize( 1 );
        tree[v][0] = p[l];
        return;
    }
    int x = (l + r) / 2;
    init( v + v, l, x );
    init( v + v + 1, x + 1, r );
    tree[v].resize( tree[v + v].size() + tree[v + v + 1].size() );
    merge( tree[v + v].begin(), tree[v + v].end(), tree[v + v + 1].begin(), tree[v + v + 1].end(), tree[v].begin() ); 
}

int biggest_under( int v, int l, int r, int ll, int rr, int value )
{
    if ( l == ll && rr == r )
    {
        if ( tree[v][0] >= value ) return -1;
        int left = 1, right = tree[v].size() - 1, result = 0;
        while ( left <= right )
        {
            int middle = ( left + right ) / 2;
            if ( tree[v][middle] < value ) 
            {
                result = max( result, middle );
                left = middle + 1;
            } else right = middle - 1;
        }
        return tree[v][result];
    }
    int x = (l + r) / 2;
    int result = -1;
    if ( ll <= x )
        result = max( result, biggest_under( v + v, l, x, ll, min( rr, x ), value ) );
    if ( x + 1 <= rr )
        result = max( result, biggest_under( v + v + 1, x + 1, r, max( x + 1, ll ), rr, value ) );
    return result;  
}

void solve()
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%d", &a[i]);
        p[i] = m[ a[i] ];
        m[ a[i] ] = i;
    }
    init( 1, 1, n );
    f[0] = 0;
    for ( int i = 1; i <= n; i++ )
    {
        f[i] = f[i - 1];
        g[i] = i - 1;
        aa[i] = bb[i] = -1;
        int pos = i;
        for ( int it = 0; it < 3; it++ )
        {
            pos = p[ pos ];
            if ( pos == 0 ) break;
            if ( it == 2 )
            {
                int ff = f[ pos - 1 ] + 1;
                if ( ff > f[ i ] )
                {
                    f[i] = ff;
                    g[i] = pos - 1;
                    aa[i] = a[ pos ];
                    bb[i] = a[ pos ];
                }
                break;
            }
            int l = pos + 1, r = i - 1;
            if ( l <= r )
            {
                int _pos = biggest_under( 1, 1, n, l, r, pos );
                if ( _pos > 0 )
                {
                    int ff = f[ _pos - 1 ] + 1;
                    if ( ff > f[ i ] )
                    {
                        f[i] = ff;
                        g[i] = _pos - 1;
                        aa[i] = a[ _pos ];
                        bb[i] = a[ pos ];
                    }
                } 
            }
        }
    }
    printf("%d\n", f[n] * 4);
    int i = n, h = 0;
    while ( i )
    {
        if ( aa[i] != -1 )
        {
            a[ ++h ] = bb[i];
            a[ ++h ] = aa[i];
            a[ ++h ] = bb[i];
            a[ ++h ] = aa[i];
        }
        i = g[i];
    }
    for ( int i = 1; i <= h; i++ ) printf("%d ", a[ h - i + 1 ]); printf("\n");
}

int main (int argc, const char * argv[])
{
    int t = 1;
    for ( int i = 1; i <= t; i++ ) solve();
    return 0;
}
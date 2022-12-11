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
const int inf = 1e9;

using namespace std;

int f[ 1048580 ], lim;
int n, m, s[ 111 ];
char t[ 22 ];
int c[ 22 ];

int fun( int ii, int msk )
{
    if ( f[msk] != inf ) return f[msk];
    if ( ii == m ) return 0;
    if ( c[ii] == 1 )
    {
        int cur = -inf;
        if ( t[ii] == 'p' )
            for ( int i = 0; i < n; i++ )
            {
                int pt = 1 << i;
                if ( msk & pt ) continue;
                cur = max( cur, s[i] + fun( ii + 1, msk ^ pt ) );
            }
        if ( t[ii] == 'b' )
        {
            for ( int i = 0; i < n; i++ )
            {
                int pt = 1 << i;
                if ( msk & pt ) continue;
                cur = max( cur, fun( ii + 1, msk ^ pt ) );
            }
        }
        f[msk] = cur;
        return cur;
    }
    if ( c[ii] == 2 )
    {
        int cur = inf;
        if ( t[ii] == 'p' )
            for ( int i = 0; i < n; i++ )
            {
                int pt = 1 << i;
                if ( msk & pt ) continue;
                cur = min( cur, fun( ii + 1, msk ^ pt ) - s[i] );
            }
        if ( t[ii] == 'b' )
        {
            for ( int i = 0; i < n; i++ )
            {
                int pt = 1 << i;
                if ( msk & pt ) continue;
                cur = min( cur, fun( ii + 1, msk ^ pt ) );
            }
        }
        f[msk] = cur;
        return cur;
    }
}

int main (int argc, const char * argv[])
{
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> s[i]; sort( s, s + n, greater< int >() );
    cin >> m;
    for ( int i = 0; i < m; i++ ) cin >> t[i] >> c[i];
    while ( n > m ) n--;
    lim = 1 << n;
    for ( int msk = 0; msk < lim; msk++ ) f[msk] = inf;
    cout << fun( 0, 0 ) << "\n";
    return 0;
}
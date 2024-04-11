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

int n, q, sparse[ 17 ][ 100100 ];
int x[ 300300 ]; long long answer[ 300300 ];
int qq[ 300300 ], m, tmp[ 300300 ]; 

int gcd( int a, int b )
{
    if ( a != 0 ) return gcd( b % a, a ); return b;
}

void add( int x, int num )
{
    if ( x > qq[m] ) return;
    int l = 1, r = m - 1, pos = m;
    while ( l <= r )
    {
        int mid = ( l + r ) / 2;
        if ( x <= qq[ mid ] )
        {
            pos = min( mid, pos );
            r = mid - 1;
        } else l = mid + 1;
    }
    if ( qq[ pos ] == x ) answer[ pos ] += num;
}

long long fun( int x )
{
    if ( x > qq[m] ) return 0ll;
    int l = 1, r = m - 1, pos = m;
    while ( l <= r )
    {
        int mid = ( l + r ) / 2;
        if ( x <= qq[ mid ] )
        {
            pos = min( mid, pos );
            r = mid - 1;
        } else l = mid + 1;
    }
    if ( qq[ pos ] == x ) return answer[ pos ];
    return 0ll;
}

void solve()
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &sparse[0][i]);
    for ( int p = 1; p < 17; p++ )
        for ( int i = 1; i <= n; i++ )
        {
            int ii = i + ( 1 << ( p - 1 ) );
            int rr = i + ( 1 << p ) - 1;
            sparse[p][i] = -1;
            if ( rr > n ) continue;
            sparse[p][i] = gcd( sparse[p - 1][i], sparse[p - 1][ii] ); 
        }
    scanf("%d", &q);
    for ( int i = 1; i <= q; i++ )
    {
        scanf("%d", &x[i]);
        tmp[i] = x[i];
    }
    sort( tmp + 1, tmp + q + 1 );
    qq[1] = tmp[1]; m = 1;
    for ( int i = 2; i <= q; i++ ) if ( tmp[i - 1] < tmp[i] ) qq[ ++m ] = tmp[i];
    for ( int left = 1; left <= n; left++ )
    {
        int _gcd = 0;
        int bound = left;
        while ( bound <= n )
        {
            int right = bound;
            int need = gcd( _gcd, sparse[0][ bound ] );
            int left = _gcd;
            for ( int p = 16; p >= 0; p-- )
            {
                if ( sparse[p][right] == -1 ) continue;
                int cur_gcd = gcd( left, sparse[ p ][ right ] );
                if ( cur_gcd != need ) continue;
                left = cur_gcd;
                right = right + ( 1 << p ) - 1;
            }
            _gcd = gcd( _gcd, need );
            add( _gcd, right - bound + 1 ); 
            bound = right + 1;
        }
    }
    // ------------------------
    for ( int i = 1; i <= q; i++ ) printf("%I64d\n", fun( x[i] ));
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}
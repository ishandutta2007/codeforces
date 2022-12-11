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
#define fmin _fmin

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
const int mod = 1000000007;

using namespace std;

char s[ 5050 ];
int n, g[ 5050 ][ 5050 ], lcp[ 5050 ][ 5050 ];
int fcnt[ 5050 ][ 5050 ], fmin[ 5050 ][ 5050 ];

bool not_greater( int l1, int l2, int len )
{
    //cout << l1 << " " << l2 << "\n"; 
    if ( lcp[l1][l2] >= len ) return true;
    return s[ l1 + lcp[l1][l2] ] < s[ l2 + lcp[l1][l2] ];
}

bool better( int a, int b )
{
    if ( a <= 25 && b > 25 ) return true;
    if ( a > 25 && b <= 25 ) return false;
    if ( a > 25 && b > 25 ) return a < b;
    return g[ n - a + 1 ][ n ] + fmin[ n ][ a ] < g[ n - b + 1 ][ n ] + fmin[ n ][ b ];
}

void solve()
{
    gets( s + 1 ); n = strlen( s + 1 );

    for ( int i = n; i >= 1; i-- )
        for ( int j = n; j >= 1; j-- )
            if ( s[i] != s[j] ) lcp[i][j] = 0; else lcp[i][j] = 1 + lcp[i + 1][j + 1];

    for ( int l = 1; l <= n; l++ )
    {
        g[l][l] = s[l] - '0';
        for ( int r = l + 1; r <= n; r++ )
        {
            g[l][r] = g[l][r - 1] * 2 + ( s[r] - '0' );
            g[l][r] %= mod;
        }
    }
    for ( int i = 0; i < 5050; i++ )
        for ( int j = 0; j < 5050; j++ )
        {
            fcnt[i][j] = 0;
            fmin[i][j] = 1000000000;
        }

    fcnt[ 0 ][ 0 ] = 1; 
    fmin[ 0 ][ 0 ] = 0;

    for ( int i = 0; i < n; i++ )
    {
        if ( s[ i + 1 ] == '0' ) continue;
        int cur_cnt = fcnt[ i ][ 0 ];
        int cur_min = fmin[ i ][ 0 ];
        int delta = 0;
        for ( int j = i + 1; j <= n; j++ )
        {
            delta += 1;
            ( fcnt[ j ][ delta ] += cur_cnt ) %= mod;
            fmin[ j ][ delta ] = min( fmin[ j ][ delta ], cur_min + 1 );
            int l1 = i - delta + 1;
            int l2 = i + 1;
            if ( not_greater( l1, l2, delta ) )
            {
                ( fcnt[ j ][ delta ] += fcnt[ i ][ delta ] ) %= mod;
                fmin[ j ][ delta ] = min( fmin[ j ][ delta ], fmin[ i ][ delta ] + 1 );
            }
            ( cur_cnt += fcnt[ i ][ delta ] ) %= mod;
            cur_min = min( cur_min, fmin[ i ][ delta ] );
        }
    }
    int answer = 0;
    for ( int i = 0; i <= n; i++ ) ( answer += fcnt[n][i] ) %= mod;
    cout << answer << "\n";
    int len = -1;
    for ( int i = 0; i <= n; i++ )
    {
        if ( fmin[n][i] == 1000000000 ) continue;
        if ( len == -1 ) len = i;
        if ( better( i, len ) ) len = i;
    } 
    cout << ( g[ n - len + 1 ][ n ] + fmin[ n ][ len ] ) % mod << "\n";
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}
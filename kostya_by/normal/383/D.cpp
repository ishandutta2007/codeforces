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
const int mod = 1000000007;

using namespace std;

int n, a[ 1010 ];
int answer = 0;
int f[ 2 ][ 20020 ], _f[ 2 ][ 20020 ];
int g[ 20020 ], _g[ 20020 ];

void solve( int l, int r )
{
    if ( l == r ) return;
    int x = (l + r) / 2;
    solve( l, x ); solve( x + 1, r );
    //-------------------------------
    for ( int i = 0; i < 20020; i++ ) g[i] = 0;
    for ( int i = 0; i < 2; i++ )
        for ( int j = 0; j < 20020; j++ )
            f[i][j] = 0;
    f[0][ 10005 ] = 1;
    for ( int i = x; i >= l; i-- )
    {
        for ( int j = 0; j < 20020; j++ )
        {
            if ( j + a[i] < 20020 ) 
            {
                f[1][j + a[i]] += f[0][j];
                if ( f[1][j + a[i]] >= mod ) f[1][j + a[i]] -= mod;
            }
            if ( j - a[i] >= 0 ) 
            {
                f[1][j - a[i]] += f[0][j];
                if ( f[1][j - a[i]] >= mod ) f[1][j - a[i]] -= mod;
            }
        }
        for ( int j = 0; j < 20020; j++ )
        {
            g[j] += f[1][j];
            if ( g[j] >= mod ) g[j] -= mod;
            f[0][j] = f[1][j];
            f[1][j] = 0;
        } 
    }
    //-------------------------------
    for ( int i = 0; i < 20020; i++ ) _g[i] = 0;
    for ( int i = 0; i < 2; i++ )
        for ( int j = 0; j < 20020; j++ )
            _f[i][j] = 0;
    _f[0][ 10005 ] = 1;
    for ( int i = x + 1; i <= r; i++ )
    {
        for ( int j = 0; j < 20020; j++ )
        {
            if ( j + a[i] < 20020 ) 
            {
                _f[1][j + a[i]] += _f[0][j];
                if ( _f[1][j + a[i]] >= mod ) _f[1][j + a[i]] -= mod;
            }
            if ( j - a[i] >= 0 ) 
            {
                _f[1][j - a[i]] += _f[0][j];
                if ( _f[1][j - a[i]] >= mod ) _f[1][j - a[i]] -= mod;
            }
        }
        for ( int j = 0; j < 20020; j++ )
        {
            _g[j] += _f[1][j];
            if ( _g[j] >= mod ) _g[j] -= mod;
            _f[0][j] = _f[1][j];
            _f[1][j] = 0;
        } 
    }
    //-------------------------------
    long long buf1, buf2;
    for ( int i = 0; i < 20020; i++ )
    {
        int j = 20010 - i;
        if ( 0 <= j && j <= 20020 )
        {
            buf1 = g[i];
            buf2 = _g[j];
            ( buf1 *= buf2 ) %= mod;
            ( answer += buf1 ) %= mod;
        }
    }
}

int main (int argc, const char * argv[])
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    solve( 1, n );
    cout << answer << "\n"; 
    return 0;
}
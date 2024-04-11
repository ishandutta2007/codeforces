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
const long long base = 23;
const long long mod = 1000000007;

using namespace std;

int n; 
long long pt[ 300300 ];

struct fenwick
{
    long long tree[ 300300 ];
    fenwick()
    {
        memset( tree, 0, sizeof( tree ) );
    }
    void activate( int pos )
    {
        long long value = pt[ pos ];
        while ( pos < 300300 )
        {
            ( tree[ pos ] += value ) %= mod;
            pos = pos + pos - ( pos & ( pos - 1 ) );
        }
    }
    long long pref( int pos )
    {
        long long result = 0;
        while ( pos )
        {
            ( result += tree[ pos ] ) %= mod;
            pos = pos & ( pos - 1 );
        }
        return result;
    }
    long long calculate_hash( int l, int r )
    {
        long long value = ( pref( r ) - pref( l - 1 ) + mod ) % mod;
        return ( value * pt[ n - r ] ) % mod;
    }
};

fenwick foreward, backward;

int main (int argc, const char * argv[])
{
    pt[ 0 ] = 1;
    for ( int i = 1; i < 300300; i++ ) pt[ i ] = ( pt[ i - 1 ] * base ) % mod;
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) 
    {
        int a; scanf("%d", &a);
        int len = min( n - a + 1, a );
        int l = a - len + 1;
        int r = a + len - 1;
        if ( foreward.calculate_hash( l, r ) != backward.calculate_hash( n - r + 1, n - l + 1 ) )
        {
            puts( "YES" );
            return 0;
        }
        foreward.activate( a );
        backward.activate( n - a + 1 );
    }
    puts("NO");
    return 0;
}
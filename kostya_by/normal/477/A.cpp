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
const long long mod = 1000000007;

using namespace std;

int fun( int a, int b )
{
    if ( a < 1 || b < 1 ) return 0;
    int result = 0;
    for ( int x = 1; x <= 100000; x++ )
    {
        if ( x % b == 0 ) continue;
        int i = x / b;
        int j = x % b;
        if ( i % j != 0 ) continue;
        if ( i / j >= 1 && i / j <= a ) 
        {
            result += x;
            //cout << x << " "; 
        }
    }  
    //cout << "\n";
    return result;
}

int gun( int i, int j )
{
    return fun( i, j ) - fun( i - 1, j );
}

long long hun( int a, int b )
{
    long long result = 0;
    if ( b % 2 == 0 )
    {
        long long tmp = b;
        result = ( ( ( tmp / 2 ) * ( tmp + 1 ) ) % mod ) * ( tmp + 2 );
        result %= mod;
    }
    if ( b % 2 == 1 )
    {
        long long tmp = b;
        result = ( tmp * ( ( tmp + 1 ) / 2 ) % mod ) * ( tmp + 2 );
        result %= mod;
    }
    if ( a == 0 ) return result;
    long long delta = 0;
    if ( b % 2 == 0 )
    {
        long long tmp = b;
        delta = ( ( ( tmp / 2 ) * ( tmp + 1 ) ) % mod ) * ( tmp + 1 );
        delta %= mod;
    }
    if ( b % 2 == 1 )
    {
        long long tmp = b;
        delta = ( tmp * ( ( tmp + 1 ) / 2 ) % mod ) * ( tmp + 1 );
        delta %= mod;
    }
    long long aa = b + 1;
    long long tmp = 0;
    tmp = ( ( ( aa * aa ) % mod ) * aa ) % mod;
    tmp -= ( aa * ( aa + 1 ) / 2 ) % mod;
    while ( tmp < 0 ) tmp += mod;
    for ( int i = 0; i < a; i++ )
    {
        ( result += tmp ) %= mod;
        ( tmp += delta ) %= mod;
    }
    return result;
}

void solve()
{
    int a, b; cin >> a >> b;
    cout << hun( a - 1, b - 1 ) << "\n";
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}
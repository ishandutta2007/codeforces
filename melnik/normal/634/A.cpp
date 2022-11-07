#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
//#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < int > a;
int t[6 * maxn];
int pr[6 * maxn];


bool correct( int sz ) {
    int n = a.size();
    pr[0] = 0;
    for ( int i = 1; i < n; i++ ) {
        int j = pr[i - 1];
        while ( j > 0 && a[j] != a[i] )
            j = pr[j - 1];
        if ( a[j] == a[i] )
            ++j;
        pr[i] = j;
        if ( j == sz )
            return 1;
    }
    return 0;
}



int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    int n, x;
    scanf ( "%d", &n );
    int j;
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d", &x );
        if ( x != 0 )
            a.pb( x );
    }
    a.pb( -1 );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d", &t[j] );
        if ( t[j] )
            a.pb( t[j] );
    }
    for ( int j = 0; j < n; j++ )
        if ( t[j] )
            a.pb( t[j] );
    if ( correct( n - 1 ) )
        printf ( "YES" );
    else
        printf ( "NO" );
    return 0;
}
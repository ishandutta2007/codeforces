#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
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
const int base = 1e6 + 3;

int bin( int c, ll st ) {
    if ( st == 0LL )
        return 1;
	int cnt = bin( c, st / 2LL );
	if ( st & 1LL )
		return ( 1LL * c * cnt * cnt ) % base;
	return ( 1LL * cnt * cnt ) % base;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll day = 1LL;
    if ( n <= 62 )
    	for ( int j = 0; j < n; j++ )
    		day *= 2LL;
    if ( day != 1 && k > day ) {
    	printf ( "1 1\n" );
    	return 0;
    }
    int zn = bin( 2, n );
    int er;
    if ( k > 1LL * base )
    	er = 0;
    else {
    	er = 1;
    	for ( int j = 1; j <= k - 1LL; j++ )
    		er = ( 1LL * er * ( zn - j ) ) % base;
    }
    zn = bin( zn, k - 1LL );
    zn -= er;
    if ( zn < 0 )
    	zn += base;
   	ll cur = 2LL;
   	ll toDiv = 0LL;
   	while ( k - 1LL >= cur ) {
   		toDiv += ( k - 1LL ) / cur;
   		cur *= 2LL;
   	}
   	int ch = bin( 2, n );
   	ch = bin( ch, k - 1LL );
   	int toMulti = bin( bin( 2, toDiv ), base - 2 );
   	cout << ( 1LL * zn * toMulti ) % base << ' ' << ( 1LL * ch * toMulti ) % base << endl;
    return 0;
}
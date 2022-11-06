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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1e9 + 7;

int a[maxn];
int b[maxn];
int fact[maxn];

int bin( int x, int st ) {
	if ( !st )
		return 1;
	int cur = bin( x, st / 2 );
	cur = ( 1LL * cur * cur ) % base;
	if ( st & 1 )
		return ( 1LL * cur * x ) % base;
	return cur;
}

int getC( int x, int y ) {
	int ans = ( 1LL * fact[y] * bin( fact[x], base - 2 ) ) % base;
	return ( 1LL * ans * bin( fact[y - x], base - 2 ) ) % base;
}

int solution( int n ) {
	if ( n == 1 )
		return a[0];
	if ( n & 1 ) {
		for ( int j = 0; j < n; j += 2 ) {
			b[j] = ( a[j] + a[j + 1] ) % base;
			b[j + 1] = ( a[j + 1] - a[j + 2] + base ) % base;
		}
		--n;
	} else
        for ( int j = 0; j < n; j++ )
            b[j] = a[j];
	int cnt = ( n - 2 ) / 2;
	int c1 = 0;
	for ( int j = 0; j < n; j += 2 )
		c1 = ( 1LL * c1 + 1LL * b[j] * getC( j / 2, cnt ) ) % base;
	int c2 = 0;
	for ( int j = 1; j < n; j += 2 )
		c2 = ( 1LL * c2 + 1LL * b[j] * getC( ( j - 1 ) / 2, cnt ) ) % base;
	if ( cnt & 1 )
		return ( c1 - c2 + base ) % base;
	return ( c1 + c2 ) % base;
}

int c[maxn];

int brute( int n ) {
	for ( int j = 0; j < n; j++ )
		b[j] = a[j];
	int type = 0;
	while ( n != 1 ) {
		for ( int j = 0; j < n - 1; j++ ) {
			if ( type )
				c[j] = ( b[j] - b[j + 1] + base ) % base;
			else
				c[j] = ( b[j] + b[j + 1] ) % base;
			type ^= 1;
		}
		for ( int j = 0; j < n; j++ )
			b[j] = c[j];
		--n;
	}
	return b[0];
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);

    fact[0] = 1;
	for ( int j = 1; j < maxn; j++ )
		fact[j] = ( 1LL * fact[j - 1] * j ) % base;

    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    printf ( "%d\n", solution( n ) );

//     int it = 10000;
//     while ( it-- ) {
//     	int n = 1 + rand() % 100;
//     	for ( int j = 0; j < n; j++ )
//     		a[j] = rand();
//     	if ( solution( n ) != brute( n ) )
//     		puts( "kek" );
// //        puts( "+" );
//     }
//     puts( "all good" );
    return 0;
}
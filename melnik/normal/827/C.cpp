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
const int base = 1073676287;

char t[maxn];
char e[maxn];

int fw[maxn][10][10][4];

inline int convert( char x ) {
	if ( x == 'A' )
		return 0;
	if ( x == 'T' )
		return 1;
	if ( x == 'G' )
		return 2;
	return 3;
}

inline int sum (int r, int j, int step, int letter)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += fw[r][j][step][letter];
	return result;
}

inline void update (int i, int j, int step, int letter, int delta, int n)
{
	for (; i < n; i = (i | (i+1)))
		fw[i][j][step][letter] += delta;
}


void init( int n ) {
	for ( int j = 0; j < 10; j++ )
		for ( int step = 1; step <= 10; step++ )
			for ( int letter = 0; letter < 4; letter++ )
				for ( int i = j; i < n; i += step )
					if ( convert( t[i] ) == letter )
						update( i, j, step, letter, 1, n );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    gets( t );
    int n = strlen( t );
    init( n );
    int q;
    scanf ( "%d", &q );
    while ( q-- ) {
    	int type;
    	scanf ( "%d", &type );
    	if ( type == 1 ) {
    		int pos;
    		scanf ( "%d ", &pos );
    		char cur = getchar();
    		--pos;
    		for ( int j = 0; j < 10; j++ )
    			for ( int step = 1; step <= 10; step++ ) {
    				if ( pos < j ) 
    					continue;
    				if ( ( pos - j ) % step == 0 )
    					update( pos, j, step, convert( t[pos] ), -1, n );
    			}

    		t[pos] = cur;
    		for ( int j = 0; j < 10; j++ )
    			for ( int step = 1; step <= 10; step++ ) {
    				if ( pos < j ) 
    					continue;
    				if ( ( pos - j ) % step == 0 )
    					update( pos, j, step, convert( t[pos] ), 1, n );
    			}
    	} 
    	if ( type == 2 ) {
    		int l, r;
    		scanf ( "%d %d ", &l, &r );
    		--l;
    		--r;
    		gets( e );
    		int len = strlen( e );

    		int ans = 0;
    		for ( int j = 0; j < len; j++ )
    			ans += sum( r, ( l + j ) % len, len, convert( e[j] ) ) -
    				sum( l - 1, ( l + j ) % len, len, convert( e[j] ) );

    		printf( "%d\n", ans );

    		for ( int j = 0; j < len + 5; j++ )
    			e[j] = e[maxn - 1];
    	}
    }
    return 0;
}
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

pair < int, int > Hl, Hr, Vh, Vd, MainD1, MainD2, SecD1, SecD2;

void updateH( int x, int y, int x0, int y0, char type ) {
	if ( y < y0 ) {
		if ( !Hl.f || Hl.s < y )
			Hl = mp( type, y );
		return;
	}
	if ( !Hr.f || Hr.s > y )
		Hr = mp( type, y );
}

void updateV( int x, int y, int x0, int y0, char type ) {
	if ( x < x0 ) {
		if ( !Vh.f || Vh.s < x )
			Vh = mp( type, x );
		return;
	}
	if ( !Vd.f || Vd.s > x )
		Vd = mp( type, x );
}

void updateMainD( int x, int y, int x0, int y0, char type ) {
	int delta = abs( x - x0 );
	if ( x < x0 ) {
		if ( !MainD1.f || MainD1.s > delta )
			MainD1 = mp( type, delta );
		return;
	}
	if ( !MainD2.f || MainD2.s > delta )
		MainD2 = mp( type, delta );
}

void updateSecD( int x, int y, int x0, int y0, char type ) {
	int delta = abs( x - x0 );
	if ( x < x0 ) {
		if ( !SecD1.f || SecD1.s > delta )
			SecD1 = mp( type, delta );
		return;
	}
	if ( !SecD2.f || SecD2.s > delta )
		SecD2 = mp( type, delta );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    int x0, y0;
    scanf ( "%d%d%d\n", &n, &x0, &y0 );
    for ( int j = 0; j < n; j++ ) {
    	int x, y;
    	char type;
    	scanf ( "%c %d %d\n", &type, &x, &y );
    	if ( x == x0 )
    		updateH( x, y, x0, y0, type );
    	if ( y == y0 )
    		updateV( x, y, x0, y0, type );
    	int delta1 = x - x0;
    	int delta2 = y - y0;
    	if ( delta1 == delta2 )
    		updateMainD( x, y, x0, y0, type );
    	if ( delta1 == -delta2 )
    		updateSecD( x, y, x0, y0, type );
    }
    if ( Hl.f == 'R' || Hl.f == 'Q' ) {
    	puts( "YES" );
    	return 0;
    }
    if ( Hr.f == 'R' || Hr.f == 'Q' ) {
    	puts( "YES" );
    	return 0;
    }
    if ( Vh.f == 'R' || Vh.f == 'Q' ) {
    	puts( "YES" );
    	return 0;
    }
    if ( Vd.f == 'R' || Vd.f == 'Q' ) {
    	puts( "YES" );
    	return 0;
    }

    if ( MainD1.f == 'B' || MainD1.f == 'Q' ) {
    	puts( "YES" );
    	return 0;
    }
    if ( MainD2.f == 'B' || MainD2.f == 'Q' ) {
    	puts( "YES" );
    	return 0;
    }
    if ( SecD1.f == 'B' || SecD1.f == 'Q' ) {
    	puts( "YES" );
    	return 0;
    }
    if ( SecD2.f == 'B' || SecD2.f == 'Q' ) {
    	puts( "YES" );
    	return 0;
    }
    puts( "NO" );
    return 0;
}
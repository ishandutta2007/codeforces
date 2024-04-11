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

vector < int > ans1;
vector < int > ans2;

int ask( int x1, int y1, int x2, int y2 ) {
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	int a;
	cin >> a;
	return a;
}

int ask2( int x1, int y1, int x2, int y2 ) {
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	int a;
	cin >> a;
	if ( ans1[0] >= x1 && ans1[1] >= y1 && ans1[2] <= x2 && ans1[3] <= y2 )
		--a;
	return a;
}

void findAns( int x2, int y2 ) {
	int l, r;
	l = 1, r = x2;
	while ( r - l > 1 ) {
		int mid = ( l + r ) >> 1;
		int cnt = ask( mid, 1, x2, y2 );
    	if ( cnt )
    		l = mid;
        else
            r = mid - 1;
	}
	if ( !ask( r, 1, x2, y2 ) )
        ans1.pb( l );
    else
        ans1.pb( r );
	l = 1, r = y2;
	while ( r - l > 1 ) {
		int mid = ( l + r ) >> 1;
		int cnt = ask( 1, mid, x2, y2 );
    	if ( cnt )
    		l = mid;
        else
            r = mid - 1;
	}
	if ( !ask( 1, r, x2, y2 ) )
        ans1.pb( l );
    else
        ans1.pb( r );
    ans1.pb( x2 );
	ans1.pb( y2 );
}

void findAns2( int n ) {
	int l, r;
	l = 1, r = n;
	while ( r - l ) {
		int mid = ( l + r ) >> 1;
		int cnt = ask2( 1, 1, mid, n );
		if ( !cnt )
			l = mid + 1;
		else
			r = mid;
	}
	int x2 = l;

	l = 1, r = n;
	while ( r - l ) {
		int mid = ( l + r ) >> 1;
		int cnt = ask2( 1, 1, x2, mid );
		if ( !cnt )
			l = mid + 1;
		else
			r = mid;
	}
	int y2 = l;

	l = 1, r = x2;
	while ( r - l > 1 ) {
		int mid = ( l + r ) >> 1;
		int cnt = ask2( mid, 1, x2, y2 );
		if ( cnt )
    		l = mid;
        else
            r = mid - 1;
	}
	if ( !ask2( r, 1, x2, y2 ) )
        ans2.pb( l );
    else
        ans2.pb( r );

	l = 1, r = y2;
	while ( r - l > 1 ) {
		int mid = ( l + r ) >> 1;
		int cnt = ask2( 1, mid, x2, y2 );
		if ( cnt )
    		l = mid;
        else
            r = mid - 1;
	}
	if ( !ask2( 1, r, x2, y2 ) )
        ans2.pb( l );
    else
        ans2.pb( r );


	ans2.pb( x2 );
	ans2.pb( y2 );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    int l, r;
    l = 1, r = n;
    while ( r - l ) {
    	int mid = ( l + r ) >> 1;
    	int cnt = ask( 1, 1, mid, n );
    	if ( !cnt )
    		l = mid + 1;
    	else    
    		r = mid;
    }
    int x2 = l;
    l = 1, r = n;
    while ( r - l ) {
    	int mid = ( l + r ) >> 1;
    	int cnt = ask( 1, 1, x2, mid );
    	if ( !cnt )
    		l = mid + 1;
    	else
    		r = mid;
    }
    int y2 = l;
    findAns( x2, y2 );


   	findAns2( n );
   	cout << "! ";
   	for ( int j = 0; j < 4; j++ )
    	cout << ans1[j] << ' ';
    for ( int j = 0; j < 4; j++ )
    	cout << ans2[j] << ' ';
    return 0;
}
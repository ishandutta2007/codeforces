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

struct node {
	int cnt;
	node *l, *r;
	node () {
		cnt = 0;
		l = r = NULL;
	}
	// node () {

	// }
};

typedef node * pnode;
vector < int > a;

void update( pnode &T, int cur, int t ) {
	if ( cur == 18 ) {
		T -> cnt += t;
		return;
	}
	if ( a[cur] ) {
		if ( T -> r )
			update( T -> r, cur + 1, t );
		else
			{
				T -> r = new node();
				update( T -> r, cur + 1, t );
			}
		T -> cnt += t;
		return;
	}
	if ( T -> l )
		update( T -> l, cur + 1, t );
	else
		{
			T -> l = new node();
			update( T -> l, cur + 1, t );
		}
	T -> cnt += t;
}

void findAns( pnode T, int cur ) {
	if ( cur == 18 ) {
		printf ( "%d\n", T -> cnt );
		return;
	}
	if ( a[cur] ) {
		if ( T -> r )
			findAns( T -> r, cur + 1 );
		else
			printf ( "0\n" );
		return;
	}
	if ( T -> l )
		findAns( T -> l, cur + 1 );
	else
		printf ( "0\n" );
}

pnode T;

void add( ll x ) {
	a.clear();
	while ( x ) {
		int cnt = x % 10LL;
		if ( cnt & 1 )
			a.pb( 1 );
		else
			a.pb( 0 );
        x /= 10LL;
	}
	while ( a.size() != 18 )
		a.pb( 0 );
	reverse( a.begin(), a.end() );
	update( T, 0, 1 );
}

void erase( ll x ) {
	a.clear();
	while ( x ) {
		int cnt = x % 10LL;
		if ( cnt & 1 )
			a.pb( 1 );
		else
			a.pb( 0 );
        x /= 10LL;
	}
	while ( a.size() != 18 )
		a.pb( 0 );
	reverse( a.begin(), a.end() );
	update( T, 0, -1 );
}

void calc( ll x ) {
	a.clear();
	while ( x ) {
		int cnt = x % 10LL;
		if ( cnt & 1 )
			a.pb( 1 );
		else
			a.pb( 0 );
        x /= 10LL;
	}
	while ( a.size() != 18 )
		a.pb( 0 );
	reverse( a.begin(), a.end() );
	findAns( T, 0 );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    T = new node();
    T -> cnt = 0;
    T -> l = T -> r = NULL;
    int q;
    scanf ( "%d\n", &q );
    while ( q-- ) {
    	char t;
    	ll x;
    	scanf ( "%c%lld\n", &t, &x );
    	if ( t == '+' )
    		add( x );
    	if ( t == '-' )
    		erase( x );
    	if ( t == '?' )
    		calc( x );
    }
    return 0;
}
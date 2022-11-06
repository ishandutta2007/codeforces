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
	int sum;
	node *l, *r;
	node () {
		sum = 0;
		l = r = NULL;
	}
};

typedef node * pnode;

int getSum( pnode T ) {
	return T ? T -> sum : 0;
}

vector < int > a;
vector < int > b;

void Add( pnode T, int pos ) {
	++T -> sum;
	if ( pos == 30 )
		return;
	if ( !a[pos] ) {
		if ( !T -> l )
			T -> l = new node();
		Add( T -> l, pos + 1 );
	} else {
		if ( !T -> r )
			T -> r = new node();
		Add( T -> r, pos + 1 );
	}
}

void Delete( pnode T, int pos ) {
	--T -> sum;
	if ( pos == 30 )
		return;
	if ( !a[pos] )
		Delete( T -> l, pos + 1 );
	else
		Delete( T -> r, pos + 1 );
}

int Ask( pnode T, int pos ) {
	if ( !T )
		return 0;
	if ( pos == 30 )
		return 0;
	if ( !b[pos] ) {
		if ( !a[pos] )
			return Ask( T -> l, pos + 1 );
		return Ask( T -> r, pos + 1 );
	}
	if ( !a[pos] )
		return getSum( T -> l ) + Ask( T -> r, pos + 1 );
	return getSum( T -> r ) + Ask( T -> l, pos + 1 );
}

pnode T = new node();

void convert( int x ) {
	a.clear();
	while ( x ) {
		a.pb( x % 2 );
		x /= 2;
	}
	while ( a.size() != 30 )
		a.pb( 0 );
	reverse( a.begin(), a.end() );
}

void convertL( int x ) {
	b.clear();
	while ( x ) {
		b.pb( x % 2 );
		x /= 2;
	}
	while ( b.size() != 30 )
		b.pb( 0 );
	reverse( b.begin(), b.end() );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int q;
    scanf ( "%d", &q );
    while ( q-- ) {
    	int type;
    	scanf ( "%d", &type );
    	if ( type == 1 ) {
    		int x;
    		scanf ( "%d", &x );
    		convert( x );
    		Add( T, 0 );
    	}
    	if ( type == 2 ) {
    		int x;
    		scanf ( "%d", &x );
    		convert( x );
    		Delete( T, 0 );
    	}
    	if ( type == 3 ) {
    		int x, l;
    		scanf ( "%d%d", &x, &l );
    		convert( x );
    		convertL( l );
    		printf ( "%d\n", Ask( T, 0 ) );
    	}
    }
    return 0;
}
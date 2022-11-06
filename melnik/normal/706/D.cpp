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

vector < int > a;

struct node {
	int sum;
	node *l, *r;
	node () {
		l = r = NULL;
		sum = 0;
	}
};

typedef node * pnode;

int getSum( pnode T ) {
	return T ? T -> sum : 0;
}


void update( pnode T, int pos, int type ) {
	if ( pos == 30 ) {
		T -> sum += type;
		return;
	}
	if ( !a[pos] ) {
		if ( !T -> l )
			T -> l = new node();
		update( T -> l, pos + 1, type );
	}
	if ( a[pos] ) {
		if ( !T -> r )
			T -> r = new node();
		update( T -> r, pos + 1, type );
	}
	T -> sum = getSum( T -> l ) + getSum( T -> r );
}

void getAns( pnode T, int pos, int cur ) {
	if ( pos == 30 ) {
		printf ( "%d\n", cur );
		return;
	}
	cur *= 2;
	if ( !a[pos] ) {
		if ( getSum( T -> r ) )
			getAns( T -> r, pos + 1, cur + 1 );
		else
			getAns( T -> l, pos + 1, cur );
	}
	if ( a[pos] ) {
		if ( getSum( T -> l ) )
			getAns( T -> l, pos + 1, cur + 1 );
		else
			getAns( T -> r, pos + 1, cur );
	}
}

pnode T;

void insert( int x ) {
	a.clear();
	while ( x ) {
		a.pb( x % 2 );
		x /= 2;
	}
	while ( a.size() != 30 )
		a.pb( 0 );
	reverse( a.begin(), a.end() );
	update( T, 0, 1 );
}

void erase( int x ) {
	a.clear();
	while ( x ) {
		a.pb( x % 2 );
		x /= 2;
	}
	while ( a.size() != 30 )
		a.pb( 0 );
	reverse( a.begin(), a.end() );
	update( T, 0, -1 );
}

void ans( int x ) {
	a.clear();
	while ( x ) {
		a.pb( x % 2 );
		x /= 2;
	}
	while ( a.size() != 30 )
		a.pb( 0 );
	reverse( a.begin(), a.end() );
	getAns( T, 0, 0 );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int q;
    scanf ( "%d\n", &q );
    T = new node();
    insert( 0 );
    while ( q-- ) {
    	char type;
    	int x;
    	scanf ( "%c %d\n", &type, &x );
    	if ( type == '+' )
    		insert( x );
    	if ( type == '-' )
    		erase( x );
    	if ( type == '?' )
    		ans( x );
    }
    return 0;
}
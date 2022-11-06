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
// #include <unordered_map>


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

char type[maxn];
int c1[maxn];
int c2[maxn];

pair < int, int > precalc[1 << 16];
vector < int > updates[1 << 16];

struct state {
	int mask,
		currentQuantityR,
		currentQuantityB,
		cost;
	state( int _q1, int _q2, int _q3, int _q4 ) {
		mask = _q1;
		currentQuantityR = _q2;
		currentQuantityB = _q3;
		cost = _q4;
	}
	bool operator < ( const state &x ) const {
		if ( x.mask != this -> mask )
			return this -> mask < x.mask;
		if ( x.currentQuantityR != this -> currentQuantityR )
			return this -> currentQuantityR < x.currentQuantityR;
		if ( x.currentQuantityB != this -> currentQuantityB )
			return this -> currentQuantityB < x.currentQuantityB;
		return this -> cost < x.cost;
	}
};

queue < state > forB;
vector < state > forB2;

int bfs( int n ) {

	for ( int curMask = 0; curMask < ( 1 << n ); curMask++ ) {
		int redCards = 0;
		int blueCards = 0;
		for ( int j = 0; j < n; j++ )
			if ( curMask & ( 1 << j ) )
				if ( type[j] == 'R' )
					++redCards;
				else
					++blueCards;
		precalc[curMask] = mp( redCards, blueCards );
	}

	for ( int curMask = 0; curMask < ( 1 << n ); curMask++ ) 
		for ( int j = 0; j < n; j++ )
			if ( !( curMask & ( 1 << j ) ) )
				updates[curMask].pb( j );
		

	forB.push( state( 0, 0, 0, 0 ) );
	int ans = inf;
	while ( !forB.empty() || !forB2.empty() ) {
		while ( !forB.empty() ) {
			int curMask = forB.front().mask;
			int curR = forB.front().currentQuantityR;
			int curB = forB.front().currentQuantityB;
			int curCost = forB.front().cost;
			int redCards = precalc[curMask].f;
			int blueCards = precalc[curMask].s;
			if ( curMask == ( 1 << n ) - 1 ) {
				ans = min( curCost, ans );
				forB.pop();
				continue;
			}
			forB.pop();

			int sz = updates[curMask].size();
			for ( int j = 0; j < sz; j++ ) {
				int pos = updates[curMask][j];
				int costRed = max( c1[pos] - redCards, 0 );
				int costBlue = max( c2[pos] - blueCards, 0 );
				int delta = max( 0, costRed - curR );
				delta = max( delta, costBlue - curB );
				int newRed = curR + delta - costRed;
				int newBlue = curB + delta - costBlue;
				int newMask = curMask | ( 1 << pos );

				forB2.pb( state( newMask, newRed, newBlue, curCost + delta ) );
			}
	    }
	    sort( forB2.begin(), forB2.end() );
	    int sz = forB2.size();
	    int l, r;
	    l = r = 0;
	    while ( l < sz ) {
	    	forB.push( forB2[l] );
	    	while ( r < sz && forB2[r].mask == forB2[l].mask &&
	    		forB2[r].currentQuantityR == forB2[l].currentQuantityR &&
	    		forB2[r].currentQuantityB == forB2[l].currentQuantityB )
	    		++r;
	    	l = r;
	    }

	    forB2.clear();
	}
	return ans + n;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d\n", &n );
   	for ( int j = 0; j < n; j++ )
   		scanf ( "%c%d%d\n", &type[j], &c1[j], &c2[j] );
   	printf ( "%d\n", bfs( n ) );
    return 0;
}
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
vector < int > b;
ll answer;

struct node {
	int v;
	node * l, * r;
	ll costL, costR;
	node () {}
	node ( int _v ) {
		v = _v;
		l = r = NULL;
		costL = costR = 0LL;
	}
};

typedef node * pnode;

void add( pnode T, ll cur, ll need, int curPos, int cost ) {
	if ( cur == need )
		return;
	cur *= 2LL;
	cur += 1LL * a[curPos];
	if ( !a[curPos] ) {
		if ( !( T -> l ) )
			T -> l = new node( cur );
		T -> costL += 1LL * cost;
		add( T -> l, cur, need, curPos + 1, cost ); 
	}
	if ( a[curPos] ) {
		if ( !( T -> r ) )
			T -> r = new node( cur );
		T -> costR += 1LL * cost;
		add( T -> r, cur, need, curPos + 1, cost );
	}
}

void calc( pnode T, ll cur, ll need, int curPos, int mn ) {
	if ( cur == need )
		return;
	cur *= 2LL;
	cur += 1LL * a[curPos];
	if ( !a[curPos] ) {
		if ( !( T -> l ) )
			return;
		answer += 1LL * mn * T -> costL;
		calc( T -> l, cur, need, curPos + 1, mn );
	}
	if ( a[curPos] ) {
		if ( !( T -> r ) )
			return;
		answer += 1LL * mn * T -> costR;
		calc( T -> r, cur, need, curPos + 1, mn );
	}
}

ll findLCA( ll u, ll v ) {
	a.clear();
	b.clear();
	while ( u ) {
		a.pb( u % 2LL );
		u /= 2LL;
	}
	while ( v ) {
		b.pb( v % 2LL );
		v /= 2LL;
	}
	reverse( a.begin(), a.end() );
	reverse( b.begin(), b.end() );
	int sz = min( a.size(), b.size() );
	ll ans = 0LL;
	for ( int j = 0; j < sz; j++ ) {
		if ( a[j] != b[j] )
			return ans;
		ans *= 2LL;
		ans += 1LL * a[j];
	}
	return ans;
}

pnode T;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int q;
    scanf ( "%d", &q );
    T = new node( 1 ); 
    while ( q-- ) {
    	int type;
    	scanf ( "%d", &type );

    	if ( type == 1 ) {
    		ll u, v;
    		int w;
    		cin >> u >> v >> w;


    		a.clear();
    		ll U = u, V = v;
    		while ( u ) {
    			a.pb( u % 2LL );
    			u /= 2LL;
    		}
    		u = U;
    		a.pop_back();
    		reverse( a.begin(), a.end() );
    		add( T, 1LL, u, 0, w );


    		a.clear();
    		while ( v ) {
    			a.pb( v % 2LL );
    			v /= 2LL;
    		}
    		v = V;
    		a.pop_back();
    		reverse( a.begin(), a.end() );
    		add( T, 1LL, v, 0, w );


    		ll c = findLCA( u, v );
    		a.clear();
    		ll C = c;
    		while ( c ) {
    			a.pb( c % 2LL );
    			c /= 2LL;
    		}
    		c = C;
    		a.pop_back();
    		reverse( a.begin(), a.end() );
    		add( T, 1LL, c, 0, -2 * w );
    	}

    	if ( type == 2 ) {
    		answer = 0LL;
    		ll u, v;
    		cin >> u >> v;


    		a.clear();
    		ll U = u, V = v;
    		while ( u ) {
    			a.pb( u % 2LL );
    			u /= 2LL;
    		}
    		u = U;
    		a.pop_back();
    		reverse( a.begin(), a.end() );
    		calc( T, 1LL, u, 0, 1 );


    		a.clear();
    		while ( v ) {
    			a.pb( v % 2LL );
    			v /= 2LL;
    		}
    		v = V;
    		a.pop_back();
    		reverse( a.begin(), a.end() );
    		calc( T, 1LL, v, 0, 1 );


    		ll c = findLCA( u, v );
    		a.clear();
    		ll C = c;
    		while ( c ) {
    			a.pb( c % 2LL );
    			c /= 2LL;
    		}
    		c = C;
    		a.pop_back();
    		reverse( a.begin(), a.end() );
    		calc( T, 1LL, c, 0, -2 );
    		cout << answer << endl;
    	}
    } 
    return 0;
}
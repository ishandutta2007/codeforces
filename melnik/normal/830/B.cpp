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
    int prior, sz, num;
    int curMin;
    node *l, *r;
    node () {}
    node ( int _sz, int _num ) {
        sz = _sz;
        num = _num;
        prior = ( rand() << 16 ) + rand();
        l = r = NULL;
        curMin = _num;
    }
};

typedef node * pnode;

inline int min3( int x, int y, int z ) {
	return min( x, min( y, z ) );
}

inline int get_size( pnode T ) {
    return T ? T -> sz : 0;
}

inline int getMin( pnode T ) {
	return T ? T -> curMin : inf;
}

inline void merge ( pnode &T, pnode L, pnode R ) {
    if ( !L ) {
        T = R;
        return;
    }
    if ( !R ) {
        T = L;
        return;
    }
    if ( L -> prior > R -> prior ) {
        merge( L -> r, L -> r, R );
        T = L;
        T -> sz = get_size( T -> l ) + get_size( T -> r ) + 1;
        T -> curMin = min3( getMin( T -> l ), getMin( T -> r ), T -> num );
        return;
    }
    merge( R -> l, L, R -> l );
    T = R;
    T -> sz = get_size( T -> l ) + get_size( T -> r ) + 1;
    T -> curMin = min3( getMin( T -> l ), getMin( T -> r ), T -> num );
}

inline void split ( pnode T, int x, pnode &L, pnode &R ) {
    if ( !T ) {
        L = R = NULL;
        return;
    }
    if ( get_size( T -> l ) + 1 > x ) {
        split( T -> l, x, L, T -> l );
        R = T;
        R -> sz = get_size( R -> l ) + get_size( R -> r ) + 1;
        R -> curMin = min3( getMin( R -> l ), getMin( R -> r ), R -> num );
        return;
    }
    split( T -> r, x - get_size( T -> l ) - 1, T -> r, R );
    L = T;
    L -> sz = get_size( L -> l ) + get_size( L -> r ) + 1;
    L -> curMin = min3( getMin( L -> l ), getMin( L -> r ), L -> num );
}

int cnt;

inline void Find( pnode T, int x ) {
	if ( getMin( T -> l ) <= x ) {
		Find( T -> l, x );
		return;
	}
	cnt += get_size( T -> l );
	if ( T -> num == x )
		return;
	++cnt;
	Find( T -> r, x );
}

pnode T = NULL;
pnode L = NULL;
pnode M = NULL;
pnode R = NULL;

int a[maxn];


int main()
{
    srand( base );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ ) {
    	scanf ( "%d", &a[j] );
    	merge( T, T, new node( 1, a[j] ) );
    }
    sort( a, a + n );
    ll ans = 0LL;
    for ( int j = 0; j < n; j++ ) {
    	cnt = 0;
    	Find( T, a[j] );
    	split( T, cnt, L, R );
    	split( R, 1, M, R );
    	ans += 1LL * cnt + 1LL;
    	merge( T, R, L );
    }
    cout << ans << endl;
    return 0;
}
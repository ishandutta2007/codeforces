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

const int maxn = 1e5;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

struct node {
    int x, max_y, prior;
    set < int > all_y;
    node *l, *r;
    node () {}
    node ( int _x, int _y ) {
        x = _x;
        max_y = _y;
        all_y.insert( _y );
        prior = ( rand() << 16 ) + rand();
        l = r = NULL;
    }
};

typedef node * pnode;

inline int getY( pnode T ) {
    if ( !T ) return -inf;
    return T -> max_y;
}

inline int get_maxY_forX ( pnode T ) {
    if ( !T ) return -inf;
    return *( T -> all_y.rbegin() );
}

inline int max3( int a, int b, int c ) {
    return max( a, max( b, c ) );
}

inline void merge( pnode &T, pnode L, pnode R ) {
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
        T -> max_y = max3( *( T -> all_y.rbegin() ) , getY( T -> l ), getY( T -> r ) );
        return;
    }
    merge( R -> l, L, R -> l );
    T = R;
    T -> max_y = max3( *( T -> all_y.rbegin() ), getY( T -> l ), getY( T -> r ) );
}

inline void split( pnode T, int key, pnode &L, pnode &R ) {
    if ( !T ) {
        L = R = NULL;
        return;
    }
    if ( T -> x > key ) {
        split( T -> l, key, L, T -> l );
        R = T;
        R -> max_y = max3( *( R -> all_y.rbegin() ), getY( R -> l ), getY( R -> r ) );
        return;
    }
    split( T -> r, key, T -> r, R );
    L = T;
    L -> max_y = max3( *( L -> all_y.rbegin() ), getY( L -> l ), getY( L -> r ) );
}

inline void find_ans( pnode T, int _x, int _y ) {
    if ( T -> l && T -> l -> max_y > _y ) {
        find_ans( T -> l, _x, _y );
        return;
    }
    if ( get_maxY_forX( T ) > _y ) {
        printf ( "%d %d\n", T -> x, *( T -> all_y.upper_bound( _y ) ) );
        return;
    }
    find_ans( T -> r, _x, _y );
}

pnode T = new node;
pnode L = new node;
pnode M = new node;
pnode R = new node;

inline void add( int _x, int _y ) {
    split( T, _x - 1, L, M );
    split( M, _x, M, R );
    if ( M ) {
        M -> all_y.insert( _y );
        M -> max_y = max( M -> max_y, _y );
    } else {
        M = new node( _x, _y );
    }
    merge( T, L, M );
    merge( T, T, R );
}

inline void erase( int _x, int _y ) {
    split( T, _x - 1, L, M );
    split( M, _x, M, R );
    M -> all_y.erase( _y );
    if ( M -> all_y.empty() ) {
        merge( T, L, R );
        return;
    }
    M -> max_y = *( M -> all_y.rbegin() );
    merge( T, L, M );
    merge( T, T, R );
}

inline void answer( int _x, int _y ) {
    split( T, _x, L, R );
    if ( !R || R -> max_y <= _y ) {
        printf ( "-1\n" );
        merge( T, L, R );
        return;
    }
    find_ans( R, _x, _y );
    merge( T, L, R );
}

string s;

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    T = NULL;
    int n, _x, _y;
    scanf( "%d", &n );
    while ( n-- ) {
        cin >> s;
        scanf ( "%d%d", &_x, &_y );
        if ( s[0] == 'a' ) {
            add( _x, _y );
        }
        if ( s[0] == 'f' ) {
            answer( _x, _y );
        }
        if ( s[0] == 'r' ) {
            erase( _x, _y );
        }
    }
    return 0;
}
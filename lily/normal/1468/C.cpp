#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int _w;

struct Money {
    bool operator()( pii a, pii b ) const {
	if( a.second == b.second ) {
	    return a.first < b.first;
	} else {
	    return a.second > b.second;
	}
    }
};

set<pii,Money> money;
set<pii> tim;

int main() {
    int q, nid = 1;
    _w = scanf( "%d", &q );
    while( q-- ) {
	int op;
	_w = scanf( "%d", &op );
	if( op == 1 ) {
	    int m;
	    _w = scanf( "%d", &m );
	    money.insert( pii(nid, m) );
	    tim.insert( pii(nid, m) );
	    ++nid;
	} else if( op == 2 ) {
	    pii now = *tim.begin();
	    tim.erase(now);
	    money.erase(now);
	    printf( "%d ", now.first );
	} else if( op == 3 ) {
	    pii now = *money.begin();
	    money.erase(now);
	    tim.erase(now);
	    printf( "%d ", now.first );
	} else {
	    assert(0);
	}
    }
    puts("");
    return 0;
}
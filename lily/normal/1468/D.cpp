#include <bits/stdc++.h>

using namespace std;
const int M = 200010;
int _w;

int n, m, a, b, s[M];
int cat, tot;

void init() {
    cat = abs(a-b) - 1;
    if( b > a ) {
	tot = b-1;
    } else {
	tot = n-b;
    }
}

bool check( int mid ) {
    for( int i = 1; i <= mid; ++i ) {
	if( s[i] + (mid-i+1) > tot )
	    return false;
    }
    return true;
}

void solve() {
    int low = 0, high = m;
    while( low < high ) {
	int mid = (low + high + 1)/2;
	if( check(mid) ) low = mid;
	else high = mid - 1;
    }
    printf( "%d\n", low );
}

int main() {
    int T;
    _w = scanf( "%d", &T );
    while( T-- ) {
	_w = scanf( "%d%d%d%d", &n, &m, &a, &b );
	for( int i = 1; i <= m; ++i )
	    _w = scanf( "%d", s+i );
	sort(s+1, s+m+1);
	init();
	m = min(m, cat);
	solve();
    }
    return 0;
}
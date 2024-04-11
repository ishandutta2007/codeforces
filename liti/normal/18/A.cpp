/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
typedef long double ld;
typedef pair<ld,ld> pdd;
const ld EPS = 1e-8;

pdd a[3];
int ans[3];
ld d[3];

int dx[] = {0,-1,1,0}; 
int dy[] = {1,0,0,-1};

ld di( pdd a, pdd b ) { 
	ld x = a.ff - b.ff;
	ld y = a.ss - b.ss;
	return x*x + y*y;
}

bool right() { 
	for(int i = 0 ; i < 3 ; i++ ){
		d[i] = di( a[i], a[(i+1)%3] ) ; 
	}
	sort( d, d + 3 ) ;
	if( abs( d[0] + d[1] - d[2] ) <= EPS ) 
		if( abs( sqrt(d[0]) + sqrt(d[1]) 
					- sqrt(d[2]) ) > EPS ) 
			return 1;
	return 0;
}

int calc( ) { 
	if( right() ) 
		return 2;

	pdd tmp = a[0];
		for(int k = 0 ; k < 4 ; k++ ) {
			a[0].ff = tmp.ff + dx[k];
			a[0].ss = tmp.ss + dy[k];
			if( right() ) {
				a[0] = tmp;
				return 1;
			}
		}
	a[0] = tmp;
	return 0;
}

int main() { 
	for(int i= 0 ; i < 3 ; i++ ) 
		cin >> a[i].ff >> a[i].ss;

	int m  = 0 ;
	for(int i = 0 ; i < 3 ; i++ ) {
		swap(a[i],a[0]);
		m = max( m,calc() );
		swap(a[i],a[0]);
	}

	cout << ( m == 0 ? "NEITHER" : 
			( m == 1 ? "ALMOST" : 
			  "RIGHT" ) ) << endl;
}
//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define SZ(x) ((int)(x).size())    
typedef long long ll    ;

int main() { 
    int n,m;
    cin >> n >> m; 
    int ans = 0 ; 
    int ld , lh;
    for( int i = 0 ; i < m ; i++ ) { 
	int d,h;
	cin >> d >> h;
	ans = max( ans , h ) ; 
	if( i == 0 && d != 1 ) 
	    ans = max( ans , h + d - 1 );
	if( i > 0 ) { 
	    int x = d - ld - abs( h - lh ) ; 
	    if( x < 0 ) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	    }
	    ans = max( max(h ,lh) + x / 2 , ans ) ; 

	}
	lh = h, ld = d;
    }
    if( ld != n ) { 
	ans = max( ans , lh + n - ld ); 
    }
    cout << ans << endl;
}
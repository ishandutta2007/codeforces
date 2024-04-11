/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef long double ld;
 
int main() { 
	int x1,y1,r1;
	int x2,y2,r2;
	cin >> x1 >> y1 >> r1; 
	cin >> x2 >> y2 >> r2; 

	ld dx = ( x1 - x2 ) ;
	ld dy = y1 - y2; 
	ld dist = sqrt( dx*dx  + dy*dy ) ; 
	cout << fixed << setprecision( 9 ) ; 
	if( r1 + r2 >= dist) { 
		if( (dist + r1 <= r2 || dist + r2 <= r1 ) ) { 
			cout << abs( max(r1 ,r2 ) - dist - min( r1 , r2 ) ) / 2.f << endl;
		} else 
			cout << 0 << endl;
		return 0;
	}
	cout << abs(dist - r1 - r2)/2 << endl;
}
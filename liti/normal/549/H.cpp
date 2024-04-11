//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef long double ld; 
const ld eps = 1e-12;

int main() { 
	int A,B,C,D;
	cin >> A >> B >> C >> D; 

	ld s = 0 , e = 1e9 + 10; 

	for( int i = 0 ; i < 200 ; i++ ) {
		ld m = ( s + e ) / 2; 
		ld a1 = (-m) - A, a2 = m - A; 
		ld b1 = (-m) - B, b2 = m - B; 
		ld c1 = (-m) - C, c2 = m - C; 
		ld d1 = (-m) - D, d2 = m - D; 

		ld s1 = min( a1 * d1 , min( a1 * d2 , 
					min( a2 * d1 , a2 * d2 ) ) ); 
		ld e1 = max( a1 * d1 , max( a1 * d2 , 
					max( a2 * d1 , a2 * d2 ) ) ) ; 
		ld s2 = min( b1 * c1 , min( b1 * c2 , 
					min( b2 * c1 , b2 * c2 ) ) ) ; 
		ld e2 = max( b1 * c1 , max( b1 * c2 , 
					max( b2 * c1 , b2 * c2 ) ) ); 

		ld a = max(s1,s2), b=min(e1,e2);
		if( a <= b ) 
			e = m;
		else
			s = m;
	}
	cout << fixed << setprecision(10) << e << endl;
}
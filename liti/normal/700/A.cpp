//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n,l,v1,v2,k; 

inline bool canDo( ld m ) { 
	ld tot = m * v1; 
	if( tot >= l ) return true;
	ld rem = l - tot; 

	ld each = rem/(v2-v1); 
//	cerr << each << endl;
	if( each > m ) return false; 

	ld go = ( 1 + (v2-v1)/ld(v1+v2) );
	ld v = each * go * (( n - 1 ) / k) + each; 
	return v <= m;
}

int main() { 
	cout << fixed << setprecision(15); 
	cerr << fixed << setprecision(15); 

	cin >> n >> l >> v1 >> v2 >> k;

	ld s = 0 , e = l; 
	for( int i = 0 ; i < 100 ; i++ ) { 
		ld m = (s+e)/2; 
		if( canDo(m) ) 
			e = m; 
		else
			s = m;
	}
	cout << e << endl;
}
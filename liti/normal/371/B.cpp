//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

int main() { 
	int a,b; 
	cin >> a >> b; 
	int x = __gcd(a,b);
	a /= x; b /= x; 
	int ans = 0; 
	while( a % 3 == 0 ) 
		a /= 3 , ans++; 
	while( a % 2 == 0 ) 
		a /= 2 , ans++; 
	while( a % 5 == 0 ) 
		a /= 5 , ans++; 
	if( a != 1 ) cout << -1 << endl;
	else { 
		swap( a , b );
		while( a % 3 == 0 ) 
			a /= 3 , ans++; 
		while( a % 2 == 0 ) 
			a /= 2 , ans++; 
		while( a % 5 == 0 ) 
			a /= 5 , ans++; 
		if( a != 1 ) cout << -1 << endl;
		else cout << ans << endl;
	}
}
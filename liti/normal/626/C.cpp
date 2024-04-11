//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 

const int maxN = 2000 * 1000 * 10 + 10; 
int main() { 
	int n,m; cin >> n >> m; 
	int a,b,c; a = b = c = 0; 
	for( int i = 2 ; i < maxN ; i++ ) { 
		if( i % 2 == 0 && i % 3 == 0 ) 
			c++; 
		else if( i % 2 == 0 ) 
			a++; 
		else if( i % 3 == 0 ) 
			b++; 

		// a + x >= n &&  b + c - x >= m
		int d = c; 
		if( a + c < n ) continue;
		if( b + c < m ) continue; 
		if( a + b + c < m + n ) continue; 
		d -= max( 0 , n - a ); 
		if( b + d < m ) continue;
		cout << i << endl;
		return 0; 
	}
}
/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*10  + 10;
int a[maxN];
int b[maxN];

int main() {
	int n;
	cin >> n;

	for( int i = 0 ; i < n;  i++ ) 
		cin >> a[i];
	copy( a , a + n , b ) ; 
	sort( b , b + n ) ; 

	int cnt = 0 ;
	for( int i = 0 ; i < n ; i++ ) 
		if( a[i] != b[i] ) 
			cnt++;
	cout << ( cnt <= 2 ? "YES" : "NO" ) << endl; 
}
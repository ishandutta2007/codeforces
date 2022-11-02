//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
#define SZ(x) ((int) (x).size())

int main() { 
	ll a,b; cin >> a >> b; 
	int ans = 0; 
	do { 
		int k = 0; 
		for( int i = 0 ; i < 63 ; i++ ) 
			if( ( a>>i) & 1 ) 
				k = i; 
		int last = -1; 
		for( int i = 0 ; i < k ; i++ ) 
			if( ((a>>i) & 1) == 0 ) { 
				a ^= ( 1ll<<i ); 
				last = i; 
			}
		if( last != -1 ) { 
			a ^= ( 1ll << last ); 
			if( a <= b ) 
				ans++;
		}
		a++; 
	} while( a <= b ); 
	cout << ans << endl;
}
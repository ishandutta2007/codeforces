/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10 ; 
const int mod = 1e9 + 7; 

int fen[maxN];

void add( int x , int val ) { 
	x++;
	for( ; x < maxN ; x += x & (-x) ) 
		fen[x] = ( fen[x] +val ) % mod;
}

int get( int x ) { 
	x++;
	int ret = 0;
	for( ; x > 0 ; x -= x & (-x) ) 
		ret = ( ret + fen[x] ) % mod;
	return ret;
}

int main() { 
	int n , m,k ; 
	n = maxN;
	cin >> m >> k;
	add( 0 , 1 ) ; 
	for( int i = 1 ; i <= n; i++ ) { 
		add( i , ( 1 + ( i - k >= 0 ? get( i - k ) : 0  ) ) % mod  ) ;
	}

	for( int i = 0 ; i < m ; i++ ) { 
		int a,b;
		cin >> a >> b;
		cout << ( ( get(b) - get(a-1) ) % mod + mod ) % mod << endl;
	}
}
//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int a[2][2]; 
inline void die() { 
	cout << "Impossible" << endl;
	exit(0);
}

const int maxN = 1000 * 1000 * 4; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	for( int i = 0 ; i < 2 ; i++ ) 
		for( int j = 0 ; j < 2 ; j++ ) 
			cin >> a[i][j]; 


	int x=-1,y=-1; 
	for( int i = 1 ; 1ll * i * (i-1) <= 2ll*a[0][0] ; i++ ) { 
		if( 1ll * i * (i-1) == 2ll*a[0][0] ) { 
			x = i; 
			break;
		}
	}
	for( int i = 1 ; 1ll * i * (i-1) <= 2ll*a[1][1] ; i++ ) 
		if( 1ll * i * (i-1) == 2ll * a[1][1] ) { 
			y = i; 
			break;
		}

	if( x == -1 || y == -1 ) die(); 
	if( a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && y != -1 ) { 
		string ans = ""; 
		for( int i = 0 ; i < y ; i++ ) 
			ans += '1';
		cout << ans << endl;
		return 0; 
	}
	if( a[1][1] == 0 && a[1][0] == 0 && a[0][1] == 0 && x != -1 ) { 
		string ans = ""; 
		for( int i = 0 ; i < x ; i++ ) 
			ans += '0';
		cout << ans << endl;
		return 0; 
	}
	if( x == 0 && y == 0 ) die(); 
	if( 1ll * a[0][1] + 1ll * a[1][0] != 1ll * x * y ) die(); 
	string ans = ""; 
	for( int i = x ; i >= 0 ; i-- ) {
		while( y && a[0][1] - i >= 0 ) { 
			a[0][1] -= i; 
			y--; 
			ans += '1'; 
		}
		if( i ) ans += '0'; 
	}
	reverse(ans.begin(),ans.end()); 
	if( a[0][1] == 0 ) cout << ans << endl;
	else die(); 
}
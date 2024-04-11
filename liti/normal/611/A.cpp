//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
#define SZ(x) ((int) (x).size())

int a[] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } ; 
int main() { 
	int x; 
	string s; cin >> x >> s >> s; 
	if( s == "month" ) { 
		int ans = 0; 
		for( int i = 0 ; i < 12 ; i++ ) 
			ans += ( a[i] >= x ) ; 
		cout << ans << endl;
	} else { 
		int k = 4; 
		x--; 
		int ans = 0;
		for( int i = 0 ; i < 12 ; i++ ) 
			for( int j = 0 ; j < a[i] ; j++ ) { 
				if( k == x ) ans++;
				k = ( k + 1 ) % 7;
			}
		cout << ans << endl;
	}
}
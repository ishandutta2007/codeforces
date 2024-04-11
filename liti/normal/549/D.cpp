//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 100 + 10; 
string a[maxN]; 
int val[maxN][maxN];
int main() { 
	int n,m; 
	cin >> n >> m; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];

	int ans = 0 ;
	for( int i = n - 1 ; i >= 0 ; i-- ) 
		for( int j = m - 1 ; j >= 0 ; j-- ) {
			char ch = a[i][j]; 
			int k;
			if( ch == 'B') 
				k = val[i][j] + 1; 
			else
				k = val[i][j] - 1; 
			if( k == 0 ) continue;
			ans += 1; 
			for( int x = 0 ; x <= i ; x++ ) 
				for( int y = 0 ; y <= j ; y++ ) 
					val[x][y] -= k;
		}
	cout << ans << endl;

}
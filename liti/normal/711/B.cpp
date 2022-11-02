//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 500 + 10; 

ll a[maxN][maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int x,y; 
	x = y = -1; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < n ; j++ ) { 
			cin >> a[i][j]; 
			if( !a[i][j] ) 
				x = i , y = j; 
		}

	if( n == 1 ) { 
		cout << 1 << endl;
		return 0; 
	}
	ll sum = -1; 
	for( int i = 0 ; i < n ; i++ ) 
		if( i != x ) { 
			ll tmp = 0; 
			for( int j = 0 ; j < n ; j++ ) 
				tmp += a[i][j]; 
			if( sum == -1 ) 
				sum = tmp; 
			else if( sum != tmp ) { 
				cout << -1 << endl;
				return 0; 
			}
		}
	ll tmp = 0; 
	for( int j = 0 ; j < n ; j++ ) 
		tmp += a[x][j]; 
	if( sum - tmp <= 0 ) { 
		cout << -1 << endl;
		return 0;
	}

	a[x][y] = sum - tmp;  


	for( int j = 0 ; j < n ; j++ ) { 
		ll tmp = 0; 
		for( int i = 0 ;i < n ; i++ ) 
			tmp += a[i][j]; 
		if( sum != tmp ) { 
			cout << -1 << endl;
			return 0; 
		}
	}
	tmp = 0; 
	ll tmp2 = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		tmp += a[i][i]; 
		tmp2 += a[i][n-i-1]; 
	}
	if( tmp != sum || tmp2 != sum ) { 
		cout << -1 << endl;
		return 0;
	}
	cout << a[x][y] << endl;

}
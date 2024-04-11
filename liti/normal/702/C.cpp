//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 100 * 1000 + 100; 
typedef long long ll; 

ll a[maxN], b[maxN]; 
bool ok[maxN]; 

int main() { 
	int n,m; cin >> n >> m; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i]; 
	}
	for( int j = 0 ; j < m ; j++ ) { 
		cin >> b[j]; 
	}

	ll s = -1 , e = 2000 * 1000 * 1000 + 1000; 
	while( e - s > 1 ) { 
		ll mid = (s+e)/2; 

		memset( ok , 0 , sizeof ok ) ; 
		int ptr = 0; 
		for( int i = 0 ; i < n ; i++ ) { 
			while( ptr < m && b[ptr] <= a[i] ) 
				ptr++; 
			if( ptr && b[ptr-1] + mid >= a[i] ) 
				ok[i] = true; 
		}
		ptr = m; 
		bool flag = true;
		for( int i = n - 1 ; i >= 0 ; i-- ) { 
			while( ptr > 0 && b[ptr-1] >= a[i] ) 
				ptr--; 
			if( ptr != m && b[ptr] - mid <= a[i] ) 
				ok[i] = true; 
			if( !ok[i] ) flag = false; 
		}
		if( flag ) 
			e = mid; 
		else
			s = mid;
	}
	cout << e << endl;
}
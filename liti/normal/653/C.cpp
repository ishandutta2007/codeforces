//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll;

const int maxN = 150 * 1000 + 100; 
int a[maxN]; 
vector<int> bad; 
set<pair<int,int>> curr; 
set<int> pl; 
int main() { 
	int n; cin >> n; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	for( int i = 0 ; i < n - 1 ; i++ ) 
		if( i % 2 == 0 ) { 
			if( a[i] >= a[i+1] ) 
				bad.push_back(i); 
		} else { 
			if( a[i] <= a[i+1] ) 
				bad.push_back(i); 
		}
	for( auto x : bad ) {
		pl.insert(x); 
		pl.insert( x + 1 ); 
	}

	if( bad.size() > 4 ) { 
		cout << 0 << endl;
		return 0; 
	}

	for( int i = 0 ; i < n ; i++ ) { 
		for( auto x : pl ) {
			if( x == i ) continue;
			swap( a[i] , a[x] ); 
			bool good = true; 
			if( i % 2 == 0 ) {
				good &= (i==0||a[i-1] > a[i]);
				good &= (i==n-1||a[i+1] > a[i]); 
			} else { 
				good &= (i==0||a[i-1] < a[i]);
				good &= (i==n-1||a[i+1] < a[i]); 
			}
			swap( i , x ) ; 
			if( i % 2 == 0 ) {
				good &= (i==0||a[i-1] > a[i]);
				good &= (i==n-1||a[i+1] > a[i]); 
			} else { 
				good &= (i==0||a[i-1] < a[i]);
				good &= (i==n-1||a[i+1] < a[i]); 
			}
			swap( i , x ); 
			for( auto y : bad ) { 
				if( y % 2 == 0 ) 
					good &= a[y] < a[y+1]; 
				else
					good &= a[y] > a[y+1]; 
			}
			swap( a[i] , a[x] ); 
			if( good ) 
				curr.insert( make_pair( min(i,x) , max(i,x) ) ); 
		}
	}
	cout << curr.size() << endl;
}
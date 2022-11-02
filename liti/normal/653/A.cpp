//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll;

int a[100];
int main() { 
	int n; cin >> n; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	sort( a , a + n ); 
	n = unique( a , a + n ) - a; 
	for( int i =0 ; i + 2 < n ; i++ ) 
		if( a[i+2] - a[i] <= 2 ) { 
			cout << "YES" << endl;
			return 0; 
		}

	cout << "NO" << endl;
}
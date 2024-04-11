//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() {
	int n,m; 
	cin >> n >> m; 
	if( min( n,m ) == 1 ) 
		cout << n * m << endl;
	else if( max( n , m ) <= 2 ) 
		cout << n * m << endl;
	else if( min(n,m) == 2 ) {
		if( m > 2 ) swap( n,m) ; 
		int x = n / 2; 
		int k = 4 * (x/2); 
		if( n % 2 == 1 && x % 2 == 1 ) 
			k += 2;
	//	cout << k << endl;
		cout << n * m - k << endl;
	}else
		cout << (n * m+1) / 2 << endl;
}
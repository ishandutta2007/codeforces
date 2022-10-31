#include <iostream>
#include <cmath>

using namespace std;
long long n,m,k;

long long check( int mid ) { 
	long long x = k - mid; 
//	cout << mid << ' ' << x << endl;
	long long ret = n/(mid+1); 
	ret *= m/(x+1);

	return ret;
}

int main() { 
	cin >> n >> m >> k;

	if( n + m - 2 < k ) { 
		cout << -1 << endl;
		return 0;

	}


	long long x = min( k , n - 1 ) ; 

	long long ans = n / ( x + 1 ) * ( m / ( k - x + 1 ) ) ; 
	
	swap( n , m ) ; 
	
	x = min( k , n - 1 ) ; 

	ans = max( ans, n / ( x + 1 ) * ( m / ( k - x + 1 ) ) ); 
	

	cout << ans << endl;

}
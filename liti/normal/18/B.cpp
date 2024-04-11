/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

int main() { 
	long long n,d,m,l;
	cin >> n >> d >> m >> l;

	long long s = 0 ; 
	
	for(int i = 0;i < 2*m ; i++ ) { 
		if( s/m >= n ) {
			cout << s << endl;
			return 0;
		}

		if( s % m > l ) {
			cout << s << endl;
			return 0;
		}
		s += d;
	}

	cout << d* (  ( m * n + d - 1 ) / d )  << endl;
}
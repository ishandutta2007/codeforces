/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main() { 
	int n;
	cin >> n;

	if( n == 2 ) { 
		cout << 1 << endl << 1 << endl;
		return 0;
	}
	if( n == 3 ) { 
		cout << 2 << endl << 1 << ' '<< 3 << endl;
		return 0; 
	}
	if( n == 4 ) { 
		cout << "4\n3 1 4 2" << endl;
		return 0;
	}

	int k = n - 1; 

	cout << n << endl;

	if( n % 2 == 1 ) { 
		for( int i = 0 ; i < n ; i++ ) { 
			cout << ((2*i)) % n  + 1 << ' ' ;
		}
	} else { 
		cout << n << ' ';
		n--;
		for( int i = 0 ; i < n ; i++ ) { 
			cout << ((2*i)) % n  + 1 << ' ' ;
		}
	}
	cout << endl;
}
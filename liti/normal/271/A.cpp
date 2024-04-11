//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

bool good( int n ) { 
	int ni = n;

	for( int i = 0 ; i < 4 ; i++ ) { 
		int digi = ni % 10; 
		ni /= 10;

		int nj = ni;
		for( int j = i + 1 ; j < 4 ; j++ ) { 
			int digj = nj % 10;
			nj /= 10;

			if( digi == digj ) 
				return false;
		}
	}

	return true;
}

int main() { 
	int n;
	cin >> n;

	n++;

	while( !good(n) ) 
		n++;

	cout << n << endl;
}
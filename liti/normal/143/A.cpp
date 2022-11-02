//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
	int r1,r2,c1,c2,d1,d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2; 
	for( int i = 1 ; i < 10 ; i++ ) 
		for( int j = 1 ; j < 10 ; j++ ) 
			for( int k = 1 ; k < 10 ; k++ ) 
				for( int p = 1 ; p < 10 ; p++ ) 
					if( i != j && k != i && 
							k != j && p != k && p != j && p != i &&
							i + j == c1 && k + p == c2 && 
							i + k == r1 && j + p == r2 && 
							i + p == d1 && j + k == d2 ) { 
						cout << i << ' ' << k << endl << j << ' ' << p << endl;
						return 0;
					}
	cout << -1 << endl;
}
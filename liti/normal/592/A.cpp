//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

string a[8];
int main() { 
	int b1 = 100000 , b2  = b1; 
	for( int i = 0;i < 8 ; i++ ) 
		cin >> a[i];
	for( int i = 0 ; i < 8 ; i++ ) 
		for( int j =0 ; j < 8 ; j++ ) 
			if( a[i][j] == 'W' ) { 
				bool flag = true;
				for( int k = i - 1 ; k >= 0 ; k-- ) 
					if( a[k][j] != '.' ) 
						flag = false;
				if( flag ) 
					b1 = min( b1 , i ); 
			} else if( a[i][j] == 'B' ) { 
				bool flag = true;
				for( int k = i + 1 ; k < 8 ; k++ ) 
					if( a[k][j] != '.' ) flag = false;
				if( flag ) 
					b2 = min( b2 , 7 - i ); 
			}
	cout << (b1 <= b2 ? "A" : "B" ) << endl;

}
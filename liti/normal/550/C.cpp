//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

bool a[10];
int main() { 
	string s; 
	cin >> s; 

	a[0] = a[8] = true; 
	int n = s.size();
	for(int i = 0 ; i < n ; i++ ) 
		if( a[s[i] - '0'] ) { 
			cout << "YES" << endl;
			cout << s[i] << endl;
			return 0 ; 
		}
	for( int i = 0 ; i < n ; i++ )
		for( int j = i + 1 ; j < n ; j++) { 
			int a = ( s[i] - '0' ) * 10 + s[j] - '0';
			if( a % 8 == 0 ) {
				cout << "YES" << endl;
				cout << a << endl;
				return 0 ; 
			}
		}
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = i + 1 ; j < n ; j++ ) 
			for( int k = j + 1 ; k < n ; k++ ) { 
				int a = ( s[i] - '0' ) * 100 + (s[j] - '0')*10 + s[k] - '0';
				if( a % 8 == 0 ) { 
					cout << "YES" << endl;
					cout << a << endl;
					return 0 ; 
				}
			}
	cout<< "NO" << endl;
}
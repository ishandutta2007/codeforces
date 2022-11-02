//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 100000 + 100; 
int a[maxN], b[maxN];
int main() { 
	string s; 
	cin >> s;

	for( int i = __sz(s) - 1 ; i >= 0 ; i-- ) {
		if( s.substr( i , 2 ) == "AB" ) {
			a[i]++;
			if( b[i+2] ) {
				cout<< "YES" << endl;
				return 0;
			}
		}
		if( s.substr( i , 2 ) == "BA" ) { 
			b[i]++; 
			if( a[i+2] ) { 
				cout << "YES" << endl;
				return 0;
			}
		}
		a[i] += a[i+1] ; 
		b[i] += b[i+1];
	}
	cout << "NO" << endl;
}
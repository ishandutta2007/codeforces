//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
	string s; 
	cin >> s; 
	bool m = false;
	if( s[0] == '-' ) m = true; 
	string res = "$";
	for( int i = 0 ; i <=__sz(s) ; i++ ) 
		if( i == __sz(s) || s[i] == '.' ) { 
			for( int j = m ; j < i ; j++ ) {
				res += s[j];
				if( j != i-1 && (j) % 3 == (i+2) % 3 ) res += ","; 
			}
			res += '.';
			if( i == __sz(s) ) 
				s += ".";
			s+= "00";
			for( int j = i + 1 ; j < i + 3 ; j++ ) 
				res += s[j];
			break;
		}
	if( m ) cout << "(";
	cout << res;
	if( m ) cout << ")" ; 
	cout << endl;
}
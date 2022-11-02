//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
#define __sz(x) ((int)(x).size())

int main() { 
	string a,b;
	cin >> a >> b; 
	int ans = 0; 
	for( int i = 0 ; i + __sz(b) <= __sz(a) ; i++ ) 
		if( a.substr( i , __sz(b) ) == b ) {
			ans++; 
			a[i + __sz(b)-1] = '#'; 
		}
	cout << ans << endl;
}
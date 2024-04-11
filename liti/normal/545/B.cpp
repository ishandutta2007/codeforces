//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
    string a,b; 
    cin >> a >> b; 
    int n = __sz(a); 
    int diff = 0;
    for( int i = 0 ; i < n ; i++ ) 
	if( a[i] != b[i] ) 
	    diff++; 
    if( diff & 1 ) { 
	cout << "impossible" << endl;
	return 0; 
    }
    int x = diff / 2; 
    string res = "";
    for( int i = 0 ; i < n ; i++ ) 
	if( a[i] != b[i] ) { 
	    if( x ) {
		res += a[i]; 
		x--;
	    } else
		res += b[i];
	} else 
	    res += a[i];
    cout << res << endl;
}
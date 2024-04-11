//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
	int w,m; 
	cin >> w >> m; 
	int x = w; 
	w = m;
	for( int i = 0 ; i <= 100 ; i++ ) { 
		if( w % x == 0 || w % x == 1 ) 
			w = w; 
		else if( w % x == x - 1 ) 
			w += 1; 
		else
			break;
		if( w == 0 ) { 
			cout << "YES" << endl;
			return 0;
		}
		w /= x; 
	}
	cout << "NO" << endl;
}
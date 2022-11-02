//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
	int n; 
	cin >> n;
	int ans = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2; 
		ans += ( x2 - x1 + 1 ) * ( y2 - y1 + 1 ) ; 
	}
	cout << ans << endl;
}
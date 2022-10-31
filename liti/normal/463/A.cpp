/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

int main() { 
	int n, s;
	cin >> n >> s;

	int ans = -1;
	for( int i = 0 ; i < n ; i++) { 
		int a,b;
		cin >> a >> b ; 
		if( a + ( b == 0 ? 0 : 1 ) > s ) 
			continue;
		ans = max( ans, 100 - ( b == 0 ? 100 : b ) ) ; 
	}
	cout << ans << endl;
}
//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 
int sq(int v) { 
	return v*v;
}

int main() {
	int r, d;
	cin >> r >> d;
	int n; 
	cin >> n;
	int ans = 0;
	for( int i = 0 ; i < n; i++ ) { 
		int c, x, y; 
		cin >> x >> y >> c; 
		int dis = x * x + y * y; 

		if( c <= r && sq( r - d + c ) <= dis && dis <= sq(r - c) ) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0; 
}
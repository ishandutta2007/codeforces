//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 

int main() {
	int n; cin >> n; 

	int l, r = l = 0; 
	for( int i = 0 ; i < n ; i++ ) {
		int x, y; 
		cin >> x >> y;
		if( x < 0 ) l++;
		else r++; 
	}
	cout << (min(l,r) <= 1 ? "Yes" : "No" ) << endl;
	return 0;
}
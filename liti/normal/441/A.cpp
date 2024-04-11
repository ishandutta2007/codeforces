/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int main() { 
	int n, v;
	cin >> n >> v;

	for( int i = 1 ; i <= n ; i++ ) { 
		int k;
		cin >> k;
		int val = 1e7 ;
		for( int j = 0 ; j < k ; j++) { 
			int num;
			cin >> num;
			val = min( val , num ) ; 
		}
		if( val < v ) 
			ans.push_back( i ) ;
	}
	cout << ans.size() << endl;
	copy( ans.begin() , ans.end() , ostream_iterator<int>(cout, " " ) );
}
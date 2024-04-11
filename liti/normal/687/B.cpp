//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int mark[10]; 

int main() {
    ios::sync_with_stdio(false);
	int n,k; cin >> n >> k; 
	int kk = k;
	vector<int> x; 
	for( int i = 2 ; i <= k ; i++ ) 
		if( k % i == 0 ) { 
			int z = 1; 
			for( ; k % i == 0 ; k /= i , z *= i ); 
			x.push_back(z); 
		}

	for( int i = 0 ; i < n ; i++ ) {
		int y; cin >> y; 
		for( int j = 0 ; j < int(x.size()) ; j++ ) 
			if( y % x[j] == 0 ) 
				mark[j] = true; 
	}
	for( int i = 0 ; i < int(x.size()) ; i++ ) 
		if( !mark[i] ) { 
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
}
/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 3000*10 + 100; 

int a[maxN];

int main() { 
	int n , t;

	cin >> n >> t ; t--;
	for( int i = 0 ; i < n - 1 ; i++ ) 
		cin >> a[i];

	if( t == n - 1 ) {
		cout << "YES" << endl;
		return 0;
	}
	int i = 0 ;
	while( i != n-1 ) { 
		if( i == t ) { 
			cout << "YES" << endl;
			return 0;
		}
		i = i + a[i];
	}
	cout << "NO" << endl;
}
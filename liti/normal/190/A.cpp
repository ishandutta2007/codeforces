/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main() { 
	int n,m;
	cin >> n >> m; 
	if( n == 0 ) { 
		if( m == 0 ) 
			cout << "0 0" << endl;
		else
			cout << "Impossible" << endl;
		return 0; 
	}
	int k = min( n , m ) ; 
	cout << m - k + n << ' ' << n + max(0,m - 1) << endl;
}
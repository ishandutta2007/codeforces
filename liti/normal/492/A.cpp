/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main() { 
	int n;
	cin >> n;

	int cnt = 0; 
	int k = 0;
	for( int i = 1 ; i <= n + 1 ; i++ ) { 
		k += i;
		cnt += k ; 
		if( cnt > n  ) {
			cout << i-1 << endl;
			return 0;
		}
	}
}
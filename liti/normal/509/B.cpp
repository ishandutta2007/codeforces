/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100 + 10;
int a[maxN];

int main() { 
	int n,k;
	cin >> n >> k;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	int x = *min_element(a, a + n ); 
	int y = *max_element(a, a + n );
	if( y - x  > k ) { 
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for( int i =0 ; i < n ; i++ ) {
		for( int j = 0 ; j < a[i] ; j++ ) {
			if( j <= x ) cout << 1 << ' ';
			else cout << j - x + 1 << ' ' ;
		}
		cout << endl;
	}
}
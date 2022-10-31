/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 3*100*1000 + 10;
int a[maxN];

int main() {
	int n;
	cin >> n;

	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	sort( a , a + n ) ;

	long long ans = 0;
	for( int i = 0 ; i < n ; i++ ) 
		ans += 1LL*(i+2)*a[i];
	cout << ans - a[n-1]<< endl;
}
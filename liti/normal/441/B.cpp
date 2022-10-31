/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 3000 + 100; 
int a[maxN];

int main() { 
	int n,v;
	cin >> n >> v;
	for( int i= 0 ; i < n; i++ ) { 
		int num, t;
		cin >> t >> num;
		a[t]+=num;
	}
	int ans = 0 ;
	for( int i = 0 ; i < maxN ; i++ ) { 
		ans += min( a[i] + ( i != 0 ? a[i-1] : 0 ) , v ) ;
		a[i] = max( 0 , a[i] - v + ( i == 0 ? 0 :  min( a[i-1] , v ) ) ) ;
	}
	cout << ans << endl;
}
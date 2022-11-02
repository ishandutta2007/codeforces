//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 100 + 10;
int a[100]; 
int b[maxN],c[maxN]; 
int main() {
	int n,k; 
	cin >> n >> k;
	for( int i = 0 ;i < n ; i++ ) { 
		cin >> a[i]; 
		if( a[i] == 1 ) b[i%k]++; 
		else c[i%k]++; 
	}
	int ans = 0 ; 
	for( int i =0 ; i < k ; i++ ) {
		ans += min( c[i] , b[i] ); 
	}
	cout << ans << endl;
}
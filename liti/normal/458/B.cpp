/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;


const int maxN = 1000*100 + 10;
int a[maxN], b[maxN];
unsigned long long sum[maxN];

unsigned long long calc( int* a , int* b , int n, int m) { 
	sum[0] = 0;
	for(int i = 1 ; i <= n ; i++ ) 
		sum[i] = sum[i-1] + a[i-1];

	unsigned long long c = 0 ; 
	for(int i = 0 ; i < m ; i++ ) 
		c += b[i];

	unsigned long long ans = 1e9*1LL*1e6;
	for(int i = 1 ; i <= n ; i++ ) 
		if( c * i >= 0 )
			ans = min( ans, ( c * i ) + sum[n] - sum[i] )  ;
	return ans;
}

int main() { 
	int m,n;
	cin >> m >> n;

	for(int i = 0 ; i < m; i++ ) 
		cin >> a[i];
	for(int i = 0 ; i < n ; i++ ) 
		cin >> b[i];

	sort( a , a + m , greater<int>() ) ; 
	sort( b, b + n , greater<int>() ) ;
	unsigned long long ans = min( calc( a, b, m, n ) , calc( b, a,n,m ) ) ; 
	cout << ans << endl;
}
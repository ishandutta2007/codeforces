#include <iostream>

using namespace std;

const int maxN = 1000*100 + 10;

int a[maxN], d[maxN], dp[maxN];

int main(){
	int n;
	cin >> n;

	for(int i =0 ; i < n ; i++ )
		cin >> a[i];

	int ans = 0 ;
	int counter = 1; 
	for(int i = 0 ; i < n - 1  ; i++ ) { 
		dp[i] = counter;
		ans = max( ans, counter ) ; 
		counter++;
		if( a[i] >= a[i+1] ) 
			counter = 1;
	}
	dp[n-1] = counter;

	counter = 1; 
	for(int i= n - 1 ; i > 0 ; i-- ) { 
		d[i] = counter ; 
		ans = max( ans, counter ) ; 
		counter++;
		if( a[i] <= a[i-1]  ) 
			counter = 1; 
	}
	d[0] = counter;


	a[n] = 1e9 + 100;
	for(int i = 0 ; i < n - 1 ; i++ ) 
		if( a[i+2] - a[i] > 1 ) 
		{
			ans = max( ans, dp[i] + 1 + d[i+2] ) ; 
		} else ans = max( ans, max( dp[i] + 1, d[i+1] + 1 )  ) ;
	ans= max( ans, d[1] + 1 ) ; 
	cout << ans << endl;
}
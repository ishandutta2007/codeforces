//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 1000 * 100 + 100; 

pair<int,int> a[maxN];
int dp[maxN]; 

int main() { 
	int n; 
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i].first >> a[i].second; 
	sort( a , a + n ); 

	dp[1] = 1; 
	int mx = 1; 
	for( int i = 1 ; i < n ; i++ ) { 
		int k = lower_bound( a , a + n , make_pair( a[i].first - a[i].second , -1 ) ) - a;
		dp[i+1] = dp[k] + 1; 
		mx = max( mx , dp[i+1] ) ;  
	}
	cout << n - mx << endl;
}
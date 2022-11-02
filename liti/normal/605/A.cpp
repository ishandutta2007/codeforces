//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000 * 100 + 100; 
pair<int,int> a[maxN];
int main() { 
	int n; 
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i].first; 
		a[i].second = i; 
	}
	sort( a , a + n ); 

	int cnt = 0; 
	int ans = n - 1; 
	for( int i = 0 ; i < n ; i++ ) { 
		if( i != 0 && a[i].second < a[i-1].second ) 
			cnt = 0; 
		cnt++; 
		ans = min( ans , n - cnt ); 
	}
	cout << ans << endl;
}
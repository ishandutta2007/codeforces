//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 100 + 10; 
int a[maxN]; 
int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n; cin >> n ; 
	int ans = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i]; 
		if( a[i] == 1 || a[i] == n ) ans = max( ans , max( i , n - i - 1 ) ) ; 
	}
	cout << ans << endl;
}
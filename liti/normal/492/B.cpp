/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef long double ld;

const int maxN = 1000 + 10; 

int a[maxN];

int main() { 
	int n,l;
	cin >> n >> l;
	for( int i = 0 ;i < n ; i++ ) 
		cin >> a[i];
	sort( a , a + n ) ; 

	ld ans = max( a[0] , l - a[n-1] );
	for( int i = 0 ; i < n -1 ; i++ ) 
		ans = max( ans , ld(a[i+1] - a[i]) / 2 ) ; 

	cout << fixed << setprecision(9)  <<ans << endl;
}
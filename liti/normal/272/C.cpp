/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100*1000 + 10;
ll a[maxN];
int main() { 
	int n;
	cin >> n;
	for( int i = 0; i < n ; i++ ) 
		cin >> a[i];
	ll mx = 0;
	int m; cin >> m;
	for( int i = 0 ; i < m ; i++ ) {
		ll w,h; cin >> w >> h;
		ll best = max( a[w-1] , mx );
		cout << best << endl;
		mx = max( mx , best + h ) ; 
	}
}
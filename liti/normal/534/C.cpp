/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
const int maxN = 2000*100 + 100; 

ll a[maxN];

int main() {
	int n;
	ll A; 
	cin >> n >> A;

	ll sum = 0;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i]; 
		sum += a[i]; 
	}

	for( int i =0 ; i < n ; i++ ) { 
		ll mx = sum - a[i]; 
		ll mn = n - 1; 

		// mn  <= A - x <= mx
		// mn = A - x => x = A - mn 
		// mx = A - x => x = A - mx
		ll saght = A - mn; 
		ll kaf = A - mx; 

		cout << a[i] - (min( saght , a[i] ) - max( min(kaf, a[i]) , 1ll ) + 1) <<' ';
	}
}
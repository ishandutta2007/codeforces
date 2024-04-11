//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
const int maxN = 3 * 100000 + 100; 
int a[maxN];
ll psum[maxN],p2sum[maxN]; 
map<int,int> mp;

int main() { 
	int n; cin >> n;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i]; 
		mp[a[i]] = i;
	}
	sort( a , a + n ); 
	for( int i = 0 ; i< n ; i++ ) { 
		psum[i+1] = a[i] + psum[i]; 
		p2sum[i+1] = i *1ll* a[i] + p2sum[i]; 
	}
	int k; cin >> k; 

	pair<ll,int> best = { ll( -1ull/2 )  , -1 }; 
	for( int i = 0 ; i + k <= n; i++ ) { 
		int s = i , e = i + k; 
		// -> ( i - s - (e - i - 1)  ) a[i]
		// -> 2i - s - e + 1 
		// 2i  - ( e + s - 1 ) a[i]
		//  ( s a[s] + s+1 a[s+1] + s+2 a[s+2] + .... 
		// psum[e] - psum[s+1] + psum[e] - psum[s+2] + .... + psum[e] - psum[e-1]
		ll dist = 2 * ( p2sum[e] - p2sum[s] )
			- (psum[e] - psum[s]) * ( e + s - 1 ) ;
		best = min( best , { dist , i } ) ; 
	//	cerr << i << ' ' << dist << endl;
	}

	for( int i = best.second ; i < best.second + k ; i++ ) 
		cout << mp[a[i]] + 1 << ' ' ; 
	cout << endl;
}
/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 10; 

pair<int,int> a[maxN];

int main() { 
	int n,r,av;
	cin >> n >> r >> av;

	ll x = av*1LL*n;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i].second >> a[i].first; 
		x -= a[i].second;
	}

	sort( a , a + n ) ; 

	ll ret = 0;
	for( int i = 0 ;i < n ; i++ ) {
		if( x <= 0 ) break;
		int k = min( ll(r) - a[i].second , x ) ; 
		x -= k;
		ret += k*1LL*a[i].first;
	}
	cout << ret << endl;
}
//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxN = 1000*100 + 100; 

pii a[maxN];

int main() { 
	int n,d; 
	cin >> n >> d; 
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i].first >> a[i].second;
	sort( a , a + n ) ; 
	int st = 0; 
	ll sum = 0 , ans = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		sum += a[i].second;
		while( a[st].first + d - 1 < a[i].first ) sum -= a[st].second, st++; 
		ans = max(ans,sum);
	}
	cout << ans << endl;
}
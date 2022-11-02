//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxL = 32; 
typedef long long ll;

map<ll,int> cnt; 
const int maxN = 100 * 1000 + 100; 
ll a[maxN]; 

int main() { 
	ios::sync_with_stdio(false); 
	int n; 
	cin >> n; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	ll ans = 0; 
	for( int k = 0 ; k < maxL ; k++ ) { 
		cnt.clear(); 
		ll num = 1ll<<k; 
		for( int i = 0 ; i < n ; i++ ) { 
			ans += cnt[a[i]];
			cnt[num-a[i]]++; 
		}
	}
	cout << ans << endl;
}
//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 2000 * 1000 + 10; 
int cnt[maxN]; 
int len[maxN]; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 

	int n, m; 
	cin >> n >> m;

	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		cnt[x]++; 
	}
	for( int i = maxN - 2 ; i >= 0 ; i-- ) 
		len[i] = cnt[i] ? 1 + len[i+1] : 0;

	int x = 0; 
	for( int i = 0 ; i < m ; i++ ) { 
		int _; cin >> _; 
		x ^= _; 

		int v = x; 
		int ans = 0; 
		for( int k = 20 ; k >= 0 ; k-- ) 
			if( len[v & (~((1<<k)-1))] >= (1<<k) ) { 
				ans += (1<<k);
				v ^= (1<<k); 
			}
		cout << ans << '\n';
	}

	return 0; 
}
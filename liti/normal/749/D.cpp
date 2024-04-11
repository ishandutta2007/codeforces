//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 2000 * 100 + 100; 

int a[maxN], b[maxN]; 
int ql[maxN], qr[maxN]; 
vector<int> q[maxN]; 
vector<int> todo[maxN]; 
int cnt[maxN]; 
int last[maxN];
int ans[maxN], cost[maxN];

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n; cin >> n; 
	for( int i =n - 1 ; i >= 0 ; i-- ) 
		cin >> a[i] >> b[i]; 

	int m; cin >> m; 
	for( int i = 0 ; i < m ; i++ ) { 
		int k; cin >> k; 
		q[i].resize(k);
		for( int j = 0 ; j < k ; j++ ) 
		   cin >> q[i][j]; 

		ql[i] = -1 , qr[i] = n; 
	}	

	for( int t = 0 ; t < 22 ; t++ ) { 
		bool hasTo = false; 
		for( int i = 0 ; i < m ; i++ ) 
			if( qr[i] - ql[i] > 1 ) { 
				todo[(qr[i]+ql[i])/2].push_back(i); 
				hasTo = true; 
			}
		if( !hasTo ) break;

		memset( cnt , 0 , sizeof cnt ); 
		int tot = 0; 
		long long sum = 0; 
		for( int i = 0 ; i < n ; i++ ) { 
			if( cnt[a[i]] == 0 ) {
			   	tot++; 
				sum += a[i]; 
			}
			last[a[i]] = i; 
			cnt[a[i]]++; 
			for( auto x : todo[i] ) { 
				int count = 0; 
				long long val = 0; 
				for( auto y : q[x] ) 
					if( cnt[y] ) { 
						count++; 
						val += y;
					}
						
				if( count + 1 >= tot ) { 
					ql[x] = i; 
					if( sum - val > 0 ) { 
						int p = sum - val; 
						ans[x] = p , cost[x] = b[last[p]]; 
					} else 
						ans[x] = 0 , cost[x] = 0; 
				} else
					qr[x] = i; 
			}
			todo[i].clear();
		}
	}
	for( int i = 0 ; i < m ; i++ )
		cout << ans[i] << " " << cost[i] << endl;
}
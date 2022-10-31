/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
#define sz(x) (((int) x.size()))

const int maxN = 100*100*10+100; 
const int INF = 1e8;

int a[maxN];
int dp[maxN];

deque<pair<int,int>> mn, mx;

int main() { 
	fill( dp , dp + maxN , INF );
	dp[0] = 1;

	int n,s,l;
	cin >> n >> s >> l;

	int last = 0;
	for( int i = 1 ; i <= n ; i++ ) { 
		cin >> a[i];

		while( mn.size() && mn.back().first <= a[i] ) 
			mn.pop_back();
		mn.push_back( {a[i],i} );
		while( mx.size() && mx.back().first >= a[i] ) 
			mx.pop_back();
		mx.push_back( {a[i],i} );

		while( i - last >= l ) { 
			if( dp[last] != INF && mn.front().first - mx.front().first <= s ) {
	//			cout << i << ' ' << last << ' ' << mx.front().first << ' ' << mn.front().first << endl;
				dp[i] = dp[last] + 1;
				break;
			}

			last++;
			if( mn.size() && mn.front().second <= last ) 
				mn.pop_front();
			if( mx.size() && mx.front().second <= last ) 
				mx.pop_front();
		}
	}

	if( dp[n] == INF ) 
		cout << -1 << endl;
	else
		cout << dp[n] - 1 << endl;
}
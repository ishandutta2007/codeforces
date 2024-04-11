/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100 + 10;

int dp[4][maxN];
vector<int> curr[4][maxN];
// 0: 2 taraf khali
// 1: chap khali rast bala
// 2: chap bala rast bala
// 3: chap bala rast payin 


int table[2][maxN];

int main() { 
	int m,x;
	cin >> m >> x;

	for( int i = 1 ; i <= m ; i++ ) 
		for( int t = 0 ; t < 4 ; t++ ) {
			for( int k = 1 ; k <= i ; k++ ) {
				//bala jaye k om
				if( ( k < i || t <= 2 ) ) {
					int f=0, s=0;
					if( t <= 1 ) f = 1;
					else f = 2;
					if( t == 0 ) s = 1;
					else if( t <= 2 ) s = 2;
					else s = 3;
					curr[t][i].push_back( dp[f][k-1] ^ dp[s][i-k] );
				}
				if( ( k > 1 || t <= 1 ) && ( k < i || t == 0 || t == 3 ) ) { 
					int f=0,s=0;
					if( t <= 1 ) f = 1;
					else f = 3;
					if( t == 0 ) s = 1;
					else if( t <= 2 ) s = 3;
					else s = 2;
					curr[t][i].push_back( dp[f][k-1] ^ dp[s][i-k] );
				}

			}
			int mx = 0;
			sort(curr[t][i].begin(),curr[t][i].end());
			for( int j = 0 ; j < sz(curr[t][i]) ;j++ ) 
				if( mx == curr[t][i][j] ) mx++;
			dp[t][i] = mx;
//			cout << t << ' ' << i << ' ' << dp[t][i] << endl;
		}

	for( int i = 0 ; i < x ; i++ ) { 
		int a,b; cin >> a >> b;
		table[b-1][a-1] = 1; 
	}
	int last = 0;
	int ans = 0;
	for( int i = 0 ; i < m ; i++ ) 
		if( table[0][i] == 1 || table[1][i] == 1 ) { 
			if( last == 0 )
				ans ^= dp[1][i];
			else if( table[0][last-1] == table[0][i] )
				ans ^= dp[2][i-last];
			else 
				ans ^= dp[3][i-last];
			last = i + 1;
		}
	if( last == 0 ) ans ^= dp[0][m];
	else ans ^= dp[1][m-last];
	cout << (ans?"WIN":"LOSE") << endl;
}
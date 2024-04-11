//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 1000 * 100 + 100; 
int psum[maxN]; 
int len[2][maxN];
int v[maxN]; 
pii dp[maxN];


int main() {
	int n;
	cin >> n;
	string s; cin >> s; 
	int m; cin >> m; 

	for(int i = 0; i < n; i++) {
		psum[i+1] = psum[i];
		if( s[i] == '?' ) { 
			psum[i+1]++; 
			len[0][i+1] = len[1][i] + 1;
			len[1][i+1] = len[0][i] + 1;
		} else if( s[i] == 'a' ) { 
			len[0][i+1] = len[1][i] + 1; 
		} else { 
			len[1][i+1] = len[0][i] + 1;
		}

		v[i+1] = -1;
		dp[i+1] = dp[i];
		if( i + 1 >= m && len[1^(m%2)][i+1] >= m ) {
			v[i+1] = psum[i+1] - psum[i+1-m];
			dp[i+1] = max(dp[i+1], {dp[i+1-m].first + 1, dp[i+1-m].second - v[i+1]} );
		}

	}

	cout << -dp[n].second << endl;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, m, last = -1;
vector<vi> v;
vector<vi> dp(20, vi(2, -1));

int obtRes ( int i, int f ) {
	if ( dp[i][f] > -1 )
		return dp[i][f];

	if ( i == last )
		return dp[i][f] = f ? m + 1 - v[i].front() : v[i].back();

	if ( v[i].empty() )
		return dp[i][f] = min ( 1 + obtRes(i-1, f), m + 2 + obtRes(i-1, !f) );

	if ( f )
		return dp[i][f] = min ( m + 2 + obtRes(i-1, !f), (m + 1 - v[i].front()) * 2 + 1 + obtRes(i-1, f) );
	
	return dp[i][f] = min ( m + 2 + obtRes(i-1, !f), v[i].back() * 2 + 1 + obtRes(i-1, f) ); 
}

int main() {
	char c;

	cin >> n >> m;
	v.assign(n, vi(0,0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 2; j++){
			cin >> c;
			if ( c == '1' ){
				if ( last == -1 )
					last = i;
				v[i].push_back(j);
			}
		}
	}

	if ( last == -1 )
		cout << 0;
	else
		cout << obtRes(n-1, false);

	return 0;
}
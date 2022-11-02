/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 10; 
vector<pair<int,int>> curr[maxN];
int dp[maxN];

int main() { 
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 0;
	for( int i = 2 ; i <= n ; i++ ) {
		sort(curr[i].begin(),curr[i].end());
		int mx = 0;
		for( int j = 0 ; j < sz(curr[i]) ; j++ ) 
			if( curr[i][j].first == mx ) 
				mx++;
		dp[i] = mx;
		int cnt = 1; 
		int sum = i;
		int tmp = dp[i];
		for( int j = i - 1 ; j >= 1 ; j-- ) {
			sum += j;
			tmp ^= dp[j];
			cnt++;
			if( sum >= maxN ) break;
			curr[sum].push_back({tmp,cnt});
		}
	}
	if( dp[n] == 0 ) 
		cout << -1 << endl;
	else
		cout << curr[n][0].second << endl;
}
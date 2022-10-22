#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[400005];
map<llint, llint> mp;
llint c[25][25], cnt[25];
llint dp[1<<20];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int id = 0;
	for(int i = 1; i <= n; i++){
		if(mp.count(a[i]) == 0) mp[a[i]] = id++;
		a[i] = mp[a[i]];
	}
	
	int m = id;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			if(a[i] == j) continue;
			c[a[i]][j] += cnt[j];
		}
		cnt[a[i]]++;
	}
	
	/*for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}*/
	
	int N = 1<<m;
	for(int i = 0; i < N; i++) dp[i] = 1e18;
	dp[0] = 0;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < m; j++){
			if(i&(1<<j)) continue;
			llint sum = 0;
			for(int k = 0; k < m; k++){
				if(i & (1<<k)) sum += c[j][k];
			}
			dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i] + sum);
		}
	}
	cout << dp[N-1] << endl;
	
	return 0;
}
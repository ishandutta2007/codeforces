#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, p, f;
llint a[100005], s[100005][7];
llint pop[1<<7];
llint dp[100005][1<<7];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p >> f;
	for(int i = 1; i <= n; i++) cin >> a[i], vec.push_back(P(a[i], i));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < p; j++){
			cin >> s[i][j];
		}
	}
	sort(vec.rbegin(), vec.rend());
	
	llint P = 1<<p;
	for(int i = 1; i < P; i++) pop[i] = pop[i&(i-1)] + 1;
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < P; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		llint id = vec[i].second;
		for(int j = 0; j < P; j++){
			llint cost = 0;
			if(i-pop[j] < f) cost = a[id];
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + cost);
			for(int k = 0; k < p; k++){
				if(j & (1<<k)) continue;
				dp[i+1][j|(1<<k)] = max(dp[i+1][j|(1<<k)], dp[i][j] + s[id][k]);
			}
		}
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j < P; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	llint ans = dp[n][P-1];
	cout << ans << endl;
	
	return 0;
}
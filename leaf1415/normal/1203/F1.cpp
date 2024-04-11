#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, r;
vector<P> vec, vec2;
llint dp[105][60005];

bool comp(P p, P q)
{
	return p.first-p.second > q.first-q.second;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> r;
	llint a, b;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		if(b >= 0) vec.push_back(make_pair(a, b));
		else vec2.push_back(make_pair(a, -b));
	}
	sort(vec.begin(), vec.end());
	
	llint ans = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].first > r) break;
		ans++;
		r += vec[i].second;
	}
	//cout << ans << endl;
	
	sort(vec2.begin(), vec2.end(), comp);
	llint m = vec2.size();
	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < 60005; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][r] = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 60005; j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(vec2[i].first <= j && j >= vec2[i].second) dp[i+1][j-vec2[i].second] = max(dp[i+1][j-vec2[i].second], dp[i][j]+1);
		}
	}
	llint tmp = 0;
	for(int i = 0; i < 60005; i++) tmp = max(tmp, dp[m][i]);
	ans += tmp;
	
	if(ans == n) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
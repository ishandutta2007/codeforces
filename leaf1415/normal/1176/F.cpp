#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint dp[200005][10];
vector<llint> vec[4];
vector<P> vec2;
llint dp2[200005][4][4][2];

void calc()
{
	int n = vec2.size();
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k <= 3; k++){
				for(int l = 0; l < 2; l++){
					dp2[i][j][k][l] = -1e18;
				}
			}
		}
	}
	dp2[0][0][0][0] = 0;
	for(int i = 0; i < n; i++){
		llint c = vec2[i].second, d = vec2[i].first;
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k <= 3; k++){
				for(int l = 0; l < 2; l++){
					dp2[i+1][j][k][l] = max(dp2[i+1][j][k][l], dp2[i][j][k][l]);
					if(j+1 <= 3 && k+c <= 3){
						dp2[i+1][j+1][k+c][l] = max(dp2[i+1][j+1][k+c][l], dp2[i][j][k][l] + d);
						if(l == 0) dp2[i+1][j+1][k+c][1] = max(dp2[i+1][j+1][k+c][l], dp2[i][j][k][l] + 2*d);
					}
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 10; j++){
			dp[i][j] = -1e18;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		llint m, c, d;
		cin >> m;
		
		for(int j = 1; j <= 3; j++) vec[j].clear();
		for(int j = 0; j < m; j++){
			cin >> c >> d;
			vec[c].push_back(d);
		}
		for(int j = 1; j <= 3; j++) sort(vec[j].rbegin(), vec[j].rend());
		vec2.clear();
		for(int j = 1; j <= 3; j++){
			for(int k = 0; k < min(3, (int)vec[j].size()); k++) vec2.push_back(make_pair(vec[j][k], j));
		}
		
		m = vec2.size();
		calc();
		
		for(int j = 0; j < 10; j++){
			for(int k = 0; k <= 3; k++){
				bool boost = (j+k >= 10);
				for(int l = 0; l <= 3; l++){
					dp[i+1][(j+k)%10] = max(dp[i+1][(j+k)%10], dp[i][j] + dp2[m][k][l][0]);
					if(boost) dp[i+1][(j+k)%10] = max(dp[i+1][(j+k)%10], dp[i][j] + dp2[m][k][l][1]);
				}
			}
		}
		
		//for(int j = 0; j < 10; j++) cout << dp[i+1][j] << " "; cout << endl;
	}
	
	llint ans = 0;
	for(int i = 0; i < 10; i++) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}
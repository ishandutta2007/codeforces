#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int c[5005];
vector<int> vec, vec2;
int dp[5005][5005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	for(int i = 1; i <= n; i++) vec.push_back(c[i]);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	n = vec.size();
	vec.insert(vec.begin(), 0);
	
	vec2 = vec;
	reverse(vec2.begin()+1, vec2.end());
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(vec[i] == vec2[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << (n-1) - dp[n][n]/2 << endl;
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string s, t;
	cin >> s >> t;
	vector<int> psum(21000, 0);
	psum[0] = 10100;
	s = s + "48";
	t = t + "48";
	int n = (int)s.size();
	for(int i = 0; i < n; i++){
		psum[i+1] = psum[i] + (s[i] == '.' ? -1 : 1);
	}
	vector<int> dp(n+1, 1e8);
	dp[0] = 0;
	vector<int> dp_mid(n+1, 1e8);
	vector<int> new_dp(n+1, 1e8);
	vector<int> z1(21000);
	vector<int> z2(21000);
	for(char c : t){
		z1.assign(21000, 1e8);
		z2.assign(21000, 1e8);
		for(int i = 0; i <= n; i++){
			dp[i] += psum[i];
		}
		for(int i = 0; i <= n; i++){
			z1[psum[i]] = min(z1[psum[i]], dp[i]);
			z1[psum[i]] = min(z1[psum[i]], z1[psum[i] + 1]);
			if(i > 0 && psum[i-1] > psum[i]) z1[psum[i-1]] = 1e8;
			dp_mid[i] = z1[psum[i]];
		}
		for(int i = 0; i <= n; i++){
			dp_mid[i] -= 2 * psum[i];
		}
		for(int i = 0; i <= n; i++){
			z2[psum[i]] = min(z2[psum[i]], dp_mid[i]);
			z2[psum[i]] = min(z2[psum[i]], z2[psum[i] - 1]);
			z2[psum[i] + 1] = 1e8;
			new_dp[i] = z2[psum[i]];
		}
		for(int i = 0; i <= n; i++){
			new_dp[i] += psum[i];
		}
		dp.assign(n+1, 1e8);
		for(int i = 1; i <= n; i++){
			if(s[i-1] == c) dp[i] = new_dp[i-1];
		}
	}
	assert(dp.back() < (int)1e8);
	cout << dp.back() << '\n';
}
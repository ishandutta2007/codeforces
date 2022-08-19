#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(2*n);
	for(int i = 0; i < 2*n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	int s1 = a.back(); a.pop_back();
	int s2 = a.back(); a.pop_back();

	n -= 1;

	const int M = 27 * 50000 + 100;
	const int N = M * 27;
	using B = bitset<N>;
	vector<B> dp(2*n+1);
	dp[0].set(0);
	int sum = 0;
	for(int i = 1; i <= 2*n; i++){
		dp[i] = dp[i-1] | (dp[i-1] << (M + a[i-1]));
		sum += a[i-1];
	}
	int best = 0;
	for(int i = M * n; i < M * (n+1); i++){
		if(dp[2*n][i]){
			int val = i - M * n;
			if(val <= sum - val && val >= best){
				best = val;
			}
		}
	}
	best += M * n;
	vector<int> g1, g2;
	for(int i = 2*n-1; i >= 0; i--){
		assert(dp[i+1][best]);
		if(dp[i][best]){
			g1.push_back(a[i]);
		} else {
			assert(best >= (M + a[i]));
			best -= (M + a[i]);
			g2.push_back(a[i]);
		}
	}
	{
		vector<int> a, b, c, d;
		a.push_back(s1);
		for(int i = 0; i < n; i++){
			if(g1[i] >= g2[i]){
				b.push_back(g1[i]);
				d.push_back(g2[i]);			
			} else {
				a.push_back(g1[i]);
				c.push_back(g2[i]);
			}
		}
		d.push_back(s2);
		for(int x : a) cout << x << ' ';
		for(int x : b) cout << x << ' ';
		cout << '\n';
		for(int x : c) cout << x << ' ';
		for(int x : d) cout << x << ' ';
		cout << '\n';
	}
}
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	int n,k;
	cin >> n >> k;
	int mn = 1001;
	vector<int> a;
	for (int i = 0;i < n;++i) {
		int x;	cin >> x;
		mn = min(mn,x);
		a.push_back(x);
	}
	for (int i = 0;i < a.size();++i) a[i] -= mn;
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	int mx = k * a.back();
	int dp[mx + 5];
	for (int i = 0;i < mx + 5;++i) dp[i] = 1001;
	dp[0] = 0;
	for (int i = 0;i < a.size();++i) {
		int x = a[i];
		for (int j = 0;j <= mx - x;++j) dp[j + x] = min(dp[j + x],dp[j] + 1);
	}
	for (int i = 0;i <= mx;++i) if(dp[i] <= k) cout << mn * k + i<< ' ';   
}
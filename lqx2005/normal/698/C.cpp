#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define i64 long long
#define db double
using namespace std;
const int N = 20;
const db eps = 1e-12;
int n, k, c[1 << N], L2[1 << N];
db p[N], s[1 << N], dp[1 << N], ans[N];
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) L2[1 << i] = i;
	int cnt = 0;
	for(int i = 0; i < n; i++) cin >> p[i], cnt += (p[i] != 0);
	if(cnt < k) {
		for(int i = 0; i < n; i++) cout << (p[i] > 0 ? 1 : 0) <<" ";
		cout << endl;
		exit(0);
	}
	s[0] = 0;
	for(int i = 1; i < (1 << n); i++) {
		int t = i & (-i);
		c[i] = c[i >> 1] + (i & 1);
		s[i] = s[i ^ t] + p[L2[t]];
	}
	dp[0] = 1;
	for(int i = 1; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			if(i >> j & 1) {
				dp[i] += dp[i ^ (1 << j)] * p[j] / (1 - s[i ^ (1 << j)]);
			}
		}
	}
	for(int i = 0; i < (1 << n); i++) {
		if(c[i] == k) {
			for(int j = 0; j < n; j++) {
				if(i >> j & 1) {
					ans[j] += dp[i];
				}
			}
		}
	}
	cout.precision(20), cout << fixed;
	for(int i = 0; i < n; i++) cout << ans[i] <<" ";
	cout << endl;
	return 0;
}
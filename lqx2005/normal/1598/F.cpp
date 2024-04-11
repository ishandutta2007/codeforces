#include <bits/stdc++.h>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define sz(a) int((a).size())
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 20, L = 4e5 + 10;
int n, dp[1 << N], state[1 << N], L2[1 << N];
int stk[L], top = 0;
int mn[N], cnt[N], sum[N];
string s[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) L2[1 << i] = i;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		for(int j = 0; j < sz(s[i]); j++) {
			sum[i] += s[i][j] == '(' ? 1 : -1;
			if(mn[i] > sum[i]) {
				mn[i] = sum[i], cnt[i] = 1;
			} else if(mn[i] == sum[i]) cnt[i]++;
		}
	}
	for(int i = 1; i < (1 << n); i++) {
		int t = i & (-i);
		state[i] = state[i ^ t] + sum[L2[t]];
	}
	memset(dp, 0xc0, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < (1 << n); i++) {
		int s = state[i];
		for(int j = 0; j < n; j++) {
			if(i >> j & 1 || s + mn[j] < 0) continue;
			dp[i ^ (1 << j)] = max(dp[i ^ (1 << j)], dp[i] + (s + mn[j] == 0 ? cnt[j] : 0));
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		top = 0;
		int now = 0;
		for(int j = 0; j < sz(s[i]); j++) {
			now += s[i][j] == '(' ? 1 : -1;
			if(top == 0 || now <= stk[top]) stk[++top] = now;
		}
		for(int j = 0; j < (1 << n); j++) {
			if(j >> i & 1) continue;
			int l = lower_bound(stk + 1, stk + top + 1, - state[j], [&](int x, int y) {
				return x > y;
			}) - stk;
			int r = lower_bound(stk + 1, stk + top + 1, - state[j], [&](int x, int y) {
				return x >= y;
			}) - stk;
			ans = max(ans, dp[j] + r - l);			
		}
	}
	cout << ans << endl;
	return 0;
}
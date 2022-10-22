#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N], dp[N], len = 0, pre[N], pos[N], inc[N], tot = 0;
int b[N], vis[N], c[N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	sort(b + 1, b + m + 1);
	for(int i = 1; i <= n; i++) {
		if(a[i] == -1) {
			int las = len + 1;
			for(int j = m; j >= 1; j--) {
				while(las > 0 && dp[las - 1] >= b[j]) las--;
				if(las) dp[las] = b[j], pos[las] = pos[las - 1];
			}
			if(dp[len + 1]) len++;
		} else {
			if(dp[len] < a[i]) dp[++len] = a[i], pre[i] = pos[len - 1], pos[len] = i;
			else {
				int p = lower_bound(dp + 1, dp + len + 1, a[i]) - dp;
				pre[i] = pos[p - 1];
				dp[p] = a[i], pos[p] = i;
			}
		}
	}
	memcpy(c, a, sizeof(a));
	for(int i = pos[len]; i; i = pre[i]) inc[++tot] = i;
	reverse(inc + 1, inc + tot + 1);
	inc[0] = 0;
	inc[tot + 1] = n + 1, a[n + 1] = 2e9;
	int cur = 0;
	for(int i = 1; i <= tot + 1; i++) {
		int now = a[inc[i - 1]];
		for(int j = inc[i - 1] + 1; j < inc[i]; j++) {
			while(cur <= m && b[cur] <= now) cur++;
			if(c[j] == -1 && cur <= m && b[cur] < a[inc[i]]) {
				c[j] = b[cur];
				vis[cur] = 1;
				now = b[cur];
				cur++;
			}
		}
	}
	cur = 1;
	for(int i = 1; i <= n; i++) {
		if(c[i] == -1) {
			while(cur <= m && vis[cur]) cur++;
			c[i] = b[cur], vis[cur] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << c[i] <<" ";
	}
	cout << endl;
	return 0;
}
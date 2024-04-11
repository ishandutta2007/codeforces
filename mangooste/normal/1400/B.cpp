#include <bits/stdc++.h>

using namespace std;

#define int long long

int solve(int a, int aa, int b, int bb, int left) {
	assert(a <= b);
	int ans = 0;
	{
		int del = min(aa, left / a);
		left -= del * a;
		ans += del;
	}
	{
		int del = min(bb, left / b);
		left -= del * b;
		ans += del;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int p, f;
		cin >> p >> f;
		int cnt_s, cnt_w;
		cin >> cnt_s >> cnt_w;
		int s, w;
		cin >> s >> w;
		if (s > w) {
			swap(s, w);
			swap(cnt_s, cnt_w);
		}
		int ans = 0;
		for (int i = 0; i <= cnt_s; i++) {
			if (i * s > p)
				continue;
			int now = i;
			int left_p = p - i * s;
			now += min(left_p / w, cnt_w);
			int left_w = cnt_w - min(left_p / w, cnt_w);
 			ans = max(ans, now + solve(s, cnt_s - i, w, left_w, f));
		}
		cout << ans << '\n';
	}
}
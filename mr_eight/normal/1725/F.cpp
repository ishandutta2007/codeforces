#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10, M = 30;
int n, q, l[N], r[N];
int ans[M];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> l[i] >> r[i];
	}
	for(int c = 0; c < M; c ++) {
		int len = 1 << c, res = 0;
		vector<int> pos;
		vector<pair<int, int>> rng;
		auto add = [&] (int l, int r) {
			rng.emplace_back(l, r);
			pos.emplace_back(l);
			pos.emplace_back(r + 1);
		};
		for(int i = 1; i <= n; i ++) {
			if(r[i] - l[i] >= len) res ++;
			else {
				int p = l[i] % len, q = r[i] % len;
				if(p <= q) add(p, q);
				else add(p, len - 1), add(0, q);
			}
		}
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		vector<int> s(pos.size());
		for(auto [l, r] : rng) {
			l = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
			r = lower_bound(pos.begin(), pos.end(), r + 1) - pos.begin();
			s[l] ++;
			s[r] --;
		}
		int mx = s.empty() ? 0 : s[0];
		for(int i = 1; i < pos.size(); i ++) s[i] += s[i - 1], mx = max(mx, s[i]);
		ans[c] = mx + res;
	}
	cin >> q;
	for(int i = 0; i < q; i ++) {
		int x;
		cin >> x;
		cout << ans[__lg(x & -x)] << '\n';
	}
	return 0;
}
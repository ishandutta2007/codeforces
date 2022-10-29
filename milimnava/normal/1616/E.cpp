#include <bits/stdc++.h>
using namespace std;

struct fenwick {
	int f[100005], n;

	void init(int m) {
		n = m;
		for (int i = 1; i <= n; i++) f[i] = 0;
	}

	void add(int x, int y) {
		x = n - x + 1;
		while (x <= n) {
			f[x] += y;
			x += (x & -x);
		}
	}

	int query(int x) {
		x = n - x + 1;
		int ans = 0;
		while (x) {
			ans += f[x];
			x &= (x - 1);
		}
		return ans;
	}
} tr;

const long long INF = 1e18;

vector<int> pos[26];
int len[26];

int getfir(int id) {
	if (len[id] < (int)pos[id].size()) return pos[id][len[id]];
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<char> a(n + 1), b(n + 1);
		for (int i = 0; i < 26; i++) pos[i].clear(), len[i] = 0;
		for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i] - 'a'].push_back(i);
		for (int i = 1; i <= n; i++) cin >> b[i];
		auto geta = [&](int id) {
			int l = 1, r = n, ans = n;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (mid + tr.query(mid) <= id) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			return a[ans];
		};
		tr.init(n);
		long long now = 0, ans = INF;
		for (int i = 1; i <= n; i++) {
			if (geta(i) < b[i]) {
				ans = min(ans, now);
				break;
			}
			int minn = n + 1;
			for (int j = 0; j < b[i] - 'a'; j++) {
				int x = getfir(j);
				if (x != -1) minn = min(minn, x);
			}
			if (minn != n + 1) {
				ans = min(ans, now + minn + tr.query(minn) - i);
				// cout << now << " " << minn << " " << tr.query(minn) << " " << i << endl;
			}
			int tmp = getfir(b[i] - 'a');
			if (tmp == -1) break;
			now += tmp + tr.query(tmp) - i;
			tr.add(tmp, 1); ++len[b[i] - 'a'];
		}
		if (ans == INF) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
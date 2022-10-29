#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int mpow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		y >>= 1; x = 1ll * x * x % mod;
	}
	return ret;
}

int norm(int x) {
	return x >= mod ? x - mod : x;
}

int reduce(int x) {
	return x < 0 ? x + mod : x;
}

const int d[2] = {-1, 1};

int vis[100005][2][2];

struct state {
	int x, y, dx, dy;
	state(int x_ = 0, int y_ = 0, int dx_ = 0, int dy_ = 0) : x(x_), y(y_), dx(dx_), dy(dy_) {}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m, x, y, a, b, p;
		cin >> n >> m >> x >> y >> a >> b >> p;
		auto s = [&](int x, int y) { return (x - 1) * m + y; };
		p = 1ll * p * mpow(100, mod - 2) % mod; p = reduce(1 - p);
		memset(vis, 0, sizeof(vis));
		vector<state> seq;
		state now = state(x, y, 1, 1);
		int pos = 0;
		while (1) {
			seq.push_back(now);
			if (vis[s(now.x, now.y)][now.dx][now.dy]) {
				pos = vis[s(now.x, now.y)][now.dx][now.dy];
				break;
			}
			vis[s(now.x, now.y)][now.dx][now.dy] = (int)seq.size();
			if (now.x + d[now.dx] < 1 || now.x + d[now.dx] > n) now.dx ^= 1;
			if (now.y + d[now.dy] < 1 || now.y + d[now.dy] > m) now.dy ^= 1;
			now.x += d[now.dx]; now.y += d[now.dy];
		}
		--pos;
		int ca = 1, cb = 0;
		// for (int i = 0; i < (int)seq.size(); i++) cout << seq[i].x << " " << seq[i].y << endl;
		for (int i = (int)seq.size() - 2; i >= pos; i--) {
			if (seq[i].x == a || seq[i].y == b) {
				ca = 1ll * p * ca % mod, cb = 1ll * p * cb % mod;
				cb = norm(cb + p);
				continue;
			}
			cb = (cb + 1) % mod;
		}
		int ans = 1ll * cb * mpow(reduce(1 - ca), mod - 2) % mod;
		for (int i = pos - 1; i >= 0; i--) {
			if (seq[i].x == a || seq[i].y == b) {
				ans = 1ll * ans * p % mod;
				ans = norm(ans + p);
				continue;
			}
			ans = (ans + 1) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}
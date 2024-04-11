/*input
8 6
00110011
3
1 3 8
5
1 2 5 6 7
2
6 8
2
3 5
2
4 7
1
2
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _co(x);}
void _co() {cout << endl;}
template<typename T, typename... Ts> void _co(const T& value, const Ts&... values) {cout << ' ' << value; _co(values...);}
template<typename T, typename... Ts> void co(const T& value, const Ts&... values) {cout << "deb: " << value; _co(values...);}
// change cout to cerr for debug in crash
const int N = 3e5 + 5;
#define lock lock__

int ans, color[N];
struct dsu {
	int par[N]; vector<int> child[N]; bool lock[N]; int cnt[2][N];
	void init(int n) {
		iota(par, par + N, 0); loop(i, 0, N - 1) child[i].push_back(i);
		memset(lock, 0, sizeof(lock));
	}
	int find(int x) {
		return par[x] = (par[x] == x ? x : find(par[x]));
	}
	// update answer whenever cnt change // divide into lock and not lock cases
	int getMn(int u) {
		u = find(u);
		return min(cnt[0][u], cnt[1][u]);
	}
	void changeColor(int u, int c) {
		if (color[u] == c) return;
		assert(!isLock(u));
		int root = find(u);
		ans -= getMn(u);
		if (color[u] == -1)
			color[u] = c, cnt[c][root]++;
		else {
			for (auto v : child[root]) {
				cnt[color[v]][root]--; color[v] ^= 1; cnt[color[v]][root]++;
			}
		}
		ans += getMn(u);
	}
	void doLock(int u, int c) {
		changeColor(u, c); u = find(u);
		if (lock[u] == true) return;
		ans -= getMn(u);
		for (auto v : child[u]) {
			// update answer here
			ans += color[v];
		}
		// debug(xnt[0], xnt[1], cnt[0][u], cnt[1][u]);
		lock[u] = true;
	}
	bool isLock(int u) {
		return lock[find(u)];
	}
	void uni(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (sz(x) > sz(y)) swap(x, y);
		if (!isLock(x) && !isLock(y))
			ans -= getMn(x) + getMn(y);
		child[y].insert(child[y].end(), child[x].begin(), child[x].end());
		child[x].clear();
		loop(i, 0, 1) cnt[i][y] += cnt[i][x], cnt[i][x] = 0;
		par[x] = y; lock[y] = max(lock[y], lock[x]);
		if (!isLock(x) && !isLock(y))
			ans += getMn(y);
	}
	int sz(int u) {
		return child[find(u)].size();
	}
} d;

int n, m;
string s;
vector<int> aff[N];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(color, -1, sizeof(color));
	cin >> n >> m; d.init(m);
	cin >> s;
	loop(i, 0, m - 1) {
		int num; cin >> num;
		loop(j, 0, num - 1) {
			int t; cin >> t; t--;
			aff[t].push_back(i);
		}
	}
	loop(i, 0, n - 1) { // 2
		if (aff[i].size() == 1) {
			// debug(aff[i], s[i] - '0');
			d.doLock(aff[i][0], 1 - (s[i] - '0'));
		}
		else if (aff[i].size() == 2) {
			int C = s[i] - '0';
			auto &x = aff[i][0]; auto &y = aff[i][1];
			// debug(aff[i], s[i] - '0');
			if (color[x] == -1) d.changeColor(x, 0);
			if (color[y] == -1) d.changeColor(y, 0);
			if (d.sz(x) > d.sz(y)) swap(x, y);
			// debug(x, y);
			if (!d.isLock(x))d.changeColor(x, (C ^ 1) ^ color[y]);
			else d.changeColor(y, (C ^ 1) ^ color[x]);
			// debug(xnt[0], xnt[1], d.cnt[0][x], d.cnt[1][x]);

			// co(ans, xnt[0], xnt[1]);
			// x = d.find(x); co(d.child[x]); co(color[x]);
			if (d.isLock(x) || d.isLock(y)) {
				d.doLock(x, color[x]);
				d.doLock(y, color[y]);
			}
			d.uni(x, y);
		}
		// debug(ans, xnt[0], xnt[1]);
		cout << ans << endl;
	}
}
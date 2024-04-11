#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ld = long double;
const ll INF = (ll)1e9 + 7;

int sgn(ll v) {
	return (int)(v >= 0) - (int)(v <= 0);
}

struct Line {
	ll a = 0, b = 0;

	Line() : a(0), b(0) {}
	Line(ll av, ll bv) : a(av), b(bv) {}
	
	ll zeroPos() const {
		return -a/b;
	}
	bool operator<(const Line& rhs) const {
		return zeroPos() < rhs.zeroPos();
	}
	ll eval(ll x) const {
		return 2*a + b*x;
	}
};

struct State {
	ll low = -INF, high = INF;
	vector<Line> lines;
};

const int N = 1e5;

vector<int> conns[N][2];
Line val[N];
int vis[N];
ll res[N];


void dfs(int i, State& s) {
	vis[i] = 1;
	s.lines.push_back(val[i]);

	for (int c = 0; c <= 1; ++c) {
		for (auto t : conns[i][c]) {
			Line off(c+1 - val[i].a, -val[i].b);
			if (! vis[t]) {
				val[t] = off;
				dfs(t, s);
			} else {
				// a0 + b0 x = a1 + b1 x
				// a0 - a1 = (b1 - b0) x
				ll da = val[t].a - off.a;
				ll db = off.b - val[t].b;
				if (db == 0) {
					if (da == 0) continue;
					else {
						s.low = INF;
						s.high = -INF;
					}
				} else {
					ll tx = 2*da / db;
					s.low = max(s.low, tx);
					s.high = min(s.high, tx);
					// cerr << da << ' ' << db << ", solved for " << tx << " / 2" << endl;
				}
			}
		}
	}
}

void dfs2(int i, ll x) {
	if (vis[i] == 2) return;
	vis[i] = 2;
	res[i] = val[i].eval(x);
	for (int c = 0; c <= 1; ++c) {
		for (auto t : conns[i][c]) dfs2(t, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b; --c;
		conns[a][c].push_back(b);
		conns[b][c].push_back(a);
	}

	bool fail = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;

		val[i].a = 0;
		val[i].b = 1;

		State s;
		dfs(i, s);

		if (s.low > s.high) fail = 1;
		else if (s.low == s.high) dfs2(i, s.low);
		else {
			for (auto& ln : s.lines) ln.a *= 2;
			sort(s.lines.begin(), s.lines.end()); // Sort by x where they hit 0
			
			ll v = s.low, off = 0, delta = 0;
			for (auto ln : s.lines) {
				ll cv = ln.a + ln.b * v;
				off += abs(cv);
				if (sgn(cv) == ln.b) ++delta;
				else if ((cv == 0) || (sgn(cv) == -ln.b)) --delta;
			}
			ll opt_v = v, opt_off = off;

			for (auto ln : s.lines) {
				ll nxt_v = min(s.high, ln.zeroPos());
				if (nxt_v < v) continue; // those that will never hit zero

				off += delta * (nxt_v - v);
				v = nxt_v;

				if (off < opt_off) {
					opt_off = off;
					opt_v = v;
				}

				if (v == s.high) break;

				delta += 2;
			}
			dfs2(i, opt_v);
		}
	}
	if (fail) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			if (res[i] % 2 == 0) cout << res[i] / 2 << ' ';
			else if (res[i] == -1) cout << "-0.5" << ' ';
			else cout << res[i] / 2 << ".5" << ' ';
		}
		cout << '\n';
	}
}
#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
const int inf = 2e9;

bool Q = 0;
struct Line {
	mutable int m, b, x;

	bool operator < (const Line ot) const {
		return Q ? x < ot.x : m > ot.m;
	}
};

int ceil (int a, int b) {
	if (a < 0 != b < 0) return a / b;
	return (abs(a) + abs(b) - 1) / abs(b);
}

int intersection (const Line &p, const Line &q) {
	return ceil(q.b - p.b, p.m - q.m);
}

struct Hull : multiset<Line> {
	bool valid (auto it) {
		if (it == begin()) {
			auto sig = it;
			sig++;
			if (sig != end()) sig->x = intersection(*it, *sig);
			return it->x = -inf;
		}

		auto ant = it, sig = it;
		ant--, sig++;

		if (sig == end()) {
			it->x = intersection(*it, *ant);
			return 1;
		}

		int x = intersection(*it, *ant);
		int y = intersection(*it, *sig);

		if (x > y) return 0;
		it->x = x, sig->x = y;
		return 1;
	}

	void add (int m, int b) {
		auto it = lower_bound({m, b, -inf});

		if (it != end() && it->m == m) {
			if (it->b < b) return;
			it->b = b;
		} else {
			it = insert({m, b, -inf});
		}

		if (!valid(it)) {
			erase(it);
			return;
		}

		auto ant = it;
		while (ant != begin()) {
			if (valid(--ant)) break;
			erase(ant);
			if (it == begin()) { it->x = -inf; break; }
			ant = it;
		}

		auto sig = it;
		sig++;
		while (sig != end() && !valid(sig))
			erase(sig++);
	}

	int query (int x) {
		if (empty()) return 0;

		Q = 1;
		auto it = upper_bound({0, 0, x});
		it--;
		Q = 0;
		return x * it->m + it->b;
	}
};

int n, a[MX], pre[MX], q;
Hull st[4 * MX];

void build (int i, int j, int pos) {
	for (int k = i; k <= j; k++)
		st[pos].add(a[k], k * a[k] - pre[k]);
	
	if (i < j) {
		int m = (i + j) / 2;
		build(i, m, pos * 2);
		build(m + 1, j, pos * 2 + 1);
	}
}

int query (int i, int j, int pos, int a, int b, int x) {
	if (j < a || b < i) return inf;
	if (a <= i && j <= b) return st[pos].query(x);
	
	int m = (i + j) / 2;
	return min(
		query(i, m, pos * 2, a, b, x), 
		query(m + 1, j, pos * 2 + 1, a, b, x)
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = a[i] + pre[i - 1];
	}
	build(1, n, 1);
	
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << pre[y] + query(1, n, 1, y - x + 1, y, (x - y)) << endl;
	}
	
	return 0;
}
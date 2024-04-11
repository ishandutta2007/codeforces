#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU {
	private:
		vector<int> comp, siz;
	public:
		DSU(int n) : comp(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
		}
		int getc(int i) {
			if (comp[i] != i) comp[i] = getc(comp[i]);
			return comp[i];
		}
		bool join(int a, int b) {
			a = getc(a);
			b = getc(b);
			if (a == b) return false;

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;
			return true;
		}
		int compSize(int i) { return siz[getc(i)]; }
};

const int N = 2 * (int)1e5;
vector<pair<int, ll>> g[N];
int cmp[N];

void findCmp(int i, set<int>& unseen, int ind) {
	cmp[i] = ind;

	int j = 0;
	vector<int> tars;
	for (auto t : unseen) {
		while(j < g[i].size() && g[i][j].first < t) ++j;
		if (j < g[i].size() && g[i][j].first == t) ++j;
		else tars.push_back(t);
	}
	for (auto t : tars) unseen.erase(t);
	for (auto t : tars) findCmp(t, unseen, ind);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	ll cheap = 0;
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		--a; --b;

		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
		cheap ^= w;
	}
	
	for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());

	set<int> unseen;
	for (int i = 0; i < n; ++i) unseen.insert(i);

	int ind = 0;
	while(! unseen.empty()) {
		int s = *(unseen.begin());
		unseen.erase(s);
		findCmp(s, unseen, ind);
		++ind;
	}

	vector<pair<ll, pair<int, int>>> ed;
	for (int i = 0; i < n; ++i) {
		for (auto pr : g[i]) {
			int t = pr.first;
			if (t < i) continue;
			ed.emplace_back(pr.second, make_pair(i, t));
		}
	}
	sort(ed.begin(), ed.end());

	ll res = 0;
	DSU dsu1(ind);
	DSU dsu2(n);
	for (auto pr : ed) {
		int a = pr.second.first, b = pr.second.second;
		if (dsu1.join(cmp[a], cmp[b])) {
			res += pr.first;
			dsu2.join(a, b);
		} else if (dsu2.join(a, b)) {
			cheap = min(cheap, (ll)pr.first);
		}
	}

	ll alt_edc = (ll)n * (n-1) / 2 - m;
	if (ind == n - alt_edc) res += cheap;
	cout << res << '\n';
}
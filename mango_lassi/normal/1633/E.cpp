#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

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

ll answer(ll x, const vector<ll>& xs, const vector<ll>& bases, const vector<ll>& adds) {
	int i = bins(xs, x + 1) - 1;
	return bases[i] + adds[i] * (x - xs[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<ll, pair<int, int>>> ed(m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll x;
		cin >> a >> b >> x;
		ed[i] = {x, {a-1, b-1}};
	}
	sort(ed.begin(), ed.end());

	vector<ll> xs = {{0ll}};
	for (int i = 0; i < m; ++i) {
		xs.push_back(ed[i].first);
		for (int j = i + 1; j < m; ++j) {
			// Point where edge j becomes STRICTLY cheaper than edge i
			ll h = (ed[i].first + ed[j].first) / 2 + 1;
			xs.push_back(h);
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	
	int k = xs.size();
	vector<ll> bases(k, 0), adds(k, 0);
	for (int i = 0; i < k; ++i) {
		vector<pair<ll, int>> ed_ord(m);
		for (int j = 0; j < m; ++j) ed_ord[j] = {abs(ed[j].first - xs[i]), j};
		sort(ed_ord.begin(), ed_ord.end());

		DSU dsu(n);
		for (auto pr : ed_ord) {
			int j = pr.second;
			if (dsu.join(ed[j].second.first, ed[j].second.second)) {
				bases[i] += pr.first;
				adds[i] += (ed[j].first > xs[i]) ? -1 : 1;
			}
		}
	}

	// for (int i = 0; i < k; ++i) cerr << xs[i] << ' ' << bases[i] << ' ' << adds[i] << '\n';
	
	ll res = 0;

	int p, q;
	ll a, b, c;
	cin >> p >> q >> a >> b >> c;
	for (int i = 0; i + 1 < p; ++i) {
		ll x;
		cin >> x;
		res ^= answer(x, xs, bases, adds);
	}

	ll x;
	cin >> x;
	for (int ind = p-1; ind < q; ++ind, x = (a*x + b) % c) res ^= answer(x, xs, bases, adds);
	
	cout << res << '\n';
}
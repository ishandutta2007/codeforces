#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const int N = 600;
const int M = N * N;
vector<pair<ll, int>> triples[N];
vector<int> g[N];
ll dist[N][N];
ll off[N];
int as[M];
int bs[M];
ll wgs[M];

// Struct for priority queue operations on index set [1, n]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct Prique {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;

	Prique(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
	void push(int i, ll v) {
		data[i+n] = {v, (v >= INF ? -1 : i)};
		for (i += n; i > 1; i >>= 1) data[i>>1] = min(data[i], data[i^1]);
	}
	void decKey(int i, ll v) {
		for (int j = i+n; data[j].first > v; j >>= 1) data[j] = {v, i};
	}
	pair<ll, int> pop() {
		auto res = data[1];
		push(res.second, INF);
		return res;
	}
};

void djikstra(int src, int n) {
	for (int i = 0; i < n; ++i) dist[src][i] = INF;
	dist[src][src] = 0;
	Prique que(n);

	for (int i = src; i != -1; i = que.pop().second) {
		for (auto ei : g[i]) {
			int t = as[ei] ^ bs[ei] ^ i;
			ll off = dist[src][i] + wgs[ei];
			if (off < dist[src][t]) {
				dist[src][t] = off;
				que.decKey(t, off);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> as[i] >> bs[i] >> wgs[i];
		--as[i]; --bs[i];
		g[as[i]].push_back(i);
		g[bs[i]].push_back(i);
	}

	for (int i = 0; i < n; ++i) djikstra(i, n);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		ll h;
		cin >> a >> b >> h;
		--a; --b;

		triples[a].emplace_back(h, b);
		triples[b].emplace_back(h, a);
	}

	int res = 0;
	for (int a = 0; a < n; ++a) {
		for (int i = 0; i < n; ++i) {
			off[i] = -INF;
			for (auto& pr : triples[i]) off[i] = max(off[i], pr.first - dist[a][pr.second]);
		}
		for (int ei : g[a]) {
			int b = as[ei] ^ bs[ei] ^ a;
			bool works = 0;
			for (int i = 0; i < n; ++i) works |= (dist[b][i] + wgs[ei] <= off[i]);
			res += works;
		}
	}
	cout << (res / 2) << '\n';
}
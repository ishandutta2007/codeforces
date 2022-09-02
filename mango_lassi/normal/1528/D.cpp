#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ops = 0;

int mAdd(int a, int b, int mod) {
	return (a + b >= mod ? a + b - mod : a + b);
}

// Struct for priority queue operations on index set [0, n-1]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct Prique {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;

	Prique(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
	bool empty() const { return data[1].second >= INF; }
	pair<ll, int> top() const { return data[1]; }

	void push(int i, ll v) {
		++ops;
		data[i+n] = {v, (v >= INF ? -1 : i)};
		for (i += n; i > 1; i >>= 1) data[i>>1] = min(data[i], data[i^1]);
	}
	void decKey(int i, ll v) {
		++ops;
		for (int j = i+n; data[j].first > v; j >>= 1) data[j] = {v, i};
	}
	pair<ll, int> pop() {
		auto res = data[1];
		push(res.second, INF);
		return res;
	}
};

const ll INF = 1e18;
const int N = 600;
vector<pair<int, ll>> edges[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int j = 0; j < m; ++j) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		edges[a].emplace_back(b, c);
	}

	for (int s = 0; s < n; ++s) {
		vector<ll> dist(n, INF);
		Prique pq(n);

		for (auto pr : edges[s]) {
			int t = pr.first;
			ll c = pr.second;
			dist[t] = c;
			pq.decKey(t, c);
		}

		for (int i = pq.pop().second; i != -1; i = pq.pop().second) {
			ll c = dist[i];
			int sf = c % n;
			for (auto pr : edges[i]) {
				int t = mAdd(pr.first, sf, n);
				ll off = c + pr.second;
				if (dist[t] > off) {
					dist[t] = off;
					pq.decKey(t, off);
				}
			}
			
			int t = mAdd(i, 1, n);
			if (dist[t] > c + 1) {
				dist[t] = c + 1;
				pq.decKey(t, c + 1);
			}
		}

		dist[s] = 0;
		for (int i = 0; i < n; ++i) cout << dist[i] << ' '; cout << '\n';
	}

	double rat = (double)ops / (N*N*N);
	cerr << rat << endl;
	assert(rat <= 0.05);
}
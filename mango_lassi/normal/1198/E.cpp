#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e9;

// Struct for priority queue operations on
// index set [1, n] with really good constants
// decKey pushes index if it doesn't exist yet
struct FastPrique {
	const int n, INF = 1e9;
	vector<pair<int, int>> seg;

	FastPrique(int nn) : n(nn), seg(2*nn, {INF, -1}) {
		seg[0] = {-INF, -1};
	}
	void setKey(int i, int v) {
		seg[i+n] = {v, i};
		for (int j = i+n; j > 1; j /= 2) seg[j/2] = min(seg[j], seg[j^1]);
	}
};

// FIFO push-relabel algorithm for max flow
// Complexity: O(V^3 log V)
class PushRelabel {
	private:
		const int source, sink, n;
		vector<vector<ll>> cap, flow;
		vector<FastPrique> adj;
		vector<ll> excess;
		vector<int> label;
		vector<int> nxt;

		void push(int i, int t, ll v) {
			excess[i] -= v;
			excess[t] += v;
			flow[i][t] += v;
			flow[t][i] -= v;
			if (cap[i][t] - flow[i][t] == 0)  adj[i].setKey(t, 2*n);
			if (cap[t][i] - flow[t][i] == v) adj[t].setKey(i, label[i]);
			if (excess[t] == v && t != source && t != sink) nxt.push_back(t);
		}
		void fix(int i) {
			while(excess[i] > 0) {
				int h, t;
				tie(h, t) = adj[i].seg[1];
				if (label[t] > h) {
					adj[i].setKey(t, label[t]);
				} else {
					label[i] = max(label[i], label[t] + 1); // (possibly) relabel
					push(i, t, min(cap[i][t] - flow[i][t], excess[i])); // push flow
				}
			}
		}
	public:
		PushRelabel(int nn, int s, int t)
			: source(s), sink(t), n(nn), cap(nn, vector<ll>(nn, 0)), flow(nn, vector<ll>(nn, 0)), adj(nn, FastPrique(nn)), excess(nn, 0), label(nn, 0) {
			label[s] = nn;
		}
		void addEdge(int a, int b, ll c, bool dir = 1) {
			cap[a][b] += c;
			if (! dir) cap[b][a] += c;
		}
		ll pushFlow() {
			for (int i = 0; i < n; ++i) {
				for (int t = 0; t < n; ++t) {
					if (cap[i][t] > 0) adj[i].setKey(t, label[t]);
				}
				
			}
			for (int t = 0; t < n; ++t) excess[source] += cap[source][t];

			nxt = {source};
			while(! nxt.empty()) {
				vector<int> que;
				swap(que, nxt);
				for (auto i : que) fix(i);
			}
			return excess[sink];
		}
		ll getFlow(int a, int b) const { return flow[a][b]; }
};

 
// Finds first that is >= val
int bins(const vector<int>& vec, int val) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < val) low = mid + 1;
		else high = mid;
	}
	return low;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
 
	vector<pair<int, int>> xs(m);
	vector<pair<int, int>> ys(m);
 
	vector<int> xev(2*m);
	vector<int> yev(2*m);
 
	for (int i = 0; i < m; ++i) {
		cin >> xs[i].first >> ys[i].first >> xs[i].second >> ys[i].second;
		++xs[i].second;
		++ys[i].second;
		xev[2*i] = xs[i].first;
		xev[2*i+1] = xs[i].second;
		yev[2*i] = ys[i].first;
		yev[2*i+1] = ys[i].second;
	}
	sort(xev.begin(), xev.end());
	sort(yev.begin(), yev.end());
	xev.erase(unique(xev.begin(), xev.end()), xev.end());
	yev.erase(unique(yev.begin(), yev.end()), yev.end());
 
	for (int i = 0; i < m; ++i) {
		xs[i].first = bins(xev, xs[i].first);
		xs[i].second = bins(xev, xs[i].second);
		ys[i].first = bins(yev, ys[i].first);
		ys[i].second = bins(yev, ys[i].second);
	}
 
	n = xev.size() + yev.size() + 2;
	int source = n - 2;
	int sink = n - 1;
 
	PushRelabel mf(n, source, sink);
	for (int i = 0; i < m; ++i) {
		for (int a = xs[i].first; a < xs[i].second; ++a) {
			for (int b = ys[i].first; b < ys[i].second; ++b) {
				mf.addEdge(a, b + xev.size(), INF);
				// cout << "addEdge " << a << ' ' << b << '\n';
			}
		}
	}
	for (int i = 0; i+1 < xev.size(); ++i) {
		// cout << "x " << i << ": " << xev[i+1] << ' ' << xev[i] << '\n';
		mf.addEdge(source, i, xev[i+1] - xev[i]);
	}
	for (int i = 0; i+1 < yev.size(); ++i) {
		// cout << "y " << i << ": " << yev[i+1] << ' ' << yev[i] << '\n';
		mf.addEdge(i + xev.size(), sink, yev[i+1] - yev[i]);
	}
 
	ll res = mf.pushFlow();
	cout << res << '\n';
}
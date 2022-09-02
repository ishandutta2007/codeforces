#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Struct for priority queue operations on index set [0, n-1]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct Prique {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;

	Prique(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
	bool empty() const { return data[1].first >= INF; }
	pair<ll, int> top() const { return data[1]; }

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

const int INF = (int)1e9 + 7;
const int N = 2 * (int)1e5;
vector<int> ins[N];
int deg[N];
int dp[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		ins[b-1].push_back(a-1);
		++deg[a-1];
	}
	for (int i = 0; i < n; ++i) dp[i] = INF;
	dp[n-1] = 0;

	Prique pq(n);
	pq.decKey(n-1, 0);
	while(! pq.empty()) {
		auto pr = pq.top();
		int i = pq.pop().second;
		if (i == -1) assert(false);
		for (int t : ins[i]) {
			--deg[t];
			int off = dp[i] + deg[t] + 1;
			if (off < dp[t]) {
				dp[t] = off;
				pq.decKey(t, off);
			}
		}
	}
	cout << dp[0] << '\n';
}
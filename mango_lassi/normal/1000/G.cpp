#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 3 * (int)(1e5);
const int Q = 4 * (int)(1e5);
const int L = 20;

ll val[N];
vector<int> conns[N];
vector<int> costs[N];

int ind[N];
int parent[N][L];
int depth[N];
ll dp[N];
ll pew[N];

ll base[2 * Q];
int int_start[2 * Q];
int int_end[2 * Q];
ll adjust[Q];
vector<pair<int, pair<int, int>>> que;

ll seg[4 * N];
int h;

ll getSum(int a, int b, int ia = 0, int ib = h-1, int i = 1) {
	if (ib < a || b < ia) return 0;
	if (a <=ia && ib<= b) return seg[i];
	int mid = (ia + ib) >> 1;
	return getSum(a, b, ia, mid, 2*i) + getSum(a, b, mid+1, ib, 2*i+1);
}

void setVal(int i, ll v) {
	i += h;
	seg[i] = v;
	while(i > 1) {
		seg[i >> 1] = seg[i] + seg[i^1];
		i >>= 1;
	}
}

ll dfs1(int i, int p, int d, int& j) {
	ind[i] = j;
	++j;

	parent[i][0] = p;
	dp[i] = val[i];
	depth[i] = d;

	for (int ti = 0; ti < conns[i].size(); ++ti) {
		int t = conns[i][ti];
		int w = costs[i][ti];
		if (t == p) continue;
		pew[t] = w;
		ll off = dfs1(t, i, d+1, j) - 2 * w;
		dp[i] += max((ll)0, off);
	}
	return dp[i];
}

void dfs2(int i, int p, int& que_ind, ll curr_total, ll up_off) {
	// Get offers below
	ll sum_off = 0;
	for (int ti = 0; ti < conns[i].size(); ++ti) {
		int t = conns[i][ti];
		int w = costs[i][ti];
		if (t == p) continue;
		ll off = dp[t] - 2 * w;
		if (off > 0) sum_off += off;
	}
	setVal(depth[i], sum_off);

	// cout << "dfs2 (i p sum curr up) " << i << ' ' << p << ' ' << sum_off << ' ' << curr_total << ' ' << up_off << '\n';
	// Handle events
	for (; (que_ind < que.size()) && (que[que_ind].first == ind[i]); ++que_ind) {
		int ty = que[que_ind].second.first;
		int in = que[que_ind].second.second;
		if (ty == -1) {
			// cout << "start event (up1 sum1 curr-2) " << up_off << ' ' << sum_off << ' ' << curr_total << '\n';
			base[in] += up_off + sum_off - 2 * curr_total;
		} else {
			// cout << "end event (curr2 segsum2) " << (curr_total + val[i]) << ' ' << getSum(depth[int_start[in]] + 1, depth[int_end[in]]) << '\n';
			base[in] += 2 * (curr_total + val[i]);
			base[in] += 2 * getSum(depth[int_start[in]] + 1, depth[int_end[in]]);
		}
	}
	// Recurse to children
	for (int ti = 0; ti < conns[i].size(); ++ti) {
		int t = conns[i][ti];
		ll w = costs[i][ti];
		if (t == p) continue;

		ll off = dp[t] - 2 * w;
		ll sub_sum_off = sum_off - max((ll)0, off);
		setVal(depth[i], sub_sum_off);

		ll next_total = curr_total + val[i] - w;
		ll next_up_off = max((ll)0, up_off + sub_sum_off + val[i] - 2 * w);

		dfs2(t, i, que_ind, next_total, next_up_off);
	}
}

int lca(int& a, int& b) {
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b] - 1;
	if (diff >= 0) {
		for (int j = L-1; j >= 0; --j) {
			if(diff & (1<<j)) a = parent[a][j];
		}
		if (parent[a][0] != b) {
			a = parent[a][0];
		} else {
			return b;
		}
	}
	for (int j = L-1; j >= 0; --j) {
		if (parent[a][j] != parent[b][j]) {
			a = parent[a][j];
			b = parent[b][j];
		}
	}
	if (a != b) return parent[a][0];
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	h = 1; // Size of the segment tree
	while(h < n) h <<= 1; 

	for (int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b, w;
		std::cin >> a >> b >> w;
		--a; --b;

		conns[a].push_back(b);
		conns[b].push_back(a);

		costs[a].push_back(w);
		costs[b].push_back(w);
	}

	int tmp = 0;
	dfs1(0, 0, 0, tmp);
	for (int j = 1; j < L; ++j) {
		for (int i = 0; i < n; ++i) {
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
	// for (int i = 0; i < n; ++i) cout << dp[i] << ' '; cout << '\n';

	for (int i = 0; i < q; ++i) {
		int ca, cb;
		cin >> ca >> cb;
		--ca; --cb;
		int a = ca;
		int b = cb;
		int c = lca(ca, cb);

		int_start[2*i] = c;
		int_end[2*i] = a;
		que.push_back({ind[c], {-1, 2*i}}); // Start event
		que.push_back({ind[a], { 1, 2*i}}); // End event

		int_start[2*i+1] = c;
		int_end[2*i+1] = b;
		que.push_back({ind[c], {-1, 2*i+1}}); // Start event
		que.push_back({ind[b], { 1, 2*i+1}}); // End event

		// Fix double counting
		// cout << "adjust (i c ca cb, val[c]2 dp[ca]1 pew[ca]-2 dp[cb]1 pew[cb]-2) " << i << ' ' << c << ' ' << ca << ' ' << cb << ' ' << val[c] << ' ' << dp[ca] << ' ' << pew[ca] << ' ' << dp[cb] << ' ' << pew[cb] << '\n';
		adjust[i] += 2 * val[c]; // Double counting of LCA
		if (ca != c) {
			ll off = dp[ca] - 2 * pew[ca]; // Counting A-branch
			adjust[i] += 2 * max((ll)0, off);
		}
		if (cb != c) {
			ll off = dp[cb] - 2 * pew[cb]; // Countin B-branch
			adjust[i] += 2 * max((ll)0, off);
		}
	}
	sort(que.begin(), que.end());

	tmp = 0;
	dfs2(0, 0, tmp, 0, 0);
	for (int i = 0; i < q; ++i) {
		// cout << "Answer " << i << ": " << base[2*i] << ' ' << base[2*i+1] << ' ' << adjust[i] << '\n';
		cout << (base[2*i] + base[2*i+1] - adjust[i]) / 2 << ' ';
	}
	cout << '\n';
}
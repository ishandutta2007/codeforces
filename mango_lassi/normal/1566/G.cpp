#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

const ll INF = (ll)1e18 + 7;
const int N = 2 * (int)1e5;
const int Q = 1e5;
const int K = 100; // 300;
const int D = 20;
int col[N];
ll ans[4*Q];
vector<pair<pair<int, int>, int>> itvs[4*Q];
ll adjs[N][D][4];

void placeSegs(int i, int a, int b, const vector<pair<pair<int, int>, pair<pair<int, int>, int>>>& segs) {
	vector<pair<pair<int, int>, pair<pair<int, int>, int>>> ch;
	for (auto pr : segs) {
		if (pr.first.first <= a && b <= pr.first.second) {
			itvs[i].push_back(pr.second);
		} else if (a <= pr.first.second && pr.first.first <= b) {
			ch.push_back(pr);
		}
	}
	if (a != b) {
		int im = (a + b) >> 1;
		placeSegs(2*i, a, im, ch);
		placeSegs(2*i+1, im + 1, b, ch);
	}
}

void recSolve(int i, int ia, int ib, ll zeros, ll ones) {
	for (auto pr : itvs[i]) {
		int a = pr.first.first;
		int b = pr.first.second;
		ll w = pr.second;
		if (col[a] == col[b]) {
			if (col[a] == 0) zeros = min(zeros, w);
			else ones = min(ones, w);
		}
	}

	if (ia == ib) ans[i] = min(ans[i], zeros + ones);
	else {
		int im = (ia + ib) >> 1;
		recSolve(2*i, ia, im, zeros, ones);
		recSolve(2*i + 1, im + 1, ib, zeros, ones);
	}
}

ll offerEdge(int i, ll w, int d, int ind) {
	if (adjs[i][d][3] != ind) {
		// Copy from last occurrence
		for (int si = (ind >> 1), sd = d - 1;; si >>= 1, --sd) {
			if (adjs[i][sd][3] == si) {
				for (int it = 0; it < 3; ++it) adjs[i][d][it] = adjs[i][sd][it];
				break;
			}
		}
		adjs[i][d][3] = ind;
	}

	ll off = 0;
	for (int it = 0; it < 3; ++it) {
		if (w < adjs[i][d][it]) swap(w, adjs[i][d][it]);
		off += adjs[i][d][it];
	}
	return off;
}
void solveAdjs(int i, int ia, int ib, int d, ll res) {
	for (auto pr : itvs[i]) {
		int a = pr.first.first;
		int b = pr.first.second;
		ll w = pr.second;

		res = min(res, offerEdge(a, w, d, i));
		res = min(res, offerEdge(b, w, d, i));
	}
	if (ia == ib) ans[i] = min(ans[i], res);
	else {
		int im = (ia + ib) >> 1;
		solveAdjs(2*i, ia, im, d + 1, res);
		solveAdjs(2*i + 1, im + 1, ib, d + 1, res);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < K; ++j) cols[i][j] = rand(0, 1);
	}
	*/

	vector<array<int, 4>> evs;
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		if (a > b) swap(a, b);

		array<int, 4> ev;
		ev[0] = a - 1;
		ev[1] = b - 1;
		ev[2] = 0;
		ev[3] = w;
		evs.push_back(ev);
	}

	int q;
	cin >> q;
	
	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 0) {
			int a, b;
			cin >> a >> b;
			if (a > b) swap(a, b);

			array<int, 4> ev;
			ev[0] = a - 1;
			ev[1] = b - 1;
			ev[2] = qi + 1;
			ev[3] = -1;
			evs.push_back(ev);
		} else {
			int a, b, w;
			cin >> a >> b >> w;
			if (a > b) swap(a, b);

			array<int, 4> ev;
			ev[0] = a - 1;
			ev[1] = b - 1;
			ev[2] = qi + 1;
			ev[3] = w;
			evs.push_back(ev);
		}
	}

	sort(evs.begin(), evs.end());
	vector<pair<pair<int, int>, pair<pair<int, int>, int>>> segs;
	for (int i = 0; i < evs.size(); ++i) {
		int a = evs[i][0];
		int b = evs[i][1];
		pair<pair<int, int>, int> ed = {{a, b}, evs[i][3]};
		if (i + 1 >= evs.size() || evs[i+1][0] != a || evs[i+1][1] != b) {
			segs.emplace_back(make_pair(evs[i][2], q), ed);
		} else {
			segs.emplace_back(make_pair(evs[i][2], evs[i+1][2] - 1), ed);
			++i;
		}
	}
	
	int h = 1;
	while(h <= q) h *= 2;
	placeSegs(1, 0, h-1, segs);

	// Solve with two disjoint edges
	for (int i = h; i <= h + q; ++i) ans[i] = INF;
	for (int j = 0; j < K; ++j) {
		for (int i = 0; i < n; ++i) col[i] = rand(0, 1);
		recSolve(1, 0, h-1, INF, INF);
	}

	// Solve with three adjacent edges
	for (int i = 0; i < n; ++i) {
		adjs[i][0][0] = INF;
		adjs[i][0][1] = INF;
		adjs[i][0][2] = INF;
		adjs[i][0][3] = 0;
	}
	solveAdjs(1, 0, h-1, 1, INF);

	for (int i = h; i <= h + q; ++i) cout << ans[i] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}
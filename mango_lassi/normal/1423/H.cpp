#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

class DSU {
	private:
		vector<int> comp, siz, sta;
	public:
		DSU(int n) : comp(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
		}
		int getc(int i) {
			if (comp[i] != i) return getc(comp[i]);
			else return i;
		}
		bool join(int a, int b) {
			a = getc(a);
			b = getc(b);
			if (siz[a] < siz[b]) swap(a, b);

			sta.push_back(b);
			if (a == b) return false;

			siz[a] += siz[b];
			comp[b] = a;
			return true;
		}
		void undo() {
			int b = sta.back();
			int a = comp[b];
			sta.pop_back();

			if (a != b) siz[a] -= siz[b];
			comp[b] = b;
		}
		int compSize(int i) {
			return siz[getc(i)];
		}
};

class OfflineUndo {
	private:
		vector<vector<pair<int, int>>> ops;
		vector<vector<pair<int, int>>> queries;
		int n, h = 1, q = 0;
 
		void recAddOp(int a, int b, const pair<int, int> op, int i, int ia, int ib) {
			if (b <= ia || ib <= a) return;
			if (a <= ia && ib <= b) ops[i].emplace_back(op);
			else {
				int mid = (ia + ib) >> 1;
				recAddOp(a, b, op, 2*i, ia, mid);
				recAddOp(a, b, op, 2*i+1, mid, ib);
			}
		}
	public:
		OfflineUndo(int n_, int m) : n(n_) {
			while(h < m) h <<= 1;
			ops.resize(2*h);
			queries.resize(h);
		}
 
		void addOp(int a, int b, pair<int, int> op) {
			recAddOp(a, b+1, op, 1, 0, h);
		}
		void addQuery(int t, int i) {
			queries[t].emplace_back(i, q);
			++q;
		}
		vector<int> solve() {
			if (q == 0) return {};
 
			DSU dsu(n);
			vector<int> res(q, -1);
			for (int i = 1;;) {
				for (auto pr : ops[i]) dsu.join(pr.first, pr.second);
				if (i < h) i *= 2;
				else {
					for (auto que : queries[i - h]) res[que.second] = dsu.compSize(que.first);
					while(i) {
						for (auto pr : ops[i]) dsu.undo();
						if (i & 1) i >>= 1;
						else break;
					}
					if (i == 0) return res;
					i ^= 1;
				}
			}
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q, k;
	cin >> n >> q >> k;

	OfflineUndo solver(n, q);

	vector<int> nights = {0};
	vector<pair<pair<int, int>, pair<int, int>>> ops;
	for (int qi = 0; qi < q; ++qi) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int a, b;
			cin >> a >> b;
			ops.push_back({{qi, nights.size() + (k-1)}, {a-1, b-1}});
		} else if (tp == 2) {
			int i;
			cin >> i;
			solver.addQuery(qi, i-1);
		} else {
			nights.push_back(qi);
		}
	}
	nights.push_back(q);
	for (auto pr : ops) solver.addOp(pr.first.first, nights[min((int)nights.size() - 1, pr.first.second)], pr.second);

	auto res = solver.solve();
	for (auto v : res) cout << v << '\n';
}
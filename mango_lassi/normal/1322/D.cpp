#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1e9;

class RangeMin {
	private:
		vector<int> seg;
		int n;
	public:	
		RangeMin() {}
		void init(const vector<int>& v) {
			n = v.size();
			seg.resize(2*n);
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}
		int get(int i) const {
			return seg[i+n];
		}
		int get(int a, int b) const {
			if (a >= n) return INF;

			int res = INF;
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
		void cap(int i, int v) {
			seg[i+n] = min(seg[i+n], v);
			for (i += n; i > 1; i /= 2) seg[i/2] = min(seg[i], seg[i^1]);
		}
};

const int H = 11;
const int B = 1 << (H - 1);
const int N = 2000;
RangeMin seg[1<<H][2]; // with and without overflow
int offs[1<<H][2];
int sum[1<<H][N + H];

pair<int, int> add(int mask, int a0, int d) {
	int ans = mask + 1;
	mask = (mask ^ ans) & ((1 << d) - 1);
	return {ans, sum[mask][a0]};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < (1 << H); ++i) {
		seg[i][0].init(vector<int>(m, INF));
		seg[i][1].init(vector<int>(m, INF));
	}
	seg[0][0].cap(m-1, 0);
	seg[0][1].cap(m-1, 0);
	
	vector<int> as(n), rec(n);
	vector<int> prof(n+m);
	for (int& v : as) {
		cin >> v;
		--v;
	}
	for (int& v : rec) cin >> v;
	for (int& v : prof) cin >> v;

	for (int i = 0; i < n + H; ++i) {
		for (int x = 0; x < (1 << H); ++x) {
			for (int j = 0; j < H && i+j < n+m; ++j) {
				if (x & (1 << j)) sum[x][i] += prof[i+j];
			}
		}
	}

	for (int x = 0; x < (1 << H); ++x) {
		offs[x][0] = -INF;
		offs[x][1] = -INF;
	}
	for (int i = 0; i < n; ++i) {
		for (int x = 0; x < (1 << H); ++x) {
			// Previous at least H larger
			int off = 0;
			off += -seg[x][0].get(as[i] + H, m-1);

			off += prof[as[i]] - rec[i];
			offs[1][0] = max(offs[1][0], off);
			offs[1][1] = max(offs[1][1], off);

			// Previous d at most H-1 larger
			for (int d = min(m-1 - as[i], H-1); d >= 0; --d) {
				off = 0;
				off -= rec[i];

				auto sub = add(x << d, as[i], H);
				int mask = sub.first;
				off += sub.second;

				// Did overflow occur?
				bool ovf = (mask >= (1 << (d + H)));

				// Would overflow occur if we overflowed the new number?
				auto sub2 = add(mask >> H, as[i] + H, d);
				bool ovf2 = (sub2.first >= (1 << d));
				int ova = sub2.second;

				mask &= (1 << H) - 1;

				for (int t = 0; t < 2; ++t) {
					if (t == 0 && !ovf) {
						int tmp = off - seg[x][t].get(as[i] + d);
						offs[mask][0] = max(offs[mask][0], tmp);
						if (!ovf2) offs[mask][1] = max(offs[mask][1], tmp + ova);
					} else if (t == 1) {
						int tmp = off - seg[x][t].get(as[i] + d);
						if (ovf) offs[mask][0] = max(offs[mask][0], tmp);
						if (ovf || ovf2) offs[mask][1] = max(offs[mask][1], tmp + ova);
					}
				}
			}
		}
		for (int x = 0; x < (1 << H); ++x) {
			seg[x][0].cap(as[i], -offs[x][0]);
			seg[x][1].cap(as[i], -offs[x][1]);
			offs[x][0] = -INF;
			offs[x][1] = -INF;
		}
	}

	int res = 0;
	for (int x = 0; x < (1 << H); ++x) {
		res = max(res, -seg[x][0].get(0, m-1));
	}
	cout << res << '\n';
}
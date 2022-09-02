#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			for (++i; i < val.size(); i += i & -i) {
				val[i] += v;
			}
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) {
				res += val[i];
			}
			return res;
		}
		ll get(int a, int b) { return get(b) - get(a-1); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	vector<Fenwick> dp_row(h, w);
	vector<Fenwick> dp_col(w, h);
	vector<vector<int>> rocks_row(h, vector<int>(w+1, 0));
	vector<vector<int>> rocks_col(w, vector<int>(h+1, 0));

	// DP[x][y][0]: DP if we have to start by moving right
	// DP[x][y][1]: DP if we have to start by moving down

	for (int y = 0; y < h; ++y) {
		string row;
		cin >> row;
		for (int x = 0; x < w; ++x) {
			if (row[x] == 'R') {
				++rocks_row[y][x];
				++rocks_col[x][y];
			}
		}
	}
	for (int y = 0; y < h; ++y) {
		for (int x = w-1; x >= 0; --x) rocks_row[y][x] += rocks_row[y][x+1];
	}
	for (int x = 0; x < w; ++x) {
		for (int y = h-1; y >= 0; --y) rocks_col[x][y] += rocks_col[x][y+1];
	}

	dp_row[h-1].add(w-1, 1);
	dp_col[w-1].add(h-1, 1);
	for (int s = h-1 + w-1 - 1; s >= 0; --s) {
		for (int y = 0; y < h; ++y) {
			int x = s - y;
			if (x < 0 || x >= w) continue;

			int lst_x = w-1 - rocks_row[y][x+1];
			int lst_y = h-1 - rocks_col[x][y+1];
			ll hori = dp_row[y].get(x+1, lst_x) % MOD;
			ll vert = dp_col[x].get(y+1, lst_y) % MOD;
			dp_row[y].add(x, vert);
			dp_col[x].add(y, hori);

			// cerr << x << ' ' << y << ' ' << lst_x << ' ' << lst_y << ' ' << hori << ' ' << vert << '\n';
		}
	}

	if (w == 1 && h == 1) {
		cout << 1 << '\n';
	} else {
		ll res = (dp_row[0].get(0, 0) + dp_col[0].get(0, 0)) % MOD;
		cout << res << '\n';
	}
}
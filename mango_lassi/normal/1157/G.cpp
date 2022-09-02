#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 200;

struct Mat {
	bool data[N][N];
	bool f_row[N];
	bool f_col[N];

	int w, h, ones;

	Mat(int h, int w) {
		this->w = w;
		this->h = h;
		ones = 0;

		for (int i = 0; i < N; ++i) {
			f_row[i] = 0;
			f_col[i] = 0;
			for (int j = 0; j < N; ++j) {
				data[i][j] = 0;
			}
		}
	}

	void set(int y, int x, int v) {
		ones -= data[y][x] - v;
		data[y][x] = v;
	}
	bool get(int y, int x) {
		return data[y][x];
	}
	void flip(int y, int x) {
		set(y, x, get(y, x) ^ 1);
	}
	void flipCol(int x) {
		for (int y = 0; y < h; ++y) flip(y, x);
		f_col[x] ^= 1;
	}
	void flipRow(int y) {
		for (int x = 0; x < w; ++x) flip(y, x);
		f_row[y] ^= 1;
	}
	void print() {
		cout << "YES\n";
		for (int y = 0; y < h; ++y) cout << f_row[y]; cout << '\n';
		for (int x = 0; x < w; ++x) cout << f_col[x]; cout << '\n';
	}
};

void fixCols(Mat& m) {
	for (int y = 1; y < m.h; ++y) {
		if (m.get(y, 0)) m.flipRow(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	Mat m1(h, w);
	Mat m2(h, w);
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int b;
			cin >> b;
			m1.set(y,x,b);
			m2.set(y,x,b);
		}
	}
	m2.flipRow(0);
	for (int x = 0; x < w; ++x) {
		if (m1.get(0,x)) m1.flipCol(x);
		if (m2.get(0,x)) m2.flipCol(x);
	}
	fixCols(m1);
	fixCols(m2);

	for (int i = h*w-1; i >= -1; --i) {
		if (m1.ones == 0) {
			m1.print();
			return 0;
		} else if (m2.ones == 0) {
			m2.print();
			return 0;
		} else {
			if (i == -1) {
				cout << "NO\n";
				return 0;
			}

			int x = i % w;
			int y = i / w;
			m1.flip(y, x);
			m2.flip(y, x);
			if (y == 0) {
				if (m1.get(y, x)) {
					m1.flipCol(x);
					if (x == 0) fixCols(m1);
				}
				if (m2.get(y, x)) {
					m2.flipCol(x);
					if (x == 0) fixCols(m2);
				}
			} else if (x == 0) {
				if (m1.get(y, x)) {
					m1.flipRow(y);
				}
				if (m2.get(y, x)) {
					m2.flipRow(y);
				}
			}
		}
		
	}
}
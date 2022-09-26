/*
5
2 2 2 2
3 4 3 5
*/
#include <bits/stdc++.h>

using namespace std;


struct Data {
	int x, y, u, v;
	Data(int x = 0,int y = 0,int u = 0,int v = 0) : x(x), y(y), u(u), v(v) {}
	bool full(Data b) {
		return x <= b.x && y <= b.y && b.u <= u && b.v <= v;
	}
	void read() {
		cin >> x >> y >> u >> v;
	}
} d[2];

Data a, b;

int ask(Data d) {
	assert(d.x <= d.u && d.y <= d.v);
	#ifdef F4F
	return d.full(a) + d.full(b);
	#endif
	cout << "? " << d.x << ' ' << d.y << ' ' << d.u << ' ' << d.v << endl;
	int ans;
	cin >> ans;
	return ans;
}

template<int lim> 
struct F {
	int fndx(int x,int y,int u,int v) {
		int l = x, r = u;
		while (l < r) {
			int md = (l + r + 1) >> 1;
			if (ask({md, y, u, v}) >= lim) {
				l = md;
			} else {
				r = md - 1;
			}
		}
		return l;
	}
	int fndy(int x,int y,int u,int v) {
		int l = y, r = v;
		while (l < r) {
			int md = (l + r + 1) >> 1;
			if (ask({x, md, u, v}) >= lim) {
				l = md;
			} else {
				r = md - 1;
			}
		}
		return l;
	}
	int fndu(int x,int y,int u,int v) {
		int l = x, r = u;
		while (l < r) {
			int md = (l + r) >> 1;
			if (ask({x, y, md, v}) >= lim) {
				r = md;
			} else {
				l = md + 1;
			}
		}
		return l;
	}
	int fndv(int x,int y,int u,int v) {
		int l = y, r = v;
		while (l < r) {
			int md = (l + r) >> 1;
			if (ask({x, y, u, md}) >= lim) {
				r = md;
			} else {
				l = md + 1;
			}
		}
		return l;
	}
	Data fnd(int x,int y,int u,int v) {
		return Data(fndx(x, y, u, v), fndy(x, y, u, v), fndu(x, y, u, v), fndv(x, y, u, v));
	}
};

F<1> f;
int n;

int find_row() {
	int x = f.fndx(1, 1, n, n);
	if (ask({x, 1, n, n}) == 1 && x > 1 && ask({1, 1, x - 1, n}) == 1) return x;
	return -1;
}

int find_col() {
	int y = f.fndy(1, 1, n, n);
	if (ask({1, y, n, n}) == 1 && y > 0 && ask({1, 1, n, y - 1}) == 1) return y;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	#ifdef F4F
		a.read();
		b.read();
	#endif
	int row = find_row();
	// cout << row << '\n';
	if (row > 0) {
		d[0] = f.fnd(1, 1, row - 1, n);
		d[1] = f.fnd(row, 1, n, n);
	} else {
		int col = find_col();
		assert(col > 0);
		d[0] = f.fnd(1, 1, n, col - 1);
		d[1] = f.fnd(1, col, n, n);
	}
	cout << "! ";
	for (int i = 0; i < 2; ++i) {
		cout << d[i].x << ' ' << d[i].y << ' ' << d[i].u << ' ' << d[i].v << ' ';
	} 
	cout << endl;
}
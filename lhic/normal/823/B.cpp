#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using namespace std;

#ifndef LOCAL
const int MAXN = 100003;
#else
const int MAXN = 1001;
#endif


struct Fen {
	int Size;
	vector <int> a;

	Fen() {
	}

	Fen(int size) {
		Size = size;
		a.resize(Size, 0);
		for (int i = 0; i < Size; i++) a[i] = 0;
	}

	void upd(int x, int v) {
		for (int i = x; i < Size; i = (i | (i + 1)))
			a[i] += v;
	}

	int get(int x) {
		int ans = 0;
		for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
			ans += a[i];
		return ans;
	}
};

struct Fens {
	Fen f[11];

	Fens() {
	}

	Fens(int c) {
		for (int i = 0; i < c; i++)
			f[i] = Fen((MAXN + c - 1) / c);
	}

};


Fens f[11][4];

int getsym(char c) {
	switch (c) {
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	default:
		return 3;
	}
}

void upd(int pos, int s, int cf) {
	for (int i = 1; i <= 10; i++) {
		f[i][s].f[pos % i].upd(pos / i, cf);
	}
}

void del(int pos, char sym) {
	upd(pos, getsym(sym), -1);
}

void add(int pos, char sym) {
	upd(pos, getsym(sym), 1);
}

string e;

int main() {
	ios_base::sync_with_stdio(0);
	cout.setf(ios::fixed); cout.precision(15);
#ifdef LOCAL
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 4; j++) {
			f[i][j] = Fens(i);
		}
	}

	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		add(i, s[i]);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int x;
			char c;
			cin >> x >> c;
			x--;
			del(x, s[x]);
			s[x] = c;
			add(x, s[x]);
		} else {
			int l, r;
			cin >> l >> r >> e;
			l--, r--;
			int es = e.size();
			int ans = 0;
			for (int i = 0; i < es; i++) {
				int d = getsym(e[i]);
				int lg = l + i;
				if (lg > r) continue;
				int dd = (r - (l + i));
				int md = lg % es;
				int ls = lg / es, rs = ls + dd / es;
				ans -= f[es][d].f[md].get(ls - 1) - f[es][d].f[md].get(rs);
			}
			cout << ans << "\n";
		}
	}

	return 0;
}
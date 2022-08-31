#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <complex>

typedef long long ll;
typedef long double ld;


using namespace std;

const double PI = acos(-1);

const int MAXN = (1 << 19) + 10;

int n, m, k;
int ans[MAXN];

char s[MAXN];
char t[MAXN];


struct cmplx {
	double x, y;
	cmplx operator*(cmplx a) {
		return cmplx(x * a.x - y * a.y, x * a.y + y * a.x);
	}
	cmplx operator+(cmplx a) {
		return cmplx(x + a.x, y + a.y);
	}
	cmplx operator-(cmplx a) {
		return cmplx(x - a.x, y - a.y);
	}
	cmplx operator/(double a) {
		return cmplx(x / a, y / a);
	}
	cmplx() {
		x = y = 0;
	}
	cmplx(double x, double y) : x(x), y(y) {}
};





void fft(cmplx *a, int n, int inv) {
	int rev = 0;
	int cb = 0;
	while ((1 << cb) < n)
		++cb;
	for (int i = 0; i < n; ++i) {
		if (i < rev)
			swap(a[i], a[rev]);
		for (int j = cb - 1; j >= 0; --j) {
			rev ^= (1 << j);
			if ((rev >> j) & 1)
				break;
		}
	}

	for (int bl = 1; bl < n; bl *= 2) {
		cmplx wn(cos(2 * PI / (bl * 2)), sin(2 * PI / (bl * 2)));
		if (inv)
			wn.y = -wn.y;
		for (int i = 0; i < n; i += 2 * bl) {
			cmplx w(1, 0);
			for (int j = i; j < i + bl; ++j) {
				cmplx u = a[j];
				cmplx t = w * a[j + bl];
				a[j] = u + t;
				a[j + bl] = u - t;
				w = w * wn;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; ++i)
			a[i] = a[i] / n;
	}
}

cmplx aa[MAXN];
cmplx bb[MAXN];

void calc(char c) {
	int sz = 1;
	while (sz < 2 * max(n, m))
		sz *= 2;
	for (int i = 0; i < sz; ++i)
		aa[i] = cmplx(0, 0), bb[i] = cmplx(0, 0);
	for (int i = 0; i < m; ++i)
		if (t[i] == c)
			bb[i] = cmplx(1, 0);
	int lst = -400000;
	for (int i = 0; i < n; ++i) {
		if (s[i] == c)
			lst = i;
		if (i - lst <= k)
			aa[i] = cmplx(1, 0);
	}
	lst = n + 400000;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == c)
			lst = i;
		if (lst - i <= k)
			aa[i] = cmplx(1, 0);
	}
	reverse(bb, bb + m);
	fft(aa, sz, 0);
	fft(bb, sz, 0);
	for (int i = 0; i < sz; ++i)
		aa[i] = aa[i] * bb[i];
	fft(aa, sz, 1);
	for (int i = m - 1; i < n + m; ++i)
		ans[i] += lround(aa[i].x);
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	scanf(" %s", s);
	scanf(" %s", t);
	calc('A');
	calc('T');
	calc('G');
	calc('C');
	int cc = 0;
	for (int i = m - 1; i < n + m; ++i)
		if (ans[i] == m)
			++cc;
	cout << cc << "\n";
	return 0;
}
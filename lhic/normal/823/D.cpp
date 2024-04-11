#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using namespace std;


//typedef complex<double> cmplx;
const ld PI = acos(-1.0);


struct cmplx {
	ld x, y;
	cmplx(ld X = 0, ld Y = 0) {
		x = X, y = Y;
	}
	cmplx operator+(cmplx a) {
		return cmplx(x + a.x, y + a.y);
	}
	cmplx operator-(cmplx a) {
		return cmplx(x - a.x, y - a.y);
	}
	cmplx operator*(cmplx a) {
		return cmplx(x * a.x - y * a.y, x * a.y + y * a.x);
	}
};


int rev(int x, int k) {
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans = ans * 2 + (x & 1);
		x >>= 1;
	}
	return ans;
}

void fft(cmplx *a, int k, int inv) {
	int n = (1 << k);
	for (int i = 0; i < n; ++i) {
		int x = rev(i, k);
		if (x > i)
			swap(a[i], a[x]);
	}
	for (int bl = 1; bl < n; bl *= 2) {
		ld ang = PI / bl;
		if (inv)
			ang = -ang;
		cmplx wadd(cos(ang), sin(ang));
		for (int i = 0; i < n; i += 2 * bl) {
			cmplx w = 1;
			for (int j = i; j < i + bl; ++j, w = w * wadd) {
				cmplx u = a[j];
				cmplx v = w * a[j + bl];
				a[j] = u + v;
				a[j + bl] = u - v;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; ++i)
			a[i] = cmplx(a[i].x / n, a[i].y / n);
	}
}

const int MX = (1 << 20) + 100;

int n;
char s[MX];
cmplx a[MX], b[MX];

int fl[MX];
vector<int> ans;

void solve() {
	scanf("%d", &n);
	scanf(" %s", s);
	int k = 1;
	while ((1 << k) <= 2 * n)
		++k;
	for (int i = 0; i < (1 << k); ++i)
		a[i] = b[i] = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'V') {
			a[i] = 1;
		} else if (s[i] == 'K') {
			b[i] = 1;
		}
	}
	reverse(a, a + n);
	fft(a, k, 0);
	fft(b, k, 0);
	for (int i = 0; i < (1 << k); ++i)
		a[i] = a[i] * b[i];
	fft(a, k, 1);
	fill(fl, fl + n + 1, 0);
	for (int i = 0; i < (1 << k); ++i) {
		int x = llround(a[i].x);
		if (x) {
			int g = abs(i - (n - 1));
			fl[g] = 1;
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; j += i) {
			if (fl[j]) {
				fl[i] = 1;
				break;
			}
		}
	}
	ans.clear();
	for (int i = 1; i <= n; ++i) {
		if (!fl[i])
			ans.push_back(i);
	}
	printf("%d\n", (int)ans.size());
	for (int i : ans)
		printf("%d ", i);
	printf("\n");
}


int main() {
	cout.setf(ios::fixed); cout.precision(15);
#ifdef LOCAL
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i)
		solve();
	return 0;
}
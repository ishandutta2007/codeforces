#include <bits/stdc++.h>
using namespace std;

typedef complex<double> base;
const int N = 1 << 19;
const double PI = acos(-1);

int n, x;
int a[N];
vector<long long> f, g, h;
long long res[N];
int rev[N];

void calc_rev(int n,int logn) {
	for (int i = 0;i < n;++i) {
		rev[i] = 0;
		for (int j = 0;j < logn;++j) if (i >> j & 1) {
			rev[i] |= 1 << logn - j - 1;
		}
	}
}

void fft(base a[],int n,bool invert) {
	for (int i = 0;i < n;++i) if (i < rev[i]) {
		swap(a[i], a[rev[i]]);
	}
	for (int len = 2;len <= n;len <<= 1) {
		double alpha = 2 * PI / len * (invert ? -1 : 1);
	    base wl = base(cos(alpha), sin(alpha));
	    for (int i = 0; i < n; i += len) {
	        base w = base(1);
	        for (int j = 0; j < (len >> 1); ++j) {
	            base u = a[i + j], v = a[i + j + (len >> 1)] * w;
	            a[i + j] = u + v;
				a[i + j + (len >> 1)] = u - v;
				w *= wl;
	        }
	    }
	}
	if (invert) for (int i = 0; i < n; ++i) a[i] /= n;
}

vector<long long> mult(vector<long long> a,vector<long long> b) {
	static base fa[N], fb[N], fc[N];
	int na = a.size(), nb = b.size();
	int n = 1, logn = 0;
	while (n < max(na, nb)) n <<= 1, logn++;
	n <<= 1, logn++;
	calc_rev(n, logn);
	for (int i = 0; i < n; ++i) fa[i] = fb[i] = base(0);
	for (int i = 0; i < na; ++i) fa[i] = base(a[i]);
	for (int i = 0; i < nb; ++i) fb[i] = base(b[i]);
	fft(fa, n, false); fft(fb, n, false);
	for (int i = 0;i < n;++i) fc[i] = fa[i] * fb[i];
	fft(fc, n, true);
	vector<long long> res;
	for (int i = 0;i < na + nb - 1;++i) res.push_back((long long)(fc[i].real() + 0.5));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	f.assign(n + 1, 0), g.assign(n + 1, 0);
	f[0] = g[n] = 1;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
		a[i] = a[i - 1] + (a[i] < x);
		f[a[i]]++, g[n - a[i]]++;
	}
	h = mult(f, g);
	for (int i = 0;i <= n;++i) res[0] += f[i] * (f[i] - 1) / 2;
	for (int i = 1;i <= n;++i) res[i] = h[i + n];
	for (int i = 0;i <= n;++i) cout << res[i] << ' '; cout << '\n';
}
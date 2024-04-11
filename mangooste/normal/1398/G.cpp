#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using comp = complex<double>;

const double PI = atan2(0, -1);
const int N = 202020;
const int A = 1000100;

void fft(vector<comp> &a) {
	if (a.size() == 1)
		return;

	int n = a.size();
	vector<comp> a0, a1;
	for (int i = 0; i < n; i += 2) {
		a0.push_back(a[i]);
		a1.push_back(a[i + 1]);
	}
	fft(a0), fft(a1);

	comp now(1), w(cos(2 * PI / n), sin(2 * PI / n));
	for (int i = 0; i < n / 2; i++, now *= w) {
		a[i] = a0[i] + now * a1[i];
		a[i + n / 2] = a0[i] - now * a1[i];
	}
}

vector<int> multiply(vector<int> a, vector<int> b) {
	int n = (1 << 32 - __builtin_clz(a.size() + b.size() - 2));
	while (a.size() < n)
		a.push_back(0);
	while (b.size() < n)
		b.push_back(0);

	vector<comp> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	fft(fa), fft(fb);
	for (int i = 0; i < n; i++)
		fa[i] *= fb[i];

	fft(fa);
	reverse(fa.begin() + 1, fa.end());
	for (int i = 0; i < n; i++)
		fa[i] /= n;

	vector<int> prod(n);
	for (int i = 0; i < n; i++)
		prod[i] = (int) (fa[i].real() + 0.5);
	return prod;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	vector<int> a(N, 0), b(N, 0);
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i <= n; i++) {
		int pos;
		cin >> pos;
		a[pos]++;
		b[N - 1 - pos]++;
	}
	vector<int> c = multiply(a, b);

	vector<char> can(A, 0);
	for (int i = N; i < c.size(); i++)
		if (c[i])
			can[i - N + 1] = 1;

	vector<int> dp(A, -1);
	for (int i = 1; i < A; i++)
		if (can[i])
			for (int j = 2 * (y + i); j < A; j += 2 * (y + i))
				dp[j] = max(dp[j], 2 * (y + i));

	int q;
	cin >> q;
	while (q--) {
		int L;
		cin >> L;
		cout << dp[L] << ' ';
	}
	cout << '\n';
}
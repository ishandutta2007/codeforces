#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

const int mod = 1000000007;

void add(int &a, long long b)
{
	a = (a + b) % mod;
}

vector<int> andconv(vector<int> &p, vector<int> &q)
{
	int n = p.size();
	vector<int> r(n, 0);
	if (n <= 16) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) add(r[i&j], (long long)p[i] * q[j]);
	}
	else {
		n /= 2;
		vector<int> b(p.begin(), p.begin() + n);
		vector<int> a(p.begin() + n, p.end());
		vector<int> d(q.begin(), q.begin() + n);
		vector<int> c(q.begin() + n, q.end());
		vector<int> u = andconv(a, c);
		for (int i = 0; i < n; i++) {
			a[i] += b[i]; c[i] += d[i];
			if (a[i] >= mod) a[i] -= mod;
			if (c[i] >= mod) c[i] -= mod;
		}
		vector<int> v = andconv(a, c);
		for (int i = 0; i < n; i++) {
			r[i + n] = u[i];
			r[i] = v[i] - u[i];
			if (r[i] < 0) r[i] += mod;
		}
	}
	return move(r);
}

vector<int> orconv(vector<int> &p, vector<int> &q)
{
	int n = p.size();
	vector<int> r(n, 0);
	if (n <= 16) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) add(r[i | j], (long long)p[i] * q[j]);
	}
	else {
		n /= 2;
		vector<int> b(p.begin(), p.begin() + n);
		vector<int> a(p.begin() + n, p.end());
		vector<int> d(q.begin(), q.begin() + n);
		vector<int> c(q.begin() + n, q.end());
		vector<int> u = orconv(b, d);
		for (int i = 0; i < n; i++) {
			a[i] += b[i]; c[i] += d[i];
			if (a[i] >= mod) a[i] -= mod;
			if (c[i] >= mod) c[i] -= mod;
		}
		vector<int> v = orconv(a, c);
		for (int i = 0; i < n; i++) {
			r[i + n] = v[i] - u[i];
			r[i] = u[i];
			if (r[i + n] < 0) r[i + n] += mod;
		}
	}
	return move(r);
}

vector<int> xorconv(vector<int> &p, vector<int> &q)
{
	int n = p.size();
	vector<int> r(n, 0);
	if (n <= 2) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) add(r[i ^ j], (long long)p[i] * q[j]);
	}
	else {
		n /= 2;
		vector<int> b(p.begin(), p.begin() + n);
		vector<int> a(p.begin() + n, p.end());
		vector<int> d(q.begin(), q.begin() + n);
		vector<int> c(q.begin() + n, q.end());
		vector<int> w = xorconv(a, c);
		vector<int> u = xorconv(b, d);
		for (int i = 0; i < n; i++) {
			a[i] += b[i]; c[i] += d[i];
			if (a[i] >= mod) a[i] -= mod;
			if (c[i] >= mod) c[i] -= mod;
		}
		vector<int> v = xorconv(a, c);
		for (int i = 0; i < n; i++) {
			r[i + n] = v[i] - u[i];
			if (r[i + n] < 0) r[i + n] += mod;
			r[i + n] -= w[i];
			if (r[i + n] < 0) r[i + n] += mod;
			r[i] = u[i] + w[i];
			if (r[i] >= mod) r[i] -= mod;
		}
	}
	return move(r);
}

const int sz = 1 << 17;
void make(vector<int> &p)
{
	for (int u = 2, v = 1; u <= sz; u *= 2, v *= 2) {
		for (int s = 0; s < sz; s += u) {
			for (int t = 0; t<v; t++) {
				long long x = p[s + t];
				long long y = p[s + t + v];
				p[s + t] = (x + mod - y) % mod;
				p[s + t + v] = (x + y) % mod;
			}
		}
	}
}

const long long inv2 = 500000004;
void inv(vector<int> &p)
{
	for (int u = sz, v = u / 2; v >= 1; u /= 2, v /= 2) {
		for (int s = 0; s < sz; s += u) {
			for (int t = 0; t<v; t++) {
				long long xmy = p[s + t];
				long long xpy = p[s + t + v];
				p[s + t] = (xmy + xpy) * inv2 % mod;
				p[s + t + v] = (xpy + mod - xmy) * inv2 % mod;
			}
		}
	}
}

int n,F[1001000];

int main()
{
	vector<int> a(sz);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		a[x]++;
	}

	F[1] = 1;
	for (int i = 2; i < (sz); i++) F[i] = (F[i - 1] + F[i - 2]) % mod;

	vector<int> p(sz);
	for (int i = 0; i < (sz); i++){
		for (int x = i;; x = (x - 1)&i) {
			p[i] = (p[i] + (long long)a[i - x] * a[x]) % mod;
			if (x == 0) break;
		}
	}
	vector<int> q = a;
	make(a);
	vector<int> r = a;
	for (int i = 0; i < sz; i++) r[i] = (long long)r[i] * r[i] % mod;
	inv(r);

	for (int i = 0; i < (sz); i++) {
		p[i] = (long long)p[i] * F[i] % mod;
		q[i] = (long long)q[i] * F[i] % mod;
		r[i] = (long long)r[i] * F[i] % mod;
	}

	vector<int> v = andconv(p, q);
	vector<int> u = andconv(v, r);

	int ans = 0;
	for (int i = 0; i < 17; i++) ans = (ans + u[1 << i]) % mod;
	printf("%d\n", ans);

	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}
int bin_pow(int x, int p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
int rev(int x) {
	return bin_pow(x, MOD - 2);
}

const int N = 200200;
int f[N], rf[N];

int c00, c01, c10, c11, L;

int getC(int n, int k) {
	if (n == -1)
		return (k == -1 ? 1 : 0);
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

int calcEndings(int d0, int d1, int s0, int s1) {
	return mult(getC(d0 - 1, s0 - 1), getC(d1 - 1, s1 - 1));
}

int solve(string s) {
	if ((int)s.length() < L) return 0;
	if ((int)s.length() > L) {
		s = "";
		for (int i = 0; i < L; i++)
			s.push_back('1');
	}
	int d0 = c00 + c01, d1 = c10 + c11;
	if (c10 > c01)
		d0++;
	else
		d1++;
	int s0 = c10, s1 = c01 + 1;
	int lst = 1;
	d1--;
	s1--;
	if (s1 < 0 || d1 < 0) return 0;
	int ans = 0;
	for (int i = 1; i < L; i++) {
		if (s0 < 0 || s1 < 0 || d0 < 0 || d1 < 0) return ans;
		if (s[i] == '1' && d0 > 0 && (s0 > 0 || lst == 0)) {
			ans = add(ans, calcEndings(d0, d1, s0 + (lst == 0 ? 1 : 0), s1));
		}
		int nxt = (int)(s[i] - '0');
		if (nxt == 0) {
			if (lst == 1) s0--;
			d0--;
		} else {
			if (lst == 0) s1--;
			d1--;
		}
		lst = nxt;
	}
	if (d0 == 0 && d1 == 0 && s0 == 0 && s1 == 0) ans = add(ans, 1);
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	string s, p;
	cin >> p >> s;
	cin >> c00 >> c01 >> c10 >> c11;
	L = c00 + c01 + c10 + c11 + 1;
	if (c10 > c01 + 1 || c01 > c10) {
		cout << 0 << endl;
		return 0;
	}
	if (L > (int)s.length()) {
		cout << 0 << endl;
		return 0;
	}
	int pos = (int)p.size() - 1;
	while(p[pos] == '0') {
		p[pos] = '1';
		pos--;
	}
	p[pos] = '0';
	if (p[0] == '0') p = p.substr(1, (int)p.length() - 1);
	cout << sub(solve(s), solve(p)) << endl;

	return 0;
}
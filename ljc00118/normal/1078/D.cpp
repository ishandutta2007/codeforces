#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

int st1[16][N][17], st2[16][N][17];
int a[N], lg[N];
int n;

void make_st(int id) {
	for (int j = 1; j <= 16; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			st1[id][i][j] = min(st1[id][i][j - 1], st1[id][i + (1 << (j - 1))][j - 1]);
			st2[id][i][j] = max(st2[id][i][j - 1], st2[id][i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query1(int id, int l, int r) {
	int k = lg[r - l + 1];
	return min(st1[id][l][k], st1[id][r - (1 << k) + 1][k]);
}

int query2(int id, int l, int r) {
	int k = lg[r - l + 1];
	return max(st2[id][l][k], st2[id][r - (1 << k) + 1][k]);
}

int queryl(int base, int l, int r) {
	int ans = query1(base, max(l, 1), min(r, n));
	if (l <= 0) ans = max(-n + 1, min(ans, query1(base, l + n, n) - n));
	if (r > n) ans = max(-n + 1, min(ans, query1(base, 1, r - n) + n));
	return ans;
}

int queryr(int base, int l, int r) {
	int ans = query2(base, max(l, 1), min(r, n));
	if (l <= 0) ans = min(n * 2, max(ans, query2(base, l + n, n) - n));
	if (r > n) ans = min(n * 2, max(ans, query2(base, 1, r - n) + n));
	return ans;
}

int main() {
	read(n);
	if (n == 1) {
		print(0, '\n');
		return 0;
	}
	lg[0] = -1;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		lg[i] = lg[i >> 1] + 1;
		st1[0][i][0] = i - a[i];
		st2[0][i][0] = i + a[i];
	}
	make_st(0);
	for (int base = 1; base <= 15; base++) {
		for (int i = 1; i <= n; i++) {
			int l = st1[base - 1][i][0], r = st2[base - 1][i][0];
			st1[base][i][0] = queryl(base - 1, l, r);
			st2[base][i][0] = queryr(base - 1, l, r);
		}
		make_st(base);
	}
	for (int i = 1; i <= n; i++) {
		int l = i, r = i, ans = 0;
		for (int j = 15; j >= 0; j--) {
			int L = queryl(j, l, r), R = queryr(j, l, r);
			if (R - L + 1 < n) l = L, r = R, ans |= (1 << j);
		}
		print(ans + 1, i == n ? '\n' : ' ');
	}
	return 0;
}
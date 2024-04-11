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
 
const int N = 2e5 + 5, MX = 1e6, md = 1e9 + 7;
 
inline int add(int x, int y) {
	x += y;
	if (x >= md) x -= md;
	return x;
}
 
inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += md;
	return x;
}
 
inline int mul(int x, int y) { return 1ll * x * y % md; }
 
inline int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}
 
vector <pii> que[N];
int f[N], a[N], pri[MX + 5], inv[MX + 5], fac[MX + 5], las[MX + 5], s[N], sinv[N], ans[N];
int n, q;
 
inline int lowbit(int x) { return x & -x; }
 
inline void ADD(int x, int y) {
	while (x <= n) {
		f[x] = mul(f[x], y);
		x += lowbit(x);
	}
}
 
inline int query(int x) {
	int ans = 1;
	while (x) {
		ans = mul(ans, f[x]);
		x ^= lowbit(x);
	}
	return ans;
}
 
int main() {
	// freopen("szh.in", "r", stdin);
	// freopen("szh.out", "w", stdout);
	for (int i = 2; i * i <= MX; i++) {
		if (!pri[i]) {
			for (int j = i + i; j <= MX; j += i) if (!pri[j]) pri[j] = i;
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= MX; i++) fac[i] = mul(fac[i - 1], i);
	inv[MX] = fpow(fac[MX], md - 2);
	for (int i = MX; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
	for (int i = 2; i <= MX; i++) inv[i] = mul(inv[i], fac[i - 1]);
	read(n);
	s[0] = 1;
	for (int i = 1; i <= n; i++) read(a[i]), f[i] = 1, s[i] = mul(s[i - 1], a[i]);
	read(q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		read(l); read(r);
		que[l].emplace_back(r, i);
	}
	sinv[n] = fpow(s[n], md - 2);
	for (int i = n; i >= 1; i--) sinv[i - 1] = mul(sinv[i], a[i]);
	for (int i = n; i >= 1; i--) {
		int now = a[i], laspri = -1, multi = 1;
		while (now != 1) {
			int p = (pri[now] ? pri[now] : now);
			now /= p;
			if (p == laspri) continue;
			int pos = (las[p] ? las[p] : n + 1);
			las[p] = i; laspri = p;
			multi = mul(multi, mul(p - 1, inv[p]));
			if (pos <= n) ADD(pos, mul(p, inv[p - 1]));
		}
		ADD(i, multi);
		for (int j = 0; j < (int)que[i].size(); j++) {
			ans[que[i][j].second] = mul(query(que[i][j].first), mul(s[que[i][j].first], sinv[i - 1]));
		}
	}
	for (int i = 1; i <= q; i++) print(ans[i], '\n');
	return 0;
}
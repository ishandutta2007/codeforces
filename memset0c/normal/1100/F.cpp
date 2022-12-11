// =================================
//   author: memset0
//   date: 2019.02.06 18:12:38
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 5e5 + 10, L = 20;
int n, m, a[N], ans[N];

struct func {
	int f[L];
	inline void insert(int x) {
		for (int i = L - 1; ~i; i--)
			if ((x >> i) & 1) {
				if (f[i]) x ^= f[i];
				else { f[i] = x; return; }
			}
	}
	inline int query() {
		int ans = 0;
		for (int i = L - 1; ~i; i--)
			if (!((ans >> i) & 1))
				ans ^= f[i];
		return ans;
	}
	inline func() {}
	inline func(int x) {
		memset(f, 0, sizeof(f));
		insert(x);
	}
	friend inline func merge(const func &a, const func &b) {
		static func x; x = a;
		for (int i = 0; i < L; i++) x.insert(b.f[i]);
		return x;
	}
} pre[N];

struct query {
	int l, r, id;
};
std::vector <query> q;

void solve(int l, int r, std::vector <query> vet) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	std::vector <query> vet_l, vet_r;
	pre[mid] = func(a[mid]);
	for (int i = mid - 1; i >= l; i--) pre[i] = pre[i + 1], pre[i].insert(a[i]);
	for (int i = mid + 1; i <= r; i++) pre[i] = pre[i - 1], pre[i].insert(a[i]);
	// for (int u = l; u <= r; u++)
	// 	for (int i = 0; i < L; i++)
	// 		print(pre[u].f[i], " \n"[i == L - 1]);
	// puts("");
	for (auto it : vet) {
		if (it.r < mid) vet_l.push_back(it);
		else if (it.l > mid) vet_r.push_back(it);
		else ans[it.id] = merge(pre[it.l], pre[it.r]).query();
	} solve(l, mid - 1, vet_l), solve(mid + 1, r, vet_r);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	read(m);
	for (int i = 1, l, r; i <= m; i++) read(l), read(r), q.push_back({l, r, i});
	solve(1, n, q);
	for (int i = 1; i <= m; i++) print(ans[i], '\n');
}

} signed main() { return ringo::main(), 0; }
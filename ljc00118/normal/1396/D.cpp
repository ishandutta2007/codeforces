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

const int N = 2005, md = 1e9 + 7;

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

struct node_t { int l, r, maxn, tag, sum, len; } p[N << 2];

multiset <int> pos[N], now;
vector <int> col[N];
vector <pii> po[N];
int xb[N], yb[N], x[N], y[N], c[N], r[N], las[N];
int n, k, L, xl, yl, ans;

void update(int u) {
	p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
	p[u].sum = add(p[u << 1].sum, p[u << 1 | 1].sum);
	p[u].len = p[u << 1].len + p[u << 1 | 1].len;
}

void add_tag(int u, int x) {
	p[u].maxn = p[u].tag = x;
	p[u].sum = mul(p[u].len, x);
}

void pushdown(int u) {
	if (p[u].tag) {
		add_tag(u << 1, p[u].tag);
		add_tag(u << 1 | 1, p[u].tag);
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r; p[u].tag = 0;
	if (l == r) {
		p[u].len = yb[l] - yb[l - 1];
		p[u].maxn = ::r[l];
		p[u].sum = mul(p[u].len, ::r[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	update(u);
}

void change(int u, int l, int r, int x) {
	if (l <= p[u].l && p[u].r <= r) {
		// cout << u << " " << l << " " << r << " " << x << " " << p[u].maxn << endl;
		if (p[u].maxn <= x) {
			add_tag(u, x);
			return;
		}
		if (p[u].l == p[u].r) return;
		pushdown(u);
		change(u << 1, l, r, x); change(u << 1 | 1, l, r, x);
		update(u);
		return;
	}
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1;
	if (mid >= l) change(u << 1, l, r, x);
	if (mid + 1 <= r) change(u << 1 | 1, l, r, x);
	update(u);
}

int main() {
	read(n); read(k); read(L);
	for (int i = 1; i <= n; i++) {
		read(x[i]); read(y[i]); read(c[i]); ++x[i]; ++y[i];
		xb[i] = x[i]; yb[i] = y[i];
	}
	sort(xb + 1, xb + n + 1); xl = unique(xb + 1, xb + n + 1) - xb - 1;
	sort(yb + 1, yb + n + 1); yl = unique(yb + 1, yb + n + 1) - yb - 1;
	xb[xl + 1] = yb[yl + 1] = L + 1;
	for (int i = 1; i <= n; i++) {
		x[i] = lower_bound(xb + 1, xb + xl + 1, x[i]) - xb;
		y[i] = lower_bound(yb + 1, yb + yl + 1, y[i]) - yb;
		po[x[i]].emplace_back(y[i], c[i]);
	}
	for (int i = 1; i <= xl; i++) {
		for (int j = 1; j <= yl; j++) col[j].clear();
		for (int j = i; j <= xl; j++) {
			for (auto k : po[j]) {
				col[k.first].push_back(k.second);
			}
		}
		now.clear();
		for (int j = 1; j <= k; j++) pos[j].clear(), now.insert(L + 1), las[j] = L + 1;
		for (int j = yl; j >= 1; j--) {
			for (auto k : col[j]) {
				now.erase(now.find(las[k]));
				now.insert(yb[j]);
				las[k] = yb[j];
			}
			auto it = now.end(); --it;
			r[j] = *it;
		}
		build(1, 1, yl);
		for (int j = i; j <= xl; j++) {
			for (auto k : po[j]) {
				pos[k.second].insert(k.first);
			}
		}
		for (int j = 1; j <= k; j++) pos[j].insert(0), pos[j].insert(yl + 1);
		int lasx = L + 1;
		for (int j = xl; j >= i; j--) {
			ans = add(ans, mul(xb[i] - xb[i - 1], mul(lasx - xb[j], sub(mul(L + 1, yb[yl]), p[1].sum))));
			lasx = xb[j];
			for (auto k : po[j]) {
				pos[k.second].erase(pos[k.second].find(k.first));
				auto it = pos[k.second].lower_bound(k.first);
				if (*it == k.first) continue;
				int tmp = *it; --it;
				change(1, *it + 1, k.first, yb[tmp]);
			}
		}
	}
	print(ans, '\n');
    return 0;
}
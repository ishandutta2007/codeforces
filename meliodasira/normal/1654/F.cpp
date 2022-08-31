#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int N = (1 << 18) + 5, md[3] = { 998244353, 1000000007, 998244853 };
int base[3];

struct hash_t {
	int h[3], len;
} val[20][N];

char c[N];
int pw[3][N], key[N];
int n;

bool operator==(hash_t a, hash_t b) {
	rep(i, 0, 2) {
		if (a.h[i] != b.h[i]) {
			return 0;
		}
	}
	return 1;
}

hash_t operator+(hash_t a, hash_t b) {
	hash_t ans;
	ans.len = a.len + b.len;
	rep(i, 0, 2) {
		ans.h[i] = (1ll * a.h[i] * pw[i][b.len] + b.h[i]) % md[i];
	}
	return ans;
}

bool check(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

bool chk(int dep, int l1, int l2, int x, int y) {
	return val[dep + 1][l1 | x] == val[dep + 1][l2 | y];
}

bool cmp(int dep, int l1, int l2, int x, int y) {
	if (dep == -1) return c[l1] < c[l2];
	int mid1 = l1 + (1 << dep), mid2 = l2 + (1 << dep);
	int p1, p2, X, Y;
	if ((x >> dep) & 1) {
		p1 = mid1;
		X = x ^ (1 << dep);
	} else {
		p1 = l1;
		X = x;
	}
	if ((y >> dep) & 1) {
		p2 = mid2;
		Y = y ^ (1 << dep);
	} else {
		p2 = l2;
		Y = y;
	}
	if (chk(dep - 1, p1, p2, X, Y)) {
		return cmp(dep - 1, l1 + mid1 - p1, l2 + mid2 - p2, X, Y);
	} else {
		return cmp(dep - 1, p1, p2, X, Y);
	}
}

void solve(int dep, int l, int r) {
	if (dep == -1) {
		val[dep + 1][l].h[0] = val[dep + 1][l].h[1] = val[dep + 1][l].h[2] = c[l];
		val[dep + 1][l].len = 1;
		return;
	}
	int mid = (l + r) >> 1;
	solve(dep - 1, l, mid);
	solve(dep - 1, mid + 1, r);
	rep(i, 0, r - l) {
		if ((i >> dep) & 1) {
			val[dep + 1][l ^ i] = val[dep][(mid + 1) ^ i ^ (1 << dep)] + val[dep][l ^ i ^ (1 << dep)];
		} else {
			val[dep + 1][l ^ i] = val[dep][l ^ i] + val[dep][(mid + 1) ^ i];
		}
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	rep(i, 0, 2) {
		while (1) {
			int x = rng() % 1000000 + 233;
			if (check(x)) {
				base[i] = x;
				break;
			}
		}
	}
	n = read();
	scanf("%s", c);
	rep(_, 0, 2) {
		pw[_][0] = 1;
		rep(i, 1, (1 << n)) {
			pw[_][i] = 1ll * pw[_][i - 1] * base[_] % md[_];
		}
	}
	solve(n - 1, 0, (1 << n) - 1);
	int ans = 0;
	rep(i, 1, (1 << n) - 1) {
		if (cmp(n - 1, 0, 0, i, ans)) {
			ans = i;
		}
	}
	rep(i, 0, (1 << n) - 1) putchar(c[i ^ ans]);
	putchar('\n');
}
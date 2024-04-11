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

const int md = 998244353;

const int N = 1 << 18;

char c[N + 5];
int n, ans = 1;

vector<char> dfs(int u) {
	if (u * 2 >= (1 << n)) {
		vector<char> a(1, c[u]);
		return a;
	}
	vector<char> lc = dfs(u << 1), rc = dfs(u << 1 | 1);
	if (lc != rc) ans = ans * 2 % md;
	int cando = 1;
	for (int i = 0; i < (int)lc.size(); i++) {
		if (lc[i] < rc[i]) {
			cando = 0;
			break;
		}
		if (lc[i] > rc[i]) break;
	}
	if (cando) swap(lc, rc);
	lc.push_back(c[u]);
	for (auto i: rc) lc.push_back(i);
	return lc;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	scanf("%s", c + 1);
	dfs(1);
	printf("%d\n", ans);
}
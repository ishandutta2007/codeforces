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

const int N = 1e5 + 5;

char c[N];
int f[N], nxt[N], pre[N];
int T, n, cnt;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void calc(int x) {
	for (int i = 1; i <= 26; i++) {
		if (i == x) continue;
		if (!pre[i]) {
			if (cnt != 25 && find(i) == find(x)) continue;
			nxt[x] = i;
			pre[i] = x;
			f[find(i)] = find(x);
			++cnt;
			break;
		}
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		for (int i = 1; i <= 26; i++) f[i] = i, nxt[i] = pre[i] = 0;
		cnt = 0;
		n = read();
		scanf("%s", c + 1);
		for (int i = 1; i <= n; i++) {
			int x = c[i] - 'a' + 1;
			if (!nxt[x]) calc(x);
			putchar(nxt[x] + 'a' - 1);
		}
		putchar('\n');
	}
}
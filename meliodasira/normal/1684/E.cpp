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

map<int, int> cnt;
int a[N], seq[N];
int T, n, k, len;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		k = read();
		cnt.clear();
		for (int i = 1; i <= n; i++) a[i] = read(), ++cnt[a[i]];
		int now = 0, can = -1;
		for (int i = 0; i <= n; i++) {
			if (!cnt.count(i)) {
				if (now == k) break;
				++now;
			}
			can = i;
		}
		len = 0;
		for (auto i: cnt) {
			if (i.first > can) {
				seq[++len] = i.second;
			}
		}
		sort(seq + 1, seq + len + 1);
		int ans = len, sum = 0;
		for (int i = 1; i <= len; i++) {
			sum += seq[i];
			if (sum <= now) --ans;
		}
		printf("%d\n", ans);
	}
}
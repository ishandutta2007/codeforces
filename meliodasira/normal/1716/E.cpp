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

const int N = 18;

long long lmx[1 << N], rmx[1 << N], sum[1 << N], ans[1 << N];
int a[1 << N];
int n, q, tag;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	rep(i, 0, (1 << n) - 1) a[i] = read(), lmx[i] = rmx[i] = ans[i] = max(0, a[i]), sum[i] = a[i];
	for (int len = 1; len < (1 << n); len <<= 1) {
		for (int i = 0; i < (1 << n); i += (len << 1)) {
			for (int j = 0; j < len; j++) {
				long long lmx0 = max(lmx[i + j], sum[i + j] + lmx[i + j + len]), rmx0 = max(rmx[i + j + len], sum[i + j + len] + rmx[i + j]), sum0 = sum[i + j] + sum[i + j + len], ans0 = max(max(ans[i + j], ans[i + j + len]), rmx[i + j] + lmx[i + j + len]);
				long long lmx1 = max(lmx[i + j + len], sum[i + j + len] + lmx[i + j]), rmx1 = max(rmx[i + j], sum[i + j] + rmx[i + j + len]), sum1 = sum[i + j] + sum[i + j + len], ans1 = max(max(ans[i + j], ans[i + j + len]), rmx[i + j + len] + lmx[i + j]);
				lmx[i + j] = lmx0;
				rmx[i + j] = rmx0;
				sum[i + j] = sum0;
				ans[i + j] = ans0;
				lmx[i + j + len] = lmx1;
				rmx[i + j + len] = rmx1;
				sum[i + j + len] = sum1;
				ans[i + j + len] = ans1;
			}
		}
	}
	q = read();
	while (q--) {
		int k = read();
		tag ^= (1 << k);
		printf("%lld\n", ans[tag]);
	}
}
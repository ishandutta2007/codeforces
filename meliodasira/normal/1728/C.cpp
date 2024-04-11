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

const int N = 2e5 + 5;

priority_queue<int> A, B;
int a[N], b[N];
int T, n;

int calc(int x) {
	int ans = 0;
	while (x) {
		++ans;
		x /= 10;
	}
	return ans;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read(), A.push(a[i]);
		for (int i = 1; i <= n; i++) b[i] = read(), B.push(b[i]);
		int ans = 0;
		for (int _ = 1; _ <= n; _++) {
			int x = A.top(), y = B.top();
			while (x != y) {
				++ans;
				if (x > y) {
					A.pop();
					A.push(calc(x));
					x = A.top();
				} else {
					B.pop();
					B.push(calc(y));
					y = B.top();
				}
			}
			A.pop();
			B.pop();
		}
		printf("%d\n", ans);
	}
}
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

priority_queue<long long> Q;
int a[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		long long sum = 0;
		n = read();
		rep(i, 1, n) a[i] = read(), sum += a[i];
		sort(a + 1, a + n + 1);
		while (!Q.empty()) Q.pop();
		Q.push(sum);
		int ans = 1;
		for (int i = n; i >= 1; i--) {
			long long x = Q.top();
			Q.pop();
			if (x == a[i]) continue;
			if (x < a[i]) {
				ans = 0;
				break;
			}
			++i;
			Q.push(x / 2);
			Q.push((x + 1) / 2);
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
}
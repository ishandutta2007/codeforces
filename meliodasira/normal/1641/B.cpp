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

const int N = 505;

int a[N], b[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		rep(i, 1, n) a[i] = read(), b[i] = a[i];
		sort(b + 1, b + n + 1);
		if (n % 2 == 1) {
			printf("-1\n");
			continue;
		}
		int cando = 1;
		for (int i = 1; i <= n; i += 2) {
			if (b[i] != b[i + 1]) {
				cando = 0;
				break;
			}
		}
		if (!cando) {
			printf("-1\n");
			continue;
		}
		int m = n, sum = 0;
		vector<pii> ans1;
		vector<int> ans2;
		while (m) {
			int pos = 0;
			for (int i = 2; i <= m; i++) {
				if (a[i] == a[1]) {
					pos = i;
					break;
				}
			}
			assert(pos);
			for (int i = 2; i <= pos - 1; i++) {
				ans1.emplace_back(sum + pos + i - 2, a[i]);
			}
			for (int i = 1; i <= pos - 2; i++) b[i] = a[pos - i];
			for (int i = pos + 1; i <= m; i++) b[i - 2] = a[i];
			memcpy(a, b, sizeof(a));
			m -= 2;
			sum += (pos - 1) * 2;
			ans2.push_back((pos - 1) * 2);
		}
		printf("%d\n", (int)ans1.size());
		for (auto i: ans1) printf("%d %d\n", i.first, i.second);
		printf("%d\n", (int)ans2.size());
		for (auto i: ans2) printf("%d ", i);
		printf("\n");
	}
}
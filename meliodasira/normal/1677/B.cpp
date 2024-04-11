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

const int N = 1e6 + 5;

char c[N];
int s1[N], s2[N], s3[N];
int T, n, m;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		scanf("%s", c + 1);
		for (int i = 1; i <= n * m; i++) s1[i] = s1[i - 1] + (c[i] - '0');
		for (int i = 1; i <= n * m; i++) {
			int l = max(1, i - m + 1);
			s2[i] = (s1[i] != s1[l - 1]);
			s3[i] = (c[i] - '0');
		}
		for (int i = 1; i <= n * m; i++) {
			if (i >= m) {
				s2[i] += s2[i - m];
				s3[i] |= s3[i - m];
			}
		}
		for (int i = 1; i <= n * m; i++) s3[i] += s3[i - 1];
		for (int i = 1; i <= n * m; i++) {
			int l = max(1, i - m + 1);
			printf("%d%c", s2[i] + s3[i] - s3[l - 1], i == n * m ? '\n' : ' ');
		}
	}
}
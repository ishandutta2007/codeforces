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

mt19937 rng(time(0));

const int N = 55;

int a[N][N], id[N];
int T, n, m;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = 0;
		while (m < n) {
			for (int i = 1; i <= n; i++) id[i] = i;
			shuffle(id + 1, id + n + 1, rng);
			int cando = 1;
			for (int i = 3; i <= n; i++) {
				if (id[i - 2] + id[i - 1] == id[i]) {
					cando = 0;
					break;
				}
			}
			for (int i = 1; i <= m; i++) {
				int same = 1;
				for (int j = 1; j <= n; j++) {
					if (a[i][j] != id[j]) {
						same = 0;
						break;
					}
				}
				if (same) {
					cando = 0;
					break;
				}
			}
			if (cando) {
				++m;
				for (int i = 1; i <= n; i++) {
					a[m][i] = id[i];
					printf("%d%c", id[i], i == n ? '\n' : ' ');
				}
			}
		}
	}
}
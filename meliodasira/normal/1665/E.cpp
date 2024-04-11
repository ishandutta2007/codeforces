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

int id[30][N], a[N];
int T, n, q;

int nbit;
bool cmp(int i, int j) {
	if ((a[i] >> nbit) != (a[j] >> nbit)) return a[i] < a[j];
	return i < j;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 0, 29) {
			nbit = i;
			rep(j, 1, n) id[i][j] = j;
			sort(id[i] + 1, id[i] + n + 1, cmp);
		}
		q = read();
		while (q--) {
			int l = read(), r = read();
			vector<int> now;
			int ans = 0;
			for (int i = 29; i >= 0; i--) {
				int L = 1, R = n, pos = n + 1, cnt = 0;
				while (L <= R) {
					int mid = (L + R) >> 1;
					int x = (a[id[i][mid]] >> i);
					if (x > (ans >> i) || (x == (ans >> i) && l <= id[i][mid]))
						pos = mid, R = mid - 1;
					else
						L = mid + 1;
				}
				if (pos <= n && (a[id[i][pos]] >> i) == (ans >> i) && id[i][pos] <= r) ++cnt;
				if (pos + 1 <= n && (a[id[i][pos + 1]] >> i) == (ans >> i) && id[i][pos + 1] <= r) ++cnt;
				for (auto j: now) {
					if (!(j & (1 << i))) {
						++cnt;
					}
				}
				if (cnt >= 2) {
					vector<int> nnow;
					for (auto j: now) {
						if (!(j & (1 << i))) {
							nnow.push_back(j);
						}
					}
					now = nnow;
				} else {
					if (pos <= n && (a[id[i][pos]] >> i) == (ans >> i) && id[i][pos] <= r) now.push_back(a[id[i][pos]]);
					ans |= (1 << i);
				}
			}
			printf("%d\n", ans);
		}
	}
}
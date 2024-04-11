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

const int N = 5e5 + 5;

set<pair<int, int> > all;
vector<pair<int, int> > vec[N];
int a[N], l[N], r[N], ans[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		all.clear();
		for (int i = 1; i <= n; i++) vec[i].clear();
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			int L = 1, R = n, res = n + 1;
			while (L <= R) {
				int mid = (L + R) >> 1;
				if (i / mid < a[i])
					res = mid, R = mid - 1;
				else
					L = mid + 1;
			}
			--res;
			r[i] = res;
			L = 1;
			R = n;
			res = 0;
			while (L <= R) {
				int mid = (L + R) >> 1;
				if (i / mid > a[i])
					res = mid, L = mid + 1;
				else
					R = mid - 1;
			}
			++res;
			l[i] = res;
			vec[l[i]].emplace_back(r[i], i);
		}
		for (int i = 1; i <= n; i++) {
			for (auto j: vec[i]) {
				all.insert(make_pair(j.first, j.second));
			}
			ans[all.begin()->second] = i;
			all.erase(all.begin());
		}
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
}
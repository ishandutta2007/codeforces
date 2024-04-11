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

const int N = 3e5 + 5;
const long double eps = 1e-10;

multiset<pair<long double, long double> > all;
int p[N], q[N];
int T, n;
long double a, b;

signed main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		all.clear();
		n = read();
		a = read();
		b = read();
		rep(i, 1, n) p[i] = read();
		rep(i, 1, n) q[i] = read();
		long double free = a;
		rep(i, 1, n) {
			long double now = min((long double)p[i], b / q[i] * p[i]);
			long double tmp = (long double)q[i] / p[i];
			a += now;
			b -= now * tmp;
			while (all.size() && now + eps < p[i]) {
				auto it = --all.end();
				if (it->first > tmp) {
					long double can = min(p[i] - now, it->second * it->first / tmp);
					long double dif = can * tmp / it->first;
					now += can;
					a += (can - dif);
					long double v1 = it->first, v2 = it->second - dif;
					all.erase(it);
					if (v2 > eps) {
						all.insert(make_pair(v1, v2));
					}
				} else {
					break;
				}
			}
			free += now;
			long double can_back = now + p[i];
			while (free + eps < can_back && all.size()) {
				auto it = all.begin();
				if (it->first > tmp) break;
				long double x = it->first, y = it->second;
				long double v = min(can_back - free, it->second);
				free += v;
				y -= v;
				all.erase(it);
				if (y > eps) all.insert(make_pair(x, y));
			}
			long double tem = min(free, can_back);
			free -= tem;
			if (tem > eps) all.insert(make_pair(tmp, tem));
			printf("%.10lf\n", (double)a);
		}
	}
}
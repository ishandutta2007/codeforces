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

const int N = (1 << 17) + 5;

int T, l, r;

int solve(vector<int> a, int l, int r, int b) {
	if (b == -1) return 0;
	int cnt[2] = { 0, 0 }, ncnt[2] = { 0, 0 };
	vector<int> vec[2];
	for (int i = l; i <= r; i++) ++cnt[(i >> b) & 1];
	for (auto i: a) ++ncnt[(i >> b) & 1], vec[(i >> b) & 1].push_back(i);
	if (cnt[0] == cnt[1]) return solve(vec[0], l, (l + r) / 2, b - 1);
	int ans = 0;
	if (cnt[0] != ncnt[0]) swap(vec[0], vec[1]), ans = (1 << b);
	return solve(vec[0], l, l + cnt[0] - 1, b - 1) | solve(vec[1], r - cnt[1] + 1, r, b - 1) | ans;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		l = read();
		r = read();
		vector<int> a(r - l + 1);
		for (int i = 0; i <= r - l; i++) a[i] = read();
		printf("%d\n", solve(a, l, r, 16));
	}
}
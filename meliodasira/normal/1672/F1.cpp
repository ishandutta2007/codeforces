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

vector<int> vec[N];
int a[N], cnt[N], ans[N];
int T, n;

bool cmp(int i, int j) {
	i = a[i];
	j = a[j];
	if (cnt[i] != cnt[j]) return cnt[i] > cnt[j];
	return i < j;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) cnt[i] = 0, vec[i].clear();
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			++cnt[a[i]];
			vec[cnt[a[i]]].push_back(i);
			ans[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			if (vec[i].size() <= 1) continue;
			sort(vec[i].begin(), vec[i].end(), cmp);
			for (int j = 1; j < (int)vec[i].size(); j++) {
				ans[vec[i][j]] = vec[i][j - 1];
			}
			ans[vec[i][0]] = vec[i].back();
		}
		for (int i = 1; i <= n; i++) printf("%d%c", a[ans[i]], i == n ? '\n' : ' ');
	}
}
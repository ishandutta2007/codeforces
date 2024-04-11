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

vector<pii> ans;
bitset<257> dp[N];
char c[N];
int seq[N], l[N], r[N], opt[N], used[N];
int T, n, len, m;

void solve(int i, int x) {
	if (!i) return;
	int val = 0;
	for (int j = 0; j <= 7; j++) {
		if (c[i - j] == '1') val += (1 << j);
		if (dp[i - j - 1][x - val]) {
			solve(i - j - 1, x - val);
			ans.emplace_back(i - j, i);
			break;
		}
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		ans.clear();
		scanf("%s", c + 1);
		n = strlen(c + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += (c[i] - '0');
		if (cnt == 0) {
			printf("-1\n");
			continue;
		}
		if (cnt <= 16) {
			dp[0][0] = 1;
			for (int i = 1; i <= n; i++) {
				dp[i].reset();
				int val = 0;
				for (int j = 0; j <= 7; j++) {
					if (i - j == 0) break;
					if (c[i - j] == '1') val += (1 << j);
					if (val <= 256) dp[i] |= (dp[i - j - 1] << val);
				}
			}
			int cando = 0;
			for (int i = 0; i <= 8; i++) {
				if (dp[n][1 << i]) {
					cando = 1;
					solve(n, 1 << i);
					break;
				}
			}
			assert(cando);
		} else {
			for (int i = 1; i <= n; i++) used[i] = 0;
			int need = 1;
			while (need < cnt) need <<= 1;
			need -= cnt;
			// fprintf(stderr, "need = %d\n", need);
			len = 0;
			for (int i = 1; i <= n; i++) {
				if (c[i] == '1') {
					seq[++len] = i;
				}
			}
			m = 0;
			for (int i = seq[5]; i <= n - 2;) {
				if (c[i] == '0') {
					++i;
					continue;
				}
				++m;
				l[m] = i;
				r[m] = i + 2;
				opt[m] = (c[i + 1] - '0') * 2 + (c[i + 2] - '0');
				i += 3;
			}
			for (int i = 1; i <= m; i++) {
				// fprintf(stderr, "opt[%d] = %d\n", i, opt[i]);
				if (opt[i] <= 1) {
					if (need >= 3) {
						for (int j = l[i]; j <= r[i]; j++) used[j] = 1;
						ans.emplace_back(l[i], r[i]);
						need -= 3;
					}
				} else {
					if (need >= 4) {
						for (int j = l[i]; j <= r[i]; j++) used[j] = 1;
						ans.emplace_back(l[i], r[i]);
						need -= 4;
					} else if (need >= 1) {
						for (int j = l[i] + 1; j <= r[i]; j++) used[j] = 1;
						ans.emplace_back(l[i] + 1, r[i]);
						need -= 1;
					}
				}
			}
			if (need >= 1) {
				used[seq[1]] = used[seq[1] + 1] = 1;
				ans.emplace_back(seq[1], seq[1] + 1);
			}
			if (need >= 2) {
				used[seq[3]] = used[seq[3] + 1] = 1;
				ans.emplace_back(seq[3], seq[3] + 1);
			}
			for (int i = 1; i <= n; i++) {
				if (!used[i]) {
					ans.emplace_back(i, i);
				}
			}
			sort(ans.begin(), ans.end());
		}
		printf("%d\n", (int)ans.size());
		for (auto i: ans) printf("%d %d\n", i.first, i.second);
	}
}
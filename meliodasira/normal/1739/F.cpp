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

map<int, char> val;
char c[2005];
int trie[4005][12], fail[4005], w[4005], id[12];
int dp[1 << 12][4005], p1[1 << 12][4005], p2[1 << 12][4005];
int n, m, tot, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	rep(i, 1, n) {
		m = read();
		scanf("%s", c + 1);
		int len = strlen(c + 1), mn, mx, now;
		mn = mx = now = 15;
		val.clear();
		memset(id, 0, sizeof(id));
		val[15] = c[1];
		id[c[1] - 'a'] = 15;
		int ok = 1;
		for (int i = 2; i <= len; i++) {
			if (now - 1 >= mn && val[now - 1] == c[i]) {
				--now;
			} else if (now + 1 <= mx && val[now + 1] == c[i]) {
				++now;
			} else {
				if (id[c[i] - 'a']) {
					ok = 0;
					break;
				}
				if (now == mn) {
					--now;
					--mn;
					val[now] = c[i];
					id[c[i] - 'a'] = now;
				} else if (now == mx) {
					++now;
					++mx;
					val[now] = c[i];
					id[c[i] - 'a'] = now;
				} else {
					ok = 0;
					break;
				}
			}
		}
		if (ok) {
			int now = 0;
			for (int i = mn; i <= mx; i++) {
				int x = val[i] - 'a';
				if (!trie[now][x]) trie[now][x] = ++tot;
				now = trie[now][x];
			}
			w[now] += m;
			now = 0;
			for (int i = mx; i >= mn; i--) {
				int x = val[i] - 'a';
				if (!trie[now][x]) trie[now][x] = ++tot;
				now = trie[now][x];
			}
			w[now] += m;
		}
	}
	queue<int> q;
	for (int i = 0; i < 12; i++) {
		if (trie[0][i]) {
			q.push(trie[0][i]);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		w[u] += w[fail[u]];
		for (int i = 0; i < 12; i++) {
			if (trie[u][i]) {
				int v = trie[u][i];
				fail[v] = trie[fail[u]][i];
				q.push(v);
			} else {
				trie[u][i] = trie[fail[u]][i];
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < (1 << 12); i++) {
		for (int j = 0; j <= tot; j++) {
			if (dp[i][j] == -1) continue;
			for (int k = 0; k < 12; k++) {
				if ((i >> k) & 1) continue;
				int v = trie[j][k];
				if (dp[i | (1 << k)][v] < dp[i][j] + w[v]) {
					dp[i | (1 << k)][v] = dp[i][j] + w[v];
					p1[i | (1 << k)][v] = k;
					p2[i | (1 << k)][v] = j;
				}
			}
		}
	}
	for (int i = 1; i <= tot; i++) {
		if (dp[(1 << 12) - 1][i] > dp[(1 << 12) - 1][ans]) {
			ans = i;
		}
	}
	int x = (1 << 12) - 1, y = ans;
	vector<int> ret;
	for (int i = 1; i <= 12; i++) {
		int gx = p1[x][y], gy = p2[x][y];
		ret.push_back(gx);
		x ^= (1 << gx);
		y = gy;
	}
	for (int i = 11; i >= 0; i--) putchar(ret[i] + 'a');
	putchar('\n');
}
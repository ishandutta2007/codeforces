#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 5100;
const int MAXQ = 30100;
const ll P = 10000019;
const ll MOD = 1000000007;

vector<int> go[MAXQ * 4];
ll ans[MAXQ];
int cs[MAXQ + MAXN];
int w[MAXQ + MAXN];
int dp[20][1010];
int t[MAXQ];
int n, k;

void add(int v, int tl, int tr, int l, int r, int x) {
	if (tr <= l || r <= tl)
		return;
	if (l <= tl && tr <= r) {
		go[v].push_back(x);
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, x);
	add(v * 2 + 2, m, tr, l, r, x);
}

void dfs(int v, int tl, int tr, int h) {
	for (int i = 0; i < (int)go[v].size(); ++i) {
		int cc = cs[go[v][i]];
		int ww = w[go[v][i]];
		for (int i = k; i >= ww; --i)
			if (dp[h][i] < dp[h][i - ww] + cc)
				dp[h][i] = dp[h][i - ww] + cc;
	}
	if (tl + 1 == tr) {
		if (t[tl] == 3) {
			ans[tl] = 0;
			for (int i = k; i >= 1; --i)
				ans[tl] = (ans[tl] * P + dp[h][i]) % MOD;
		}
		return;
	}
	int m = (tl + tr) >> 1;
	memcpy(dp[h + 1], dp[h], sizeof(dp[h]));
	dfs(v * 2 + 1, tl, m, h + 1);
	memcpy(dp[h + 1], dp[h], sizeof(dp[h]));
	dfs(v * 2 + 2, m, tr, h + 1);
}

int l[MAXN + MAXQ];
int r[MAXN + MAXQ];


int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", cs + i, w + i);
	}
	int q;
	scanf("%d", &q);
	int cnt = n;
	for (int i = 0; i < q; ++i) {
		scanf("%d", t + i);
		if (t[i] == 1) {
			scanf("%d%d", cs + cnt, w + cnt);
			l[cnt] = i;
			++cnt;
		}
		else if (t[i] == 2) {
			int x;
			scanf("%d", &x);
			--x;
			r[x] = i + 1;
		}
	}
	for (int i = 0; i < cnt; ++i)
		if (r[i] == 0)
			r[i] = q;
	for (int i = 0; i < cnt; ++i)
		add(0, 0, q, l[i], r[i], i);
	dfs(0, 0, q, 0);
	for (int i = 0; i < q; ++i)
		if (t[i] == 3)
			printf("%lld\n", ans[i]);
	return 0;
}
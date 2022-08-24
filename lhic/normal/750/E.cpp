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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 210000;
const int INF = MAXN * 2;

int cur[5];
int cur2[5];
int rmq[MAXN * 4][5][5];
char s[MAXN];

void merge(int a[5][5], int b[5][5], int c[5][5]) {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			c[i][j] = INF;
	for (int i = 0; i < 5; ++i)
		for (int j = i; j < 5; ++j) {
			for (int k = i; k <= j; ++k)
				c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
		}
}

void merge2(int a[5][5]) {
	for (int i = 0; i < 5; ++i)
		cur2[i] = INF;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j <= i; ++j)
			cur2[i] = min(cur2[i], cur[j] + a[j][i]);
	}
	for (int i = 0; i < 5; ++i)
		cur[i] = cur2[i];
}

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				rmq[v][i][j] = INF;
		switch (s[tl]) {
			case '2':
				rmq[v][0][0] = 1;
				rmq[v][0][1] = 0;
				rmq[v][1][1] = 0;
				rmq[v][2][2] = 0;
				rmq[v][3][3] = 0;
				rmq[v][4][4] = 0;
				break;
			case '0':
				rmq[v][0][0] = 0;
				rmq[v][1][1] = 1;
				rmq[v][1][2] = 0;
				rmq[v][2][2] = 0;
				rmq[v][3][3] = 0;
				rmq[v][4][4] = 0;
				break;
			case '1':
				rmq[v][0][0] = 0;
				rmq[v][1][1] = 0;
				rmq[v][2][2] = 1;
				rmq[v][2][3] = 0;
				rmq[v][3][3] = 0;
				rmq[v][4][4] = 0;
				break;
			case '7':
				rmq[v][0][0] = 0;
				rmq[v][1][1] = 0;
				rmq[v][2][2] = 0;
				rmq[v][3][3] = 1;
				rmq[v][3][4] = 0;
				rmq[v][4][4] = 0;
				break;
			case '6':
				rmq[v][0][0] = 0;
				rmq[v][1][1] = 0;
				rmq[v][2][2] = 0;
				rmq[v][3][3] = 1;
				rmq[v][4][4] = 1;
				break;
			default:
				rmq[v][0][0] = 0;
				rmq[v][1][1] = 0;
				rmq[v][2][2] = 0;
				rmq[v][3][3] = 0;
				rmq[v][4][4] = 0;
		}
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	merge(rmq[v * 2 + 1], rmq[v * 2 + 2], rmq[v]);
}

void get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		merge2(rmq[v]);
		return;
	}
	int m = (tl + tr) >> 1;
	get(v * 2 + 1, tl, m, l, r);
	get(v * 2 + 2, m, tr, l, r);
}

int dp[MAXN][5];

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	scanf(" %s", s);
	for (int i = 0; i < 4; ++i)
		dp[0][i] = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j)
			dp[i + 1][j] = dp[i][j];
		if (s[i] == '2') {
			dp[i + 1][0] = i;
		}
		else if (s[i] == '0') {
			dp[i + 1][1] = dp[i][0];
		}
		else if (s[i] == '1') {
			dp[i + 1][2] = dp[i][1];
		}
		else if (s[i] == '7') {
			dp[i + 1][3] = dp[i][2];
		}
	}
	build(0, 0, n);
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		if (dp[r][3] < l) {
			printf("-1\n");
			continue;
		}
		for (int i = 0; i < 5; ++i)
			cur[i] = 0;
		get(0, 0, n, l, r);
		printf("%d\n", cur[4]);
	}
	return 0;
}
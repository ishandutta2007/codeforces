#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)

const int N = 20005;
const int STEPS = 100;

int dp[N];
int total;

int saved[2 * N / STEPS + 5][N];

int buf[STEPS + 5][N];

int valueX[N], valueY[N];

int n, m;

int p;

int f(int a, int b) {
	a = valueX[n - a] + valueY[m - b];
	return a >= p ? a - p : a;
}

void saveDp() {
	memcpy(saved[(total - 2) / STEPS], dp, sizeof(dp));
}

void restoreDp(int tot) {
	total = tot * STEPS + 2;
	memcpy(dp, saved[tot], sizeof(dp));
}

void oneForward() {
	++total;

	for (int i = min(n, total - 1); i >= 1 && i >= total - m; --i) {
		int cur = -1;
		if (i > 1 && dp[i - 1] != -1)
			cur = max(cur, dp[i - 1] + f(i - 1, total - i));
		if (total - i > 1 && dp[i] != -1)
			cur = max(cur, dp[i] + f(i, total - i - 1));
		dp[i] = cur;
	}
}

void initDp() {
	total = 2;
	memset(dp, -1, sizeof(dp));
	dp[1] = f(n, m);
}

void regenerateDp(int tot) {
	restoreDp(tot);
	for (int i = 0; i < STEPS && total <= n + m; ++i) {
		memcpy(buf[i], dp, sizeof(dp));
		if (i + 1 < STEPS && total < n + m)
			oneForward();
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &valueX[i]);
		valueX[i] %= p;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &valueY[i]);
		valueY[i] %= p;
	}
	initDp();
	saveDp();
	while (total < n + m) {
		oneForward();
		if (total % STEPS == 2)
			saveDp();
	}
	int a = n, b = m;
	printf("%d\n", dp[n]);
	regenerateDp((a + b - 3) / STEPS);
	while (a + b > 2) {
		if ((a + b) % STEPS == 2)
			regenerateDp((a + b - 3) / STEPS);
		int cur = (a + b - 3) % STEPS;
		int valA = -1, valB = -1;
		if (a > 1)
			valA = buf[cur][a - 1] + f(a - 1, b);
		if (b > 1)
			valB = buf[cur][a] + f(a, b - 1);
		if (valA > valB) {
			putchar('C');
			--a;
		} else {
			putchar('S');
			--b;
		}
	}
	putchar('\n');
}
/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;
#define MAXN 200005
int n, m;
int p[MAXN], A[MAXN], B[MAXN];
bool vis[MAXN];

struct stx {
	int x;
	bool operator < (const stx &a) const {
		return p[x] > p[a.x];
	}
};

priority_queue <stx> q[3];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	for (int i = 1; i <= n; i++) scanf("%d", A + i);
	for (int i = 1; i <= n; i++) scanf("%d", B + i);
	for (int i = 1; i <= n; i++) {
		stx now; now.x = i;
		q[A[i]].push(now);
		q[B[i]].push(now);
	}
	scanf("%d", &m);
	for (int i = 1, x; i <= m; i++) {
		scanf("%d", &x);
		int nowans = -1;
		while (!q[x].empty() && vis[q[x].top().x]) q[x].pop();
		if (!q[x].empty()) {
			vis[q[x].top().x] = 1;
			nowans = p[q[x].top().x];
		}
		printf("%d ", nowans);
	}

	return 0;
}
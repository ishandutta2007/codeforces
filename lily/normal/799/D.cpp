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

#define MAXN 100319

int ans = 0x3f3f3f3f;

int A[MAXN], n;
int ga, gb;

void dfs(int dep, int a, int b) {
	if (dep + ans <= n) return;
	if (a >= ga && b >= gb) {
		ans = n - dep;
		return;
	}
	if (!dep) return;
	if (A[dep] == 2) {
		while (dep && a < ga) a <<= 1, dep--;
		while (dep && b < gb) b <<= 1, dep--;
		if (a >= ga && b >= gb) ans = min(ans, n - dep);
		return;
	}
	if (a < ga) {
		int to = (int)min((LL)ga, (LL)a * A[dep]);
		dfs(dep - 1, to, b);
	}
	if (b < gb) {
		int to = (int)min((LL)gb, (LL)b * A[dep]);
		dfs(dep - 1, a, to);
	}
}

void check(int a, int b) {
	if (a > b) swap(a, b);
	if (!a) {
		LL tot = 1; int cnt = 0;
		while (cnt <= n && tot <= b) tot *= A[n - (cnt++)];
		ans = min(ans, cnt);
	}
	else {
		ga = a, gb = b;
		dfs(n, 1, 1);
	}
}

int a, b, h, w;

int main() {
	cin >> a >> b >> h >> w >> n;
	for (int i = 1; i <= n; i++) scanf("%d", A + i);
	sort(A + 1, A + n + 1);
	check((a + h - 1) / h, (b + w - 1) / w);
	check((a + w - 1) / w, (b + h - 1) / h);
	if (ans > n) ans = -1;
	printf("%d\n", ans);
	return 0;
}
/* Never Say Die */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double D;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

int n; LL K, ans = 0;
int a[105];

bool chk(LL x) {
	LL ret = 0;
	for (int i = 1; i <= n; i++) {
		if ((ret += ((a[i] + x - 1)/ x) * x - a[i]) > K) return 0;
	}
	ans = max(ans, x);
	return 1;
}

void solve(int x) {
	for (int i = 1, j; i <= x; i = j + 1) {
		j = x / (x / i);
		if (ans >= j) continue;
		int l = max((int)ans, i), r = j;
		if (!chk(l)) continue;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (chk(mid)) l = mid;
			else r = mid - 1;
		}
	}
	LL l = x, r = LL(1e9 + 1e11 + 1e2);
	while (l < r) {
		LL mid = (l + r + 1) >> 1;
		if (chk(mid)) l = mid;
		else r = mid - 1;
	}
}

int main() {
	read(n); read(K);
	for (int i = 1; i <= n; i++) read(a[i]);

	for (int i = 1; i <= n; i++) {
		solve(a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
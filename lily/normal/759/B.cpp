/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
int _c = 0;
template <class _T> inline void read(_T &_a) {
	_a = 0; bool _f = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}
typedef long long LL;
typedef long double LD;
#define MAXN 100005

int n;
int t[MAXN], dp[MAXN];

int main() {
	read(n); dp[0] = 0;
	int d = 1, ni = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", t + i);
		while (t[i] - t[d] >= 1440) d++;
		while (t[i] - t[ni] >= 90) ni++;
		dp[i] = min(min(dp[d - 1] + 120, dp[ni - 1] + 50), dp[i - 1] + 20);
		printf("%d\n", dp[i] - dp[i - 1]);
	}
	return 0;
}
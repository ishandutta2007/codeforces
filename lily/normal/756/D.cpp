/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <set>
using namespace std;
int _c = 0;
template <class _T> inline void read(_T &_a) {
	_a = 0; bool _f = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}
typedef unsigned long long LL;
typedef long double LD;
#define MAXN 5005
#define MOD 1000000007
int C[MAXN][MAXN];


int n;
int pr[MAXN], last[26];
LL dp[2][MAXN];

void init() {
	C[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			if ((C[i][j] = C[i - 1][j - 1] + C[i - 1][j]) >= MOD) C[i][j] -= MOD;
		}
	}
}

char q[MAXN];

LL ans = 0, s[MAXN];

int main() {
	read(n);
	init();
	scanf("%s", q + 1);
	for (int i = 1; i <= n; i++) q[i] -= 'a';
	int ll = int(unique(q + 1, q + n + 1) - q - 1);
	LL tot = 0;
	for (int i = 1; i <= ll; i++) {
		if (!last[q[i]]) dp[1][i] = 1, tot++;
		pr[i] = last[q[i]];
		last[q[i]] = i;
	}
	ans = tot;
	for (int i = 2; i <= ll; i++) {
		int now = i & 1, pre = now ^ 1; 
		for (int j = 1; j <= ll; j++) s[j] = s[j - 1] + dp[pre][j];
		tot = 0;
		for (int j = 1; j <= ll; j++) {
			dp[now][j] = (s[j - 1] - s[pr[j]]) % MOD;
			tot = (tot + dp[now][j]) % MOD;
		}
		ans = (ans + C[n - 1][i - 1] * tot) % MOD;
	}
	cout << ans << endl;
	return 0;
}
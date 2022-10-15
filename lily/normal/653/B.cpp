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

int n, Q;
int dp[10][10];
vector <int> to[6];

char tmp[10], ff[10];

int main() {
	read(n); read(Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%s%s", tmp, ff);
		to[tmp[0] - 'a'].push_back(ff[0] - 'a');
	}
	for (int i = 0; i < 6; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 6; j++) if (dp[i - 1][j]) {
			for (int k = 0; k < to[j].size(); k++) {
				dp[i][to[j][k]] += dp[i - 1][j];
			}
		}
	}
	printf("%d\n", dp[n][0]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define MOD 1000000007

LL power(LL x, LL y) {
	LL ret = 1;
	for ( ; y; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

#define inv(x) power(x, MOD - 2)

int n;
int a[1231][1231];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			read(a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		vector <int> b;
		for (int j = 1; j <= 3; j++) {
			if (i != j) b.push_back(j);
		}
		printf("%d ", int(0.5 + sqrtl((long long)a[i][b[0]] * a[i][b[1]] / a[b[0]][b[1]])));
	}
}
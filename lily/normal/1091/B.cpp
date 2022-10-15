#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)


int n;
int a[1005], b[1005], x[1005], y[1005];

map < pair<int, int>, int> G;

void check(int q, int w) {
	G.clear();
	for (int i = 1; i <= n; i++) {
		G[{q - a[i], w - b[i]}]++;
	}
	for (int i = 1; i <= n; i++) {
		if (G[{x[i], y[i]}]-- <= 0) {
			return;
		}
	}
	printf("%d %d\n", q, w);
	exit(0);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]) ;read(b[i]);
	}
	for (int i = 1; i <= n; i++) {
		read(x[i]) ;read(y[i]);
	}
	for (int i =1  ;i <= n; i++) {
		check(x[1] + a[i], y[1] + b[i]);
	}
	return 0;
}
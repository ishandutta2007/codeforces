#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 505;

int n, m;
int X[Maxn];
ld res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &X[i]);
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		res = max(res, ld(X[a] + X[b]) / c);
	}
	cout << fixed << setprecision(15) << res << endl;
	return 0;
}
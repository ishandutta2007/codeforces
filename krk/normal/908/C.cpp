#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 1005;

int n, r;
int x[Maxn];
ld res[Maxn];

int main()
{
	scanf("%d %d", &n, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		res[i] = r;
		for (int j = 0; j < i; j++) {
			int dif = abs(x[j] - x[i]);
			if (dif <= 2 * r) {
				ld delt = sqrt(ld(2 * r) * (2 * r) - ld(dif) * dif);
				res[i] = max(res[i], delt + res[j]);
			}
		}
		cout << fixed << setprecision(10) << res[i] << (i + 1 < n? ' ': '\n');
	}
	return 0;
}
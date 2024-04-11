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

#define MAXN 100005

inline int gcd(int a, int b) {
	while (b) {
		int c = a;
		a = b;
		b = c % b;
	}
	return a;
}

int n, ans = 0;
int a[MAXN];

int main() {
	cin >> n;
	int g = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		g = gcd(g, a[i]);
	}
	if (g > 1) return puts("YES\n0"), 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] & 1) {
			if (a[i + 1] & 1) ans++, a[i + 1] = 0;
			else ans += 2;
		}
	}
	puts("YES");
	printf("%d\n", ans);
	return 0;
}
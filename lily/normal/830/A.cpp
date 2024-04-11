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
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

int n, m, p;

LL a[10005], b[10005];


bool chk(LL mid) {
	for (int i = 1, j = 1; i <= n; i++, j++) {
		while (j <= m && abs(a[i] - b[j]) + abs(b[j] - p) > mid) j++;
		if (j > m) return 0;
	}
	return 1;
}

int main() {
	read(n); read(m); read(p);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= m; i++) read(b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	LL l = 0, r = 0x17f7f7f7f;
	while (l < r) {
		LL mid = (l + r) >> 1;
		if (chk(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", l);
	return 0;
}
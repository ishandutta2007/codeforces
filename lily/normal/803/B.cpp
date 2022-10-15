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

#define MAXN 233333

int n;
int a[MAXN];
int ans[MAXN];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(ans, 0x3f, sizeof ans);
	for (int i = 1, last = -2333333; i <= n; i++) {
		last = !a[i] ? i : last;
		ans[i] = min(ans[i], i - last);
	}
	
	for (int i = n, last = 23333333; i; i--) {
		last = !a[i] ? i : last;
		ans[i] = min(ans[i], last - i);
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

	return 0;
}
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

int n;
int ans = 23333333;
string a[55], b[55];

int work(int st) {
	int tot = 0, ret = 0;
	for (int i = 1; i <= n; i++) if (i != st) b[++tot] = a[i];
	for (int i = 1; i <= tot; i++) {
		int siz = b[i].size(), flag = 0;
		for (int j = 0; j < siz; j++) {
			if (b[i] == a[st]) {
				ret += j;
				flag = 1;
				break;
			}
			b[i] = b[i].substr(1, siz - 1) + b[i].substr(0, 1);
		}
		if (!flag) return 0;
	}
	ans = min(ans, ret);
	return 1;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (!work(1)) return puts("-1"), 0;
	for (int i = 2; i <= n; i++) work(i);
	cout << ans << endl;
	return 0;
}
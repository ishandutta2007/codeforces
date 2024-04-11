#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 1000010;
const int LN = 30;
const int MX = MAXN * (LN + 1);

int n, k;
int a[MAXN];

int dd = 0;

int go[MX][2];
int sz[MX];
int cnt = 1;

int add(int x) {
	int now = 0;
	for (int i = LN - 1; i >= 0; --i) {
		++sz[now];
		int gg = (dd >> i) & 1;
		if (go[now][gg] == 0)
			now = go[now][gg] = cnt++;
		else
			now = go[now][gg];
	}
	++sz[now];

	dd ^= x;
	int ans = 0;
	now = 0;
	for (int i = LN - 1; i >= 0; --i) {
		int gk = (k >> i) & 1;
		int gg = (dd >> i) & 1;
		if (gk == 0) {
			if (go[now][gg ^ 1])
				ans += sz[go[now][gg ^ 1]];
			now = go[now][gg];
			if (now == 0)
				break;
		}
		else {
			now = go[now][gg ^ 1];
			if (now == 0)
				break;
		}
	}
	if (now != 0)
		ans += sz[now];
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += add(a[i]);
	cout << ans << "\n";
	return 0;
}
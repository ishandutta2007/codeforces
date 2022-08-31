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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int n;
int p[220000];
int b[220000];
int was[220000];

void dfs1(int v) {
	was[v] = 1;
	if (!was[p[v]])
		dfs1(p[v]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i), --p[i];
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i);
	int x = 0;
	for (int i = 0; i < n; ++i)
		x ^= b[i];
	int ans = 0;
	if (x == 0)
		++ans;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!was[i]) {
			dfs1(i);
			++cnt;
		}
	}
	if (cnt != 1)
		ans += cnt;
	cout << ans << "\n";
	return 0;
}
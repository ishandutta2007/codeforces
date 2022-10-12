#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
map<int, int> Map;
int a[10010], la, X, Y;
void solve() {
	la = 0;
	for (auto it : Map) {
		int u = it.first, y = it.second;
		if (y < 2)continue;
		if (y >= 4) {
			printf("%d %d %d %d\n", u, u, u, u);
			return;
		}
		a[la++] = u;
	}
	X = a[1], Y = a[0];
	for (int i = 0; i < la - 1; i++) {
		if (1LL * a[i + 1] * Y < 1LL * X * a[i]) {
			X = a[i + 1];
			Y = a[i];
		}
	}
	printf("%d %d %d %d\n", X, X, Y, Y);
}
int main() {
	int _,n,x;
	for (scanf("%d", &_); _--;) {
		Map.clear();
		for (scanf("%d", &n); n--;) {
			scanf("%d", &x);
			Map[x] ++;
		}
		solve();
	}
	return 0;
}
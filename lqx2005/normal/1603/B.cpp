#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<int, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;

void solve() {
	int x, y;
	scanf("%d%d", &x, &y);
	if(x > y) printf("%d\n", x + y);
	else {
		int k = y / x;
		printf("%d\n", (y + k * x) / 2);
	}
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) {
		solve();
	}
	return 0;
}
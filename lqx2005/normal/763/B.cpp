#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<i64, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
int main() {
	int n;
	scanf("%d", &n);
	printf("YES\n");
	for(int i = 1; i <= n; i++) {
		int xa, xb, ya, yb;
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		printf("%d\n", (xa & 1) * 2 + (ya & 1) + 1);
	}
	return 0;
}
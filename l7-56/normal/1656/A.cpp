#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 1e5 + 10, inf = 1e9 + 10;
int n,a[maxn];
void work() {
	scanf("%d", &n);
	pii mn = {inf, 0}, mx = {-1, 0};
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pii nw = {a[i], i};
		mn = min(mn, nw), mx = max(mx, nw);
	}
	printf("%d %d\n", mn.second, mx.second);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e4 + 10;
int n,a[maxn];
void work() {
	scanf("%d", &n);
	bool flg = 0; int mx = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (mx > a[i]) flg = 1;
		mx = max(mx, a[i]);
	}
	printf(flg ? "YES\n" : "NO\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}
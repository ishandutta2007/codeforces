#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 110;
int n,a[maxn];
void work() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), ans |= a[i];
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n,k,a[maxn];
void work() {
	set <int> s;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		if (s.find(a[i]) != s.end()) return printf("YES\n"), void();
		s.insert(a[i] - k), s.insert(a[i] + k);
	}
	printf("NO\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}
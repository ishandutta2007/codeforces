#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)
int n;

void work() {
	vector <int> a;
	read(n);
	for (int i = 1; i<= n; i++) {
		int x; read(x);
		a.push_back(x);
	}
	if (n & 1) {
		puts ("-1");
		return;
	}
	vector <pair <int, int>> ans;
	for (int i = 0; i < n; i += 2) {
		if (a[i] + a[i + 1] == 0) {
			ans.push_back({i, i});
			ans.push_back({i + 1, i + 1});
		}
		else ans.push_back({i, i + 1});
	}
	printf("%d\n", (int) ans.size());
	for (auto [l, r] : ans) {
		printf("%d %d\n", l + 1, r + 1);
	}
}

int main() {
	int T; read(T);
	while (T--) work();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)
int n;

void work() {
	vector <int> a;
	read(n);
	int sum = 0;
	for (int i = 1; i<= n; i++) {
		int x; read(x);
		a.push_back(x);
		sum += x;
	}
	if (sum & 1) {
		puts ("-1");
		return;
	}
	vector <pair <int, int>> ans;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			int j = i + 1;
			while (!a[j]) j++;
			if (a[i] + a[j] == 0 && (j - i) % 2 == 0) ans.push_back({i, j});
			else if (a[i] + a[j] && (j - i) % 2 == 1) {
				ans.push_back({i, j});
			}
			else {
				ans.push_back({i, i});
				ans.push_back({i + 1, j});
			}
			i = j;
		}
		else ans.push_back({i, i});
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
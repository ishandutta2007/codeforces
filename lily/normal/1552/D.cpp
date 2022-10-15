#include <bits/stdc++.h>
using namespace std;
int n;
vector< int > a;
bool ans = false;
vector <int> h;
void dfs(int dep, int cur = 0) {
	if (dep == n) {
		for (auto v : h) {
			if (v == cur) ans = true;
		}
		return;
	}
	dfs(dep + 1, cur + a[dep]);
	dfs(dep + 1, cur - a[dep]);
	h.push_back(a[dep]);
	dfs(dep + 1, cur);
	h.pop_back();
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		a.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			a.push_back(x);
		}
		ans = false;
		dfs(0);
		puts(ans ? "YES" : "NO");
	}
}
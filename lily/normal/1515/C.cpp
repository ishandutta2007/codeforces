#include <bits/stdc++.h>
using namespace std;
int n, m, X;

void work() {
	scanf("%d%d%d", &n, &m, &X);
	vector < pair<int, int> > a;
	for (int i = 1; i <= n; i++) {
		int  x; scanf("%d" , &x);
		a.push_back({x, i});
	}
	if (n < m) {puts("NO"); return;}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	priority_queue < pair <int, int> > q;
	for (int i = 1; i <= m; i++) q.push({0, i});
	vector <int> ans; ans.resize(n + 1);
	for (auto i : a) {
		auto x = q. top(); q.pop();
		ans[i.second] = x.second;
		x.first -= i.first;
		q.push(x);
	}
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	puts("");
}

int main() {
	int T;
	cin >> T;
	while (T--) work();
}
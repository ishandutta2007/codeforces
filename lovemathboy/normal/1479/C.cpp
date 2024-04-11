#include <bits/stdc++.h>
using namespace std;

int l, r;
vector<pair<pair<int, int>, int> > ans;

inline void add(int x, int y, int w) {
	ans.push_back(make_pair(make_pair(x, y), w));
}

void solve() {
	
	if (l == 1) {
		add(1, 32, 1);
		l = 2;
	}
	if (r - l <= 29) {
		for (int i = 2; i <= 2 + r - l; i++) {
			add(1, i, 1);
			add(i, 32, l+i-3);
		}
		return;
	}
	int mini = 2;
	if (l == 2) {
		add(1, 2, 1);
		add(2, 32, 1);
		mini = 3;
		l = 3;
	}
	/*if (l == 3) {
		add(1, mini, 1);
		add(mini, mini+1, 1);
		add(mini+1, 32, 1);
		add(1, mini+1, 4);
		add(mini, 32, 3);
		mini += 2;
		l = 6;
	}*/
	
	while (l <= r) {
		vector<int> a;
		a.resize(100, 1);
		//a[32] = 0;
		int sz = min(l-1, (int)log2(r - l + 1) + 1);
		add(1, mini, l - sz);
		int len = l - sz;
		for (int i = mini; i < mini + sz - 1; i++) {
			add(i, i+1, 1);
		}
		add(mini + sz - 1, 32, 1);
		l++;
		for (int i = mini + sz - 1; i >= mini - 1; i--) {
			a[i] = a[i+1];
			int cur = 2 + a[i+1];
			for (int j = 2; j <= sz; j++) {
				if (i + j >= mini + sz + 1) continue;
				int u = i, v = i+j;
				if (v == mini + sz) v = 32;
				if (u == mini - 1) u = 1;
				if (l + a[v] <= r + 1) {
					l += a[v];
					if (u == 1) add(u, v, cur + len - 1);
					else add(u, v, cur);
					a[u]+=a[v];
					cur += 1 + a[v];
				}
				else cur++;
			}
		}
		mini += sz;
	}
}

int main() {
	scanf("%d %d", &l, &r);
	int n = 32;
	solve();
	printf("YES\n%d %d\n", n, (int)ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
	}
	return 0;
}
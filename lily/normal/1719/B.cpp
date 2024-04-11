#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

int n, K;
void work() {
	read(n); read(K);
	vector <int> l[2], r[2], w;
	for (int i = 1; i <= n; i++) {
		int x = i;
		if (x % 4 == 0) r[1].push_back(x);
		else if ((x + K) % 4 == 0) l[1].push_back(x);
		else if (x % 2 == 0) r[0].push_back(x);
		else if ((x + K) % 2 == 0) l[0].push_back(x);
		else w.push_back(x);
	}
	vector <pair <int, int>> ans;
	while (l[0].size() && r[0].size()) {
		ans.push_back({l[0].back(), r[0].back()});
		l[0].pop_back(); r[0].pop_back();
	}
	while (l[1].size() || r[1].size()) {
		auto i = l[1].size() ? l[1].back() : r[1].back();
		bool sw = false;
		if (l[1].size()) l[1].pop_back();
		else r[1].pop_back(), sw = true;
		if (w.size()) {
			ans.push_back({i, w.back()});
			w.pop_back();
		}
		else if (l[0].size() || r[0].size()) {
			if (l[0].size() >= r[0].size()) {
				ans.push_back({i, l[0].back()});
				l[0].pop_back();
			}
			else {
				ans.push_back({i, r[0].back()});
				r[0].pop_back();
			}
		} else if (l[1].size() || r[1].size()) {
			if (l[1].size() >= r[1].size()) {
				ans.push_back({i, l[1].back()});
				l[1].pop_back();
			}
			else {
				ans.push_back({i, r[1].back()});
				r[1].pop_back();
			}
		}
		if (sw) swap(ans.back().first, ans.back().second);
	}
	bool flag = !w.size();
	while (flag && l[0].size()) {
		if ((l[0].back() + K) % 4 * l[0].back() % 4 == 0) {
			auto i = l[0].back();
			l[0].pop_back();
			auto j = l[0].back();
			l[0].pop_back();
			ans.push_back({i, j});
		}
		else flag = false;
	}
	while (flag && r[0].size()) {
		if ((r[0].back() + K) % 4 * r[0].back() % 4 == 0) {
			auto i = r[0].back();
			r[0].pop_back();
			auto j = r[0].back();
			r[0].pop_back();
			ans.push_back({i, j});
		}
		else flag = false;
	}
	if (flag) {
		puts ("YES");
		for (auto i : ans) printf("%d %d\n", i.first, i.second);
	}
	else puts ("NO");
}

int main() {
	int T;
	read(T);
	while (T--) work();
}
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a[N];
set<int> s;
vector<int> ans;

int main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}
	ans = {a[1]};
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 31; j++) {
			auto x = (long long)a[i] + (1 << j);
			auto y = (long long)a[i] - (1 << j);
			bool f = x <= 1e9 && s.count(x);
			bool g = y >= -1e9 && s.count(y);
			if (f && g && ans.size() < 3) {
				ans = {a[i], (int)x, (int)y};
			} else if (f && ans.size() < 2) {
				ans = {a[i], (int)x};
			} else if (g && ans.size() < 2) {
				ans = {a[i], (int)y};
			}
		}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) { printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]); }
}
// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long LL;

const int N = 3e5 + 5;

int n, m, k[N], c[N];

LL ans;

multiset<int> s;

bool st[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m); ans = 0; s.clear();
		for (int i = 1; i <= n; i++) scanf("%d", k + i);
		sort(k + 1, k + 1 + n);
		for (int i = 1; i <= m; i++) scanf("%d", c + i), s.insert(c[i]);
		for (int i = 1; i <= n; i++) ans += c[k[i]];
		for (int i = 1; i <= n; i++) {
			if (*s.begin() < c[k[i]]) {
				int t = *s.begin();
				ans -= c[k[i]] - t;
				s.erase(s.find(t));
				s.insert(c[k[i]]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
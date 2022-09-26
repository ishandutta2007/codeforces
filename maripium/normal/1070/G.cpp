#include <bits/stdc++.h>
using namespace std;

int n, m;
int s[105], h[105];
int a[105], b[105];
bool del[105];

bool go(int id,int u) {
	int now = h[id];
	if (s[id] <= u) {
		for (int i = s[id]; i <= u; ++i) {
			now += a[i];
			if (now < 0) {
				return false;
			}
		}
		for (int i = s[id]; i <= u; ++i) {
			a[i] = 0;
		}
		return true;
	} else {
		for (int i = s[id]; i >= u; --i) {
			now += a[i];
			if (now < 0) {
				return false;
			}
		}
		for (int i = s[id]; i >= u; --i) {
			a[i] = 0;
		}
		return true;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", s + i, h + i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b + i);
	}
	for (int u = 1; u <= n; ++u) {
		for (int i = 1; i <= n; ++i) {
			a[i] = b[i];
		}
		for (int i = 1; i <= m; ++i) {
			del[i] = false;
		}
		vector<int> order;
		int cnt = 0;
		bool found = true;
		while (found) {
			found = false;
			for (int i = 1; i <= m; ++i) {
				if (!del[i] && go(i, u)) {
					++cnt;
					del[i] = true;
					order.push_back(i);
					found = true;
				}
			}
		}
		if (cnt == m) {
			printf("%d\n", u);
			for (int v : order) {
				printf("%d ", v);
			}
			return 0;
		}
	} 
	puts("-1");
}
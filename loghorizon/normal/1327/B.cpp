#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100005;

int n;

bool vis[N], ok[N];

vector<int> g[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int len; scanf("%d", &len);
			for (int j = 0; j < len; j++) {
				int x; scanf("%d", &x);
				g[i].push_back(x);
				if (!ok[i]) {
					if (vis[x]) continue;
					else {
						vis[x] = true;
						ok[i] = true;
					}	
				}
			}
			if (ok[i]) cnt++;
		}

		if (cnt == n) puts("OPTIMAL");
		else {
			puts("IMPROVE");
			int t = -1;
			for (int i = 1; i <= n; i++) {
				if (!vis[i]) { t = i; break;}
			}

			for (int i = 1; i <= n; i++) {
				if (!ok[i]) {
					printf("%d %d\n", i, t);
					break;
				}
			}
		}

		for (int i = 1; i <= n; i++) g[i].clear(), vis[i] = false, ok[i] = false;
	}
	return 0;
}
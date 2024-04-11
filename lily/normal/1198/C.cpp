#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 303031


int n, m;
vector <int> E;
bool vis[N];

void work() {
	read(n); read(m);
	int nn = 3 * n;
	E.clear();
	for (int i = 1; i <= nn; i++) vis[i] = 0;
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		if (!vis[u] && !vis[v]) {
			vis[u] = 1;
			vis[v] = 1;
			E.push_back(i);
		}
	}
	if (E.size() < n) {
		printf("IndSet\n");
		int cnt = n;
		for (int i = 1; i <= nn; i++) {
			if (!vis[i] && cnt > 0) {
				cnt --;
				printf("%d ", i);
			}
		}
	}
	else {
		printf("Matching\n");
		int cnt = n;
		for (auto v : E) {
			if (cnt > 0) {
				cnt --;
				printf("%d ", v);
			}
		}
	}
	puts("");

}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}
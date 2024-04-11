#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 100005

int n;
int d[N], vis[N];
vector <vector <int>> a[N];

int main() {
	read(n);
	for (int i = 1; i <= n - 2; i++) {
		int x, y, z;
		read(x); read(y); read(z);
		vector <int> w = {x, y, z};
		sort(w.begin(), w.end());
		a[x].push_back(w);
		a[y].push_back(w);
		a[z].push_back(w);
	}
	vector <int> L, p;
	for (int i = 1; i <= n; i++) {
		if (a[i].size() == 1) {
			L.push_back(i);
		}
		d[i] = a[i].size();
	}
	int cur = L[0];
	for (int i = 1; i <= n - 3; i++) {
		p.push_back(cur);
		vis[cur] = 1;
		auto v = a[cur][0];
		int nxt;
		for (auto i : v) {
			for (int j = 0; j < a[i].size(); j++) {
				if (a[i][j] == v) {
					swap(a[i][j], a[i].back());
					a[i].pop_back();
					break;
				}
			}
			if (i != cur && a[i].size() == 1) nxt = i;
		}
		cur = nxt;
	}
	for (int i = 1; i <= n; i++) if (d[i] == 3 && !vis[i]) p.push_back(i);
	for (int i = 1; i <= n; i++) if (d[i] == 2 && !vis[i]) p.push_back(i);
	for (int i = 1; i <= n; i++) if (d[i] == 1 && !vis[i]) p.push_back(i);
	for (auto v : p) {
		printf("%d ", v);
	}
}
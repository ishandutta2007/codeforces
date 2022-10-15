#include <bits/stdc++.h>
using namespace std;


int n, k;
int vis[202];
pair <int, int> a[111];

void work() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n * 2; i++) {
		vis[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		vis[x] = 1; vis[y] = 1;
		if (x > y) swap(x, y);
		a[i] = {x, y};
	}
	vector <int> notvis;
	for (int i = 1; i <= 2 * n; i++) {
		if (!vis[i]) notvis.push_back(i);
	}
	for (int i = 0; i < n - k; i++) {
		a[k + i] = {notvis[i], notvis[i + n - k]};
	}
/*	for (int i = 0; i < n; i++) {
		printf("%d %d\n", a[i].first, a[i].second);
	}*/
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].first < a[j].first && a[i].second > a[j].second) continue;
			if (a[j].first < a[i].first && a[j].second > a[i].second) continue;
			if (a[i].first > a[j].second) continue;
			if (a[j].first > a[i].second) continue;
			ans ++;
		}
	}
	printf("%d\n", ans);

}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 1005;

int n, a[N];

vector<int> g[N];

bool inline cmp(int x, int y) {
	return (a[x] == a[y] ? x < y : a[x] < a[y]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j < i; j++)
			if (a[j] > a[i]) g[i].push_back(j);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end(), cmp), ans += g[i].size();
	printf("%d\n", ans);
	for (int i = n; i; i--) 
		for (int j = 0; j < g[i].size(); j++)
			printf("%d %d\n", g[i][j], i);
	return 0;
}
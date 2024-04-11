# include <bits/stdc++.h>
using namespace std;

const int N = 200010;
vector<int> g[N];
int seq[N], inq[N];
int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < n; ++i) scanf("%d", &seq[i]);
	for(int i = 1; i <= n; ++i) inq[i] = n + 2;
	inq[1] = 0;
	for(int i = 0; i < n; ++i) {
		int u = seq[i];
		for(auto v: g[u]) inq[v] = min(inq[v], i + 1);
	}
	for(int i = 1; i < n; ++i) {
		if(inq[seq[i-1]] > inq[seq[i]]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
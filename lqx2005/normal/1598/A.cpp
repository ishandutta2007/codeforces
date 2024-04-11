#include <bits/stdc++.h>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))

using namespace std;
const int N = 100 + 10;
int n;
int vis[N][2], used[N][2];
char s[N];

void dfs(int x, int y) {
	if(x < 1 || x > n || y < 0 || y > 1) return;
	if(vis[x][y] || used[x][y]) return;
	vis[x][y] = 1;
	dfs(x - 1, y);
	dfs(x - 1, y + 1);
	dfs(x - 1, y - 1);
	dfs(x, y - 1);
	dfs(x, y + 1);
	dfs(x + 1, y - 1);
	dfs(x + 1, y);
	dfs(x + 1, y + 1);
	return;
}

int main() {
	int T;
	for(cin >> T; T--; ) {
		cin >> n;
		for(int i = 1; i <= n; i++) vis[i][0] = vis[i][1] = 0;
		cin >> (s + 1);
		for(int i = 1; i <= n; i++) {
			used[i][0] = s[i] - '0';
		}
		cin >> (s + 1);
		for(int i = 1; i <= n; i++) {
			used[i][1] = s[i] - '0';
		}
		dfs(1, 0);
		if(vis[n][1]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
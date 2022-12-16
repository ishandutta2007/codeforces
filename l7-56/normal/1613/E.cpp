#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

const int maxn = 1e6 + 10;
char mp[maxn];
int n,m,T,lx,ly;
#define num(i, j) ((i - 1) * m + (j - 1))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool free(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m && mp[num(x, y)] == '.'; }

void dfs(int x, int y) {
	int cnt = 0;
	for(int k = 0; k < 4; ++k) {
		int nx = x + dx[k], ny = y + dy[k];
		if(free(nx, ny)) cnt++;
	}
	if(mp[num(x, y)] == '.' && cnt > 1) return;
	if(mp[num(x, y)] == '.') mp[num(x, y)] = '+';
	for(int k = 0; k < 4; ++k) {
		int nx = x + dx[k], ny = y + dy[k];
		if(free(nx, ny)) dfs(nx, ny);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			char s[maxn];
			scanf("%s", s + 1);
			for(int j = 1; j <= m; ++j) {
				mp[num(i, j)] = s[j];
				if(s[j] == 'L') lx = i, ly = j;
			}
		}
		dfs(lx, ly);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) putchar(mp[num(i, j)]);
			putchar('\n');
		}
	}
	return 0;
}
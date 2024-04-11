#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef double db;

const int N = 1e3 + 10, D = 55, M = N * D, P = 1e9 + 7;
string num, x, y;
int deg[D], len = 0, dp[D][M];
int n, d, to, rt;
int ch[M][10], tot = 0, vis[M], fail[M];
void build() {
	for(int i = 0; i < 10; i++) ch[0][i] = rt;
	queue<int> q;
	q.push(rt);
	fail[rt] = 0;
	for(; !q.empty(); ) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < 10; i++) {
			if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
			else ch[u][i] = ch[fail[u]][i];
		}
	}
	for(int i = 1; i < tot; i++) for(int j = 0; j < 10; j++) if(vis[ch[i][j]]) ch[i][j] = to;
	for(int i = 0; i < 10; i++) ch[to][i] = to;
	return;
}

int check(string x) {
	int now = rt;
	for(int i = 0; i < d; i++) {
		now = ch[now][x[i] - '0'];
	}
	return now == to;
}

int dfs(int now, int id, int lim) {
	if(now < 0) return to == id;
	if(!lim && dp[now][id] != -1) return dp[now][id];
	int res = 0, m = lim ? deg[now] : 9;
	for(int i = 0; i <= m; i++) {
		(res += dfs(now - 1, ch[id][i], lim && i == m)) %= P;
	}
	if(!lim) dp[now][id] = res;
	return res;
}

int solve(string num) {
	len = num.length();
	for(int i = len - 1; i >= 0; i--) deg[i] = num[len - i - 1] - '0';
	return dfs(len - 1, rt, 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> num >> x >> y;
	n = num.length(), d = x.length();
	rt = ++tot;
	for(int i = 0; i + d / 2 - 1 < n; i++) {
		int now = rt;
		for(int j = i; j <= i + d / 2 - 1; j++) {
			int k = num[j] - '0';
			if(ch[now][k] == 0) ch[now][k] = ++tot;
			now = ch[now][k];
		}
		vis[now] = 1;
	}
	to = ++tot;
	build();
	printf("%d\n", (solve(y) - solve(x) + check(x) + P) % P);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10; 

struct Edge {
	int u, v, next;
}G[N];

int low[N], dfn[N], head[N], w[N], to[N], st[N], inst[N];
int n, tot = 0, cnt = 0, len = 0, ans = 0;

void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	st[++len] = u; inst[u] = 1;
	if(!dfn[to[u]]) {
		tarjan(to[u]);
		low[u] = min(low[u], low[to[u]]);
	} else if(inst[to[u]]) {
		low[u] = min(low[u], dfn[to[u]]);
	}
	if(low[u] == dfn[u]) {
		int big = 0, minn = INT_MAX;
		while(st[len + 1] != u) {
			big++;
			int tmp = st[len--];
			minn = min(minn, w[tmp]);
			inst[tmp] = 0;
		}
		if(big >= 2) ans += minn;
		else if(big == 1) {
			if(to[u] == u) ans += minn;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		to[i] = a;
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	cout << ans << endl;
	return 0;
}
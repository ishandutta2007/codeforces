#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 2e5 + 10;
int T,n,k;

struct Edge {
	int v,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add(int u, int v) {
	e[++cnt_e] = (Edge) {v, h[u]};
	h[u] = cnt_e; return;
}
int st[maxn],tp,con[maxn];
void init(int n) {
	for(int i = 1; i <= n; ++i) h[i] = 0, con[i] = 0;
	cnt_e = 0;
}

void dfs1(int u, int pre) {
	con[st[tp - tp / 2]] |= con[u];
	for(int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if(v == pre) continue;
		st[++tp] = v;
		dfs1(v, u);
		st[tp--] = 0;
	}
}

int ans;
bool dfs2(int u, int pre) {
	if(con[u]) return ans++, 0;
	int cnt = 0;
	for(int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		cnt++;
		if(v == pre) continue;
		if(dfs2(v, u)) return 1;
	}
	return cnt == 1 && u != 1;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		init(n);
		for(int i = 1, x; i <= k; ++i) scanf("%d", &x), con[x] = 1;
		for(int i = 1, x, y; i < n; ++i) {
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		dfs1(1, 0);
		ans = 0;
		if(dfs2(1, 0)) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}
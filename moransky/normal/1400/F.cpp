#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 2005, S = 5005, INF = 0x3f3f3f3f;

int n, x, d[N], cnt, tr[S][9], fail[S];
int idx, f[S], g[S], q[S];

bool match[S];

char s[N];

bool inline check(int m) {
    for (int i = 1; i <= m; i++) {
        int s = 0;
        for (int j = i; j <= m; j++) {
            s += d[j];
            if (s != x && x % s == 0) return false;
        }
    }
    return true;
}

void inline insert(int m) {
	int p = 0;
	for (int i = 1; i <= m; i++) {
		int ch = d[i] - 1;
		if (!tr[p][ch]) tr[p][ch] = ++idx;
		p = tr[p][ch];
	}
	match[p] = true;
}

void dfs(int u, int rest) {
	if (!rest) {
	    if (check(u - 1)) insert(u - 1);
	    return;
	}
	for (int i = 1; i <= min(rest, 9); i++) {
		d[u] = i;
		dfs(u + 1, rest - i);
	}
}

void inline build() {
	int hh = 0, tt = -1;
    for (int i = 0; i < 9; i++)
    	if (tr[0][i]) q[++tt] = tr[0][i];
   	while (hh <= tt) {
   		int u = q[hh++];
   		for (int i = 0; i < 9; i++) {
   			int &v = tr[u][i];
   			if (!v) v = tr[fail[u]][i];
   			else fail[v] = tr[fail[u]][i], q[++tt] = v;
   		}
   	}
}

int main() {
	scanf("%s%d", s + 1, &x);
	n = strlen(s + 1);
	dfs(1, x);
	build();
	memset(f, 0x3f, sizeof f); f[0] = 0;
	for (int i = 1; i <= n; i++) {
		int ch = s[i] - '1';
		for (int j = 0; j <= idx; j++) g[j] = f[j], f[j] = INF;
		for (int j = 0; j <= idx; j++) {
			if (g[j] != INF) {
				f[j] = min(f[j], g[j] + 1);
				int v = tr[j][ch];
				if (!match[v]) f[v] = min(f[v], g[j]);
			}
		}
 	}
 	int ans = 2e9;
 	for (int i = 0; i <= idx; i++) ans = min(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
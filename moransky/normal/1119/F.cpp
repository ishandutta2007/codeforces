// xtqqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 250005;

int n, fa[N], faW[N], d[N], t, len, c[N], deg[N];

LL f[N][2], s[N], ans[N];

vector<PII> g[N];

void dfs(int u) {
	for (PII t: g[u]) {
		int v = t.fi;
		if (v == fa[u]) continue;
		fa[v] = u, faW[v] = t.se;
		dfs(v);
	}
	d[++t] = u;
}

struct T{
	multiset<LL> A, B;
	int k, now; LL s;
	void inline ins(LL x) {
		B.insert(x);
	}
	
	void inline del(LL x) {
		if (A.find(x) != A.end()) {
			s -= x;
			A.erase(A.find(x));
			now--;
		} else if (B.find(x) != B.end()) {
			B.erase(B.find(x));
		}
	}
	
	void inline maintain() {
		while (A.size() && B.size() && *--A.end() > *B.begin()) {
			LL x = *--A.end(), y = *B.begin();
			s += y - x;
			A.erase(A.find(x)), B.erase(B.find(y));
			A.insert(y), B.insert(x);
		}
		while (now < k && B.size() && *B.begin() < 0) {
			LL y = *B.begin();
			s += y;
			A.insert(y), B.erase(B.find(y));
			++now;
		}
	}
	
	LL inline ask() {
		maintain();
		return s;
	}
} h[N][2];

void inline del(int x) {
	if (x == 1) return;
	LL w = f[x][1] - f[x][0];
	s[fa[x]] -= f[x][0];
	h[fa[x]][0].del(w);
	h[fa[x]][1].del(w);
}

void inline upd(int x) {
	if (x == 1) return;
	s[fa[x]] += f[x][0];
	LL w = f[x][1] - f[x][0];
	h[fa[x]][0].ins(w);
	h[fa[x]][1].ins(w);
}

int main() {
	read(n);
	LL sm = 0;
	for (int i = 1, u, v, w; i < n; i++)
		read(u), read(v), read(w), g[u].pb(mp(v, w)), g[v].pb(mp(u, w)), sm += w, deg[u]++, deg[v]++;
	dfs(1);
	ans[0] = sm;
	for (int k = 1; k < n; k++) {
		LL res = 0;
		//cout << k <<" --\n";
		for (int i = 1; i <= t; i++) {
			int u = d[i];
			del(u);
			h[u][0].k = k, h[u][1].k = k - 1;
			f[u][0] = s[u] + faW[u] + h[u][0].ask();
			f[u][1] = s[u] + h[u][1].ask();
			upd(u);
			if (deg[fa[u]] < k) res += min(f[u][0], f[u][1]);
		}
		len = 0;
		for (int i = 1; i <= t; i++) {
			int u = d[i];
			if (deg[u] == k) {
				del(u);
				f[u][0] = faW[u], f[u][1] = 0;
				upd(u);
			} else c[++len] = u;
		}
		ans[k] = res;
		t = len;
		for (int i = 1; i <= t; i++) d[i] = c[i];
	}
	for (int i = 0; i < n; i++) printf("%lld ", ans[i]);
    return 0;
}
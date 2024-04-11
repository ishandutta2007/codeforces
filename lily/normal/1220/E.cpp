#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


#define N 202011
vector <int> E[N], F[N];
int n, m, w[N], S;
int d[N];
bool vis[N], tag[N];

long long ans = 0;
	
pair<LL, int> ddd(int x, int fa) {
	pair<LL, int> ret = {0, x};
	for (auto v : E[x]) {
		if (v != fa) {
			ret = max(ret, ddd(v, x));
		}
	}
	return {ret.first + w[x], ret.second};
}

pair <LL, LL> dp2(int x, int fa) {
	LL ret = 0, mal = 0;
	for (auto v : F[x]) {
		if (v != fa) {
			pair <LL, LL> r = dp2(v, x);
			mal = max(mal, r.second);
			mal = max(mal, r.first + ret + w[x]);
			ret = max(ret, r.first);
		}
	}
	return {ret + w[x], mal};
}
bool find(int x, int fa = -1) {
	if (!vis[x]) {
		ans += w[x];
		w[x] = 0;
		return 1;
	}
	for (auto v : F[x]) {
		if (v != fa) {
			if (find(v, x)) {
				ans += w[x];
				w[x] = 0;
				return 1;
			}
		}
	}
	return 0;
}

queue <int> q;

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(w[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		E[u].push_back(v);
		E[v].push_back(u);
		d[u]++; d[v]++;
	}

	read(S);
	
	if (m == n - 1) {
		pair <long long, int> ret = ddd(S, -1);
		printf("%lld\n", ret.first);
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 1) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		vis[x] = 1;
		tag[x] = 1;
		for (auto v : E[x]) {
			if (!vis[v]) {
				d[v]--;
				tag[v] = 1;
				F[v].push_back(x);
				F[x].push_back(v);
				if (d[v] == 1) q.push(v);
			}
		}
	}
	

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			ans += w[i];
			w[i] = 0;
		}
	}

	if (vis[S]) {
		find(S, -1);
	}

	LL ma = 0;
	for (int i = 1; i <= n; i++) if (tag[i] && !vis[i]) {
		ma = max(ma, dp2(i, -1).first);
	}
	printf("%lld\n", ans + ma);
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
	x *= f;
}

const int N = 150005 + 5, S = 1e6 + 5;

int n, a[N], f[N], b[S], q, tot, pr[S];

bool vis[S];

vector<int> d[S];

bool st[S];

void inline prework() {
	int n = 1e6 + 1;
	for (int i = 2; i <= n; i++) {
		if (!st[i]) {
			d[i].pb(i);
			pr[++tot] = i;
			for (int j = i + i; j <= n; j += i) st[j] = 1, d[j].pb(i);
		}
	}
}

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	f[find(x)] = find(y);
}

typedef pair<int, int> PII;

vector<PII> res;

void work(int x) {
	vector<int> p;
	p = d[x];
	for (int v: d[x + 1]) p.pb(v);
	for (int i = 0; i < p.size(); i++) {
		int u = p[i];
		if (!b[u]) continue;
		for (int j = 0; j < i; j++) {
			int v = p[j];
			if (!b[v]) continue;
			int x = find(b[u]), y = find(b[v]);
			if (x != y) {
				if (x > y) swap(x, y);
				res.pb(mp(x, y));
			} 
		}
	}
}

int main() {
	prework();
	read(n); read(q);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		for (int v: d[a[i]]) {
			if (!b[v]) b[v] = i;
			else merge(b[v], i);
		}
		
	}

	for (int i = 1; i <= n; i++) work(a[i]);
	res.pb(mp(1000000000, 1000000000));
	sort(res.begin(), res.end());
	while (q--) {
		int x, y; read(x), read(y);
		if (find(x) == find(y)) puts("0");
		else {
			int u = find(x), v = find(y);
			if (u > v) swap(u, v);
			int pos = lower_bound(res.begin(), res.end(), mp(u, v)) - res.begin();
			if (res[pos] == mp(u, v)) puts("1");
			else puts("2");
		}
	}
	return 0;
}
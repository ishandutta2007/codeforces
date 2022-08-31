#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MX = 300 * 1000 + 7;

vector<int> g1[MX], g2[MX];

bool was[MX];
char res[MX];
int u[MX], v[MX];

vector<int> add;
void dfs(int v) {
	add.push_back(v);
	was[v] = true;
	for (int to : g1[v]) {
		if (!was[to]) {
			dfs(to);
		}
	}
}

int main() {
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	int id = 0;
	for (int i = 0; i < m; i++) {
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if (t == 1) {
			g1[u].push_back(v);
		//	g1[v].push_back(u);
		} else {
			::u[id] = u;
			::v[id] = v;
			g2[u].push_back(id);
			g2[v].push_back(id);
			id++;
		}
	}
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		was[v] = true;
		q.pop();
		for (int to : g1[v]) {
			if (!was[to]) {
				was[to] = true;
				q.push(to);
			}
		}
		for (int e : g2[v]) {
			int a = ::u[e], b = ::v[e];
			if (res[e] == '\0') {
				if (a == v) {
					res[e] = '+';
				} else {
					res[e] = '-';
				}
			}
			bool go = false;
			if (res[e] == '+' && a == v) go = true;
			if (res[e] == '-' && a != v) go = true;
			int to = a ^ b ^ v;
			if (go && !was[to]) {
				was[to] = true;
				q.push(to);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (was[i]) ans++;
	}
	printf("%d\n", ans);
	for (int i = 0; i < id; i++) {
		if (res[i] == '\0') {
			res[i] = '+';
		}
		printf("%c", res[i]);
	}
	printf("\n");
	memset(was, 0, sizeof(was));
	memset(res, 0, sizeof(res));
	add.clear();
	dfs(s);
	printf("%d\n", (int)add.size());
	for (int i = 0; i < id; i++) {
		if (was[u[i]]) {
			printf("-");
		} else {
			printf("+");
		}
	}
	printf("\n");
	return 0;
}
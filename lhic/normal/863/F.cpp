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
struct edge {
	int a, b, c, f, w;
};

int dd[200];
int en[200];
int go[200];
queue<int> qu;
vector<edge> ed;
vector<int> eds[200];
int n, q;
int l[200];
int r[200];
int s, t;

void add_edge(int a, int b, int c, int w) {
	edge x;
	x.a = a, x.b = b, x.c = c, x.w = w, x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	x.w = -x.w;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}

ll flow() {
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		fill(dd, dd + t + 1, (ll)1e9);
		fill(en, en + t + 1, 0);
		fill(go, go + t + 1, -1);
		qu.push(s);
		en[s] = 1;
		dd[s] = 0;
		while (!qu.empty()) {
			int x = qu.front();
			en[x] = 0;
			qu.pop();
			for (int e: eds[x]) {
				if (ed[e].c == ed[e].f)
					continue;
				int u = ed[e].b;
				if (dd[u] > dd[x] + ed[e].w) {
					dd[u] = dd[x] + ed[e].w;
					go[u] = e;
					if (!en[u])
						qu.push(u), en[u] = 1;
				}
			}
		}
		int now = t;
		ans += dd[t];
		while (now != s) {
			int e = go[now];
			++ed[e].f;
			--ed[e ^ 1].f;
			now = ed[e].a;
		}
	}
	return ans;
}

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		l[i] = 0;
		r[i] = n - 1;
	}
	for (int i = 0; i < q; ++i) {
		int tl, tr, v, t;
		scanf("%d%d%d%d", &t, &tl, &tr, &v);
		--v, --tl;
		for (int j = tl; j < tr; ++j) {
			if (t == 1)
				l[j] = max(l[j], v);
			else
				r[j] = min(r[j], v);
		}
	}
	for (int i = 0; i < n; ++i)
		if (l[i] > r[i]) {
			cout << -1 << "\n";
			return 0;
		}
	s = 2 * n;
	t = s + 1;
	for (int i = 0; i < n; ++i) {
		add_edge(s, i, 1, 0);
		for (int j = l[i]; j <= r[i]; ++j)
			add_edge(i, n + j, 1, 0);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			add_edge(i + n, t, 1, j * 2 + 1);
	}
	cout << flow() << "\n";
	return 0;
}
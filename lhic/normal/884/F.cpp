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
const int INF = 1e6;
const int MAXN = 100000;

struct edge {
	int a, b, c, f, w;
};

vector<edge> ed;
vector<int> eds[MAXN];
int dd[MAXN];
int en[MAXN];
queue<int> qu;
set<pair<int, int>> ss;
int n;
string str;
int b[MAXN];
int s, t;
int phi[MAXN];
int go[MAXN];

void add_edge(int a, int b, int c, int w) {
	edge x;
	x.a = a, x.b = b, x.c = c, x.w = w;
	x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b), x.c = 0, x.w = -x.w;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}


int flow(int k) {
	fill(dd, dd + t + 1, INF);
	fill(en, en + t + 1, 0);
	dd[s] = 0;
	en[s] = 1;
	qu.push(s);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		en[x] = 0;
		for (int e: eds[x]) {
			int u = ed[e].b;
			if (ed[e].f == ed[e].c)
				continue;
			if (dd[u] > dd[x] + ed[e].w) {
				dd[u] = dd[x] + ed[e].w;
				if (!en[u]) {
					qu.push(u);
					en[u] = 1;
				}
			}
		}
	}
	for (int i = 0; i <= t; ++i)
		phi[i] += dd[i];
	ll ans = 0;
	for (int i = 0; i < k; ++i) {
		fill(dd, dd + t + 1, INF);
		fill(go, go + t + 1, -1);
		dd[s] = 0;
		ss.clear();
		ss.insert(make_pair(dd[s], s));
		while (!ss.empty()) {
			int x = ss.begin()->second;
			ss.erase(ss.begin());
			for (int e: eds[x]) {
				int u = ed[e].b;
				if (ed[e].f == ed[e].c)
					continue;
				int wei = ed[e].w - (phi[u] - phi[x]);
				if (dd[u] > dd[x] + wei) {
					ss.erase(make_pair(dd[u], u));
					dd[u] = dd[x] + wei;
					go[u] = e;
					ss.insert(make_pair(dd[u], u));
				}
			}
		}
		for (int j = 0; j <= t; ++j)
			phi[j] += dd[j];
		ans += phi[t];
		int now = t;
		while (go[now] != -1) {
			int e = go[now];
			ed[e].f += 1;
			ed[e ^ 1].f -= 1;
			now = ed[e].a;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	s = n + (n / 2) * 27;
	t = s + 1;
	for (int i = 0; i < n; ++i)
		add_edge(s, i, 1, 0);
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < 26; ++j) {
			add_edge(n + i * 27 + j, n + i * 27 + 26, 1, 0);
		}
		add_edge(n + i * 27 + 26, t, 2, 0);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n / 2; ++j) {
			if (i == j || n - 1 - i == j)
				add_edge(i, n + j * 27 + (str[i] - 'a'), 1, -b[i]);
			else
				add_edge(i, n + j * 27 + (str[i] - 'a'), 1, 0);
		}
	}
	int ans = flow(n);
	cout << -ans << "\n";
	return 0;
}
#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

using namespace std;

const ld eps = 1e-11;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

template<typename T>
struct Dinic {
	const T INF = 1e9;
	const int INF1 = 1e9;
	struct edge {
		int a, b;
		T f, c;
	};
	int s, t;
	vector<edge> ed;
	int n;
	vector<vector<int> > eds;
	vector<T> dd;
	vector<int> pp;
	vector<int> inCut;
	Dinic(int N, int S, int TT) {
		n = N, s = S, t = TT;
		eds.clear();
		dd.clear();
		pp.clear();
		ed.clear();
		eds.resize(n);
		dd.resize(n);
		pp.resize(n);
		inCut.clear();
	}
	void add_edge(int a, int b, T c) {
		edge x;
		x.a = a;
		x.b = b;
		x.f = 0;
		x.c = c;
		eds[a].push_back(ed.size());
		eds[b].push_back(ed.size() + 1);
		ed.push_back(x);
		x.c = 0;
		swap(x.a, x.b);
		ed.push_back(x);
	}
	T dfs(int v, T fl) {
		if (v == t)
			return fl;
		if (dd[v] == dd[t])
			return 0;
		T sum = 0;
		for (; pp[v] < (int)eds[v].size(); ++pp[v]) {
			int e = eds[v][pp[v]];
			int u = ed[e].b;
			T fr = ed[e].c - ed[e].f;
			if (fr <= eps || dd[u] != dd[v] + 1 || pp[u] == (int)eds[u].size())
				continue;
			fr = dfs(u, min(fl, fr));
			ed[e].f += fr;
			ed[e ^ 1].f -= fr;
			sum += fr;
			fl -= fr;
			if (fl <= eps)
				break;
		}
		return sum;
	}
	T flow() {
		T sum = 0;
		T lst = 0;
		do {
			lst = 0;
			fill(dd.begin(), dd.end(), INF1);
			dd[s] = 0;
			queue<int> qu;
			qu.push(s);
			while (!qu.empty()) {
				int x = qu.front();
				qu.pop();
				for (int i = 0; i < (int)eds[x].size(); ++i) {
					if (ed[eds[x][i]].f < ed[eds[x][i]].c) {
						int u = ed[eds[x][i]].b;
						if (dd[u] > dd[x] + 1)
							dd[u] = dd[x] + 1, qu.push(u);
					}
				}
			}
			if (dd[t] == INF)
				break;
			fill(pp.begin(), pp.end(), 0);
			lst = dfs(s, INF);
			sum += lst;
		} while (lst > 0);
		return sum;
	}
	void dfs1(int s) {
		pp[s] = 1;
		for (int e: eds[s]) {
			if (abs(ed[e].c - ed[e].f) > eps && !pp[ed[e].b])
				dfs1(ed[e].b);
		}
	}
	void markCut() {
		inCut.resize(ed.size());
		fill(pp.begin(), pp.end(), 0);
		dfs1(s);
		for (int i = 0; i < ed.size(); ++i)
			if (pp[ed[i].a] && !pp[ed[i].b])
				inCut[i] = 1;
			else
				inCut[i] = 0;
	}
};

int n, m;

vector<tuple<int, int, ll, ll> > edd;
vector<tuple<int, int, ll, ll, ll, ll> > edd2;
pair<ll, ll> ad[1200];
const int IT = 50;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		ll a, b, c, d;
		cin >> u >> v >> a >> b >> c >> d;
		--u, --v;
		edd.push_back(make_tuple(u, v, c - a, d - b));
		edd2.push_back(make_tuple(u, v, a, b, c, d));
		ad[u].first -= a;
		ad[u].second -= b;
		ad[v].first += a;
		ad[v].second += b;
	}
	ld lb = 0;
	ld rb = 1;
	ld ans = -1;
	for (int it = 0; it < IT; ++it) {
		ld mid = (lb + rb) / 2;
		Dinic<ld> din(n + 2, n, n + 1);
		for (auto x: edd) {
			int u, v;
			ll a, b;
			tie(u, v, a, b) = x;
			din.add_edge(u, v, a * mid + b);
		}
		ld go = 0;
		for (int i = 0; i < n; ++i) {
			ld x = ad[i].first * mid + ad[i].second;
			if (x > 0) {
				din.add_edge(n, i, x);
				go += x;
			}
			else if (x < 0) {
				din.add_edge(i, n + 1, -x);
			}
		}
		ld xx = din.flow();
		if (abs(xx - go) <= eps) {
			ans = mid;
			break;
		}
		din.markCut();
		pair<ld, ld> cur = make_pair(0, 0);
		for (auto x: edd2) {
			int u, v;
			ll a, b, c, d;
			tie(u, v, a, b, c, d) = x;
			if (din.pp[u] && !din.pp[v]) {
				cur.first += c;
				cur.second += d;
			}
			else if (din.pp[v] && !din.pp[u]) {
				cur.first -= a;
				cur.second -= b;
			}
		}
		if (cur.first == 0)
			break;
		if (cur.first > 0)
			lb = mid;
		else
			rb = mid;
	}
	if (ans < -0.5) {
		cout << 0 << "\n";
		return 0;
	}
	lb = 0;
	rb = ans;
	for (int it = 0; it < IT; ++it) {
		ld mid = (lb + rb) / 2;
		Dinic<ld> din(n + 2, n, n + 1);
		for (auto x: edd) {
			int u, v;
			ll a, b;
			tie(u, v, a, b) = x;
			din.add_edge(u, v, a * mid + b);
		}
		ld go = 0;
		for (int i = 0; i < n; ++i) {
			ld x = ad[i].first * mid + ad[i].second;
			if (x > 0) {
				din.add_edge(n, i, x);
				go += x;
			}
			else if (x < 0) {
				din.add_edge(i, n + 1, -x);
			}
		}
		ld xx = din.flow();
		if (abs(xx - go) <= eps)
			rb = mid;
		else
			lb = mid;
	}
	ld l = (lb + rb) / 2;
	lb = ans;
	rb = 1;
	for (int it = 0; it < IT; ++it) {
		ld mid = (lb + rb) / 2;
		Dinic<ld> din(n + 2, n, n + 1);
		for (auto x: edd) {
			int u, v;
			ll a, b;
			tie(u, v, a, b) = x;
			din.add_edge(u, v, a * mid + b);
		}
		ld go = 0;
		for (int i = 0; i < n; ++i) {
			ld x = ad[i].first * mid + ad[i].second;
			if (x > 0) {
				din.add_edge(n, i, x);
				go += x;
			}
			else if (x < 0) {
				din.add_edge(i, n + 1, -x);
			}
		}
		ld xx = din.flow();
		if (abs(xx - go) <= eps)
			lb = mid;
		else
			rb = mid;
	}
	ld r = (lb + rb) / 2;
	cout << r - l << "\n";
	return 0;
}
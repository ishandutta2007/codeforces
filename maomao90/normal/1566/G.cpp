#include <bits/stdc++.h> 
using namespace std;

template <class T, class S>
inline bool mnto(T& a, S b) {return a > b ? a = b, 1 : 0;}
template <class T, class S>
inline bool mxto(T& a, S b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005

struct edge {
	int w, u, v;
	edge(int _w, int _u, int _v): w(_w), u(_u), v(_v) {
		if (u > v) swap(u, v);
	}
	bool operator< (const edge &o) const {
		return MT(w, u, v) < MT(o.w, o.u, o.v);
	}
};
struct hash_pair {
    size_t operator()(const ii& p) const
    {
        auto hash1 = hash<int>{}(p.FI);
        auto hash2 = hash<int>{}(p.SE);
        return hash1 ^ hash2;
    }
};

int n, m;
set<ii> adj[MAXN];
set<edge> edges;
set<ll> all;
unordered_map<ii, int, hash_pair> mpw;
int q;

void upd(int i) {
	auto it = adj[i].begin();
	ll res = 0;
	REP (j, 0, 3) {
		if (it == adj[i].end()) return;
		res += it -> FI;
		int b = it -> SE;
		auto itb = adj[b].begin();
		bool impt = 0;
		REP (k, 0, 3) {
			if (itb == adj[b].end()) break;
			impt |= itb -> SE == i;
			itb = next(itb);
		}
		if (impt) {
			edges.insert(edge(it -> FI, i, it -> SE));
		}
		it = next(it);
	}
	all.insert(res);
}
void rem(int i) {
	auto it = adj[i].begin();
	ll res = 0;
	REP (j, 0, 3) {
		if (it == adj[i].end()) return;
		res += it -> FI;
		edges.erase(edge(it -> FI, i, it -> SE));
		it = next(it);
	}
	all.erase(res);
}
ll getans() {
	ll ans = all.empty() ? LINF : *all.begin();
	auto it = edges.begin();
	int a = it -> u, b = it -> v, w = it -> w;
	int cnt = 0;
	for (it = next(it); it != edges.end(); it = next(it)) {
		cnt++;
		assert(cnt <= 9);
		if (a == it -> u || a == it -> v || b == it -> u || b == it -> v) {
			continue;
		}
		mnto(ans, w + it -> w);
		break;
	}
	assert(cnt <= 9);
	auto ita = adj[a].begin();
	REP (i, 0, 3) {
		if (ita == adj[a].end()) break;
		if (ita -> SE != b) {
			auto itb = adj[b].begin();
			REP (j, 0, 3) {
				if (itb == adj[b].end()) break;
				if (itb -> SE != a && ita -> SE != itb -> SE) {
					mnto(ans, ita -> FI + itb -> FI);
				}
				itb = next(itb);
			}
		}
		ita = next(ita);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, m) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].insert(MP(w, v));
		adj[v].insert(MP(w, u));
		mpw[MP(u, v)] = w;
		mpw[MP(v, u)] = w;
	}
	REP (i, 1, n + 1) {
		upd(i);
	}
	scanf("%d", &q);
	printf("%lld\n", getans());
	while (q--) {
		int t, u, v; scanf("%d%d%d", &t, &u, &v);
		rem(u);
		rem(v);
		if (t == 0) {
			adj[u].erase(MP(mpw[MP(u, v)], v));
			adj[v].erase(MP(mpw[MP(u, v)], u));
		} else {
			int w; scanf("%d", &w);
			adj[u].insert(MP(w, v));
			adj[v].insert(MP(w, u));
			mpw[MP(u, v)] = w;
			mpw[MP(v, u)] = w;
		}
		upd(u);
		upd(v);
		printf("%lld\n", getans());
	}
	return 0;
}

/*
6 5
1 3 6
2 6 4
2 4 2
5 4 3
2 5 2
0
*/
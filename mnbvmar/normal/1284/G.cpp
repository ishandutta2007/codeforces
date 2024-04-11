//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

struct Matroid {
  int n;

  Matroid(int size) : n(size) {}
  virtual ~Matroid() {}

  // Returns any circuit as the subset of [X]. Returns an empty vector
  // if [X] is independent.
  virtual VI FindCircuit(const vector<int> &) {
    throw nullptr;
  }

  bool IsIndependent(const vector<int> &X) {
    return FindCircuit(X).empty();
  }
};

int H, W;
string board[30];
vector<pii> verts;
vector<pii> edges;
int ids[30][30];
vector<pii> adj[1000];
int num_edges, nverts;
bool is_in[1000];
int out_bound[1000];
vector<pair<vi, int>> bounds;
int bound_mapping[1000];

struct FU {
	vi pnt;
	FU(int n) : pnt(n) {
		iota(ALL(pnt), 0);
	}
	int Find(int v) {
		if (pnt[v] == v) { return v; }
		return pnt[v] = Find(pnt[v]);
	}
};

struct CographicMatroid : public Matroid {
	CographicMatroid() : Matroid(num_edges) {}
	virtual ~CographicMatroid() {}

	VI FindCircuit(const vector<int> &X) override {
		debug() << "cographic " << X;
		memset(is_in, 0, sizeof(bool) * num_edges);
		for (int v : X) { is_in[v] = true; }
		FU fu(nverts);
		int ncomp = nverts;
		for (int i = 0; i < num_edges; ++i) {
			if (!is_in[i]) {
				int a = fu.Find(edges[i].st);
				int b = fu.Find(edges[i].nd);
				if (a != b) {
					fu.pnt[a] = b; --ncomp;
				}
			}
		}
		if (ncomp == 1) { debug() << "ok"; return {}; }
		debug() << imie("bad") << imie(ncomp);

		vi indep;
		for (int v : X) {
			int a = fu.Find(edges[v].st);
			int b = fu.Find(edges[v].nd);
			debug() << imie(v) << imie(a) << imie(b) << imie(edges[v]);
			if (a != b && ncomp == 2) {
				indep.push_back(v);
				continue;
			}
			if (a != b) {
				fu.pnt[a] = b; --ncomp;
			}
		}
		debug() << imie(indep);
		return indep;
	}
};

struct MaxChoiceMatroid : public Matroid {
	MaxChoiceMatroid() : Matroid(num_edges) {}
	virtual ~MaxChoiceMatroid() {}

	VI FindCircuit(const vector<int> &X) override {
		debug() << "max choice" << imie(X);
		vector<vi> lists(SZ(bounds));
		for (int v : X) {
			const int where = bound_mapping[v];
			if (where == -1) { continue; }
			lists[where].push_back(v);
			if (SZ(lists[where]) > bounds[where].nd) {
				debug() << imie(lists[where]);
				return lists[where];
			}
		}
		debug() << "ok";
		return {};
	}
};

VI IntersectMatroids(Matroid *A, Matroid *B) {
  assert(A->n == B->n);
  const int n = A->n;

  vector<VI> graph;

  VI X;
  while (true) {
    for (int i = 0; i < n; ++i) {
      if (count(ALL(X), i)) { continue; }
      auto Y = X; Y.PB(i);
      if (A->IsIndependent(Y) && B->IsIndependent(Y)) { X = Y; }
    }
    //~ debug(X);
    vector<bool> is_x(n), is_a(n), is_b(n);
    for (int x : X) { is_x[x] = true; }

    graph.clear(); graph.resize(2 * n);
    queue<int> Q;
    VI dist(2 * n, 1e9), prv(2 * n, -1);

    for (int y = 0; y < n; ++y) {
      if (is_x[y]) { continue; }
      auto Y = X; Y.PB(y);
      auto circ_a = A->FindCircuit(Y);
      if (circ_a.empty()) {
        is_a[y] = true; Q.push(y + n); dist[y + n] = 0;
      } else {
        for (int x : circ_a) { graph[x].PB(y + n); }
      }
      auto circ_b = B->FindCircuit(Y);
      if (circ_b.empty()) {
        is_b[y] = true;
      } else {
        for (int x : circ_b) { graph[y + n].PB(x); }
      }
      //~ debug(y, circ_a, circ_b);
    }

    int dest = -1;

    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      if (v >= n && is_b[v - n]) { dest = v; break; }
      for (int s : graph[v]) {
        if (dist[s] > dist[v] + 1) {
          dist[s] = dist[v] + 1; prv[s] = v; Q.push(s);
        }
      }
    }
    if (dest == -1) { break; }

    while (dest != -1) {
      const int p = dest % n;
      //~ debug(p);
      is_x[p] = !is_x[p]; dest = prv[dest];
    }
    assert(count(ALL(is_x), true) == SZ(X) + 1);
    X.clear();
    for (int i = 0; i < n; ++i) {
      if (is_x[i]) { X.PB(i); }
    }
  }
  return X;
}

void Test() {
	debug() << "test";
	cin >> H >> W;
	int cnt = 0;
	verts.clear();
	for (int i = 0; i < H; ++i) {
		cin >> board[i];
		for (int j = 0; j < W; ++j) {
			ids[i][j] = -1;
			if (board[i][j] == 'O') {
				verts.emplace_back(i, j);
				ids[i][j] = cnt;
				++cnt;
			}
		}
	}

	edges.clear();

	for (int i = 0; i < cnt; ++i) {
		adj[i].clear();
	}

	int eid = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (j < W-1 && board[i][j] == 'O' && board[i][j+1] == 'O') {
				int a = ids[i][j];
				int b = ids[i][j+1];
				adj[a].emplace_back(b, eid);
				adj[b].emplace_back(a, eid);
				debug() << imie(eid) << imie(i) << imie(j) << imie(j+1);
				edges.emplace_back(a, b);
				eid++;
			}
			if (i < H-1 && board[i][j] == 'O' && board[i+1][j] == 'O') {
				int a = ids[i][j];
				int b = ids[i+1][j];
				adj[a].emplace_back(b, eid);
				adj[b].emplace_back(a, eid);
				debug() << imie(eid) << imie(i) << imie(i+1) << imie(j);
				edges.emplace_back(a, b);
				eid++;
			}
		}
	}

	num_edges = SZ(edges);
	nverts = cnt;

	bounds.clear();
	for (int i = 0; i < num_edges; ++i) {
		bound_mapping[i] = -1;
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (i == 0 && j == 0) { continue; }
			if (board[i][j] == 'O') {
				const int v = ids[i][j];
				out_bound[v] = SZ(adj[v]) - 1;
				if ((i + j) % 2 == 0) {
					--out_bound[v];
				}
				if (out_bound[v] < 0) {
					debug() << imie(i) << imie(j) << "bad";
					cout << "NO\n";
					return;
				}

				if ((i + j) % 2 == 0) {
					vi eids;
					for (auto &e : adj[v]) {
						eids.push_back(e.nd);
						bound_mapping[e.nd] = SZ(bounds);
					}
					bounds.emplace_back(eids, out_bound[v]);
					debug() << imie(eids) << imie(out_bound[v]) << imie(i) << imie(j);
				}
			}
		}
	}

	Matroid* cographic = new CographicMatroid();
	Matroid* max_choice = new MaxChoiceMatroid();

	auto inter = IntersectMatroids(cographic, max_choice);
	const int num_blocked = SZ(inter);
	const int need_blocked = num_edges - (nverts - 1);
	debug() << imie(num_blocked) << imie(need_blocked);
	assert(num_blocked <= need_blocked);

	if (num_blocked < need_blocked) {
		delete cographic;
		delete max_choice;
		cout << "NO\n";
		return;
	}

	vector<string> ans(2 * H - 1, string(2 * W - 1, ' '));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			ans[2*i][2*j] = board[i][j];
		}
	}

	for (auto &E : edges) {
		int a = E.st;
		int b = E.nd;
		auto [r1, c1] = verts[a];
		auto [r2, c2] = verts[b];

		if (r1 == r2) {
			ans[2*r1][2*min(c1,c2)+1] = 'O';
		} else {
			ans[2*min(r1,r2)+1][2*c1] = 'O';
		}
	}

	for (int v : inter) {
		int a = edges[v].st;
		int b = edges[v].nd;
		auto [r1, c1] = verts[a];
		auto [r2, c2] = verts[b];
		if (r1 == r2) {
			ans[2*r1][2*min(c1,c2)+1] = ' ';
		} else {
			ans[2*min(r1,r2)+1][2*c1] = ' ';
		}
	}

	cout << "YES\n";
	for (auto s : ans) {
		cout << s << "\n";
	}
	

	delete cographic;
	delete max_choice;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int t;
	cin >> t;
	while (t--) { Test(); }
}
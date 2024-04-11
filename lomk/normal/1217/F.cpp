/*input
5 9
1 1 2
1 1 3
2 3 2
1 2 4
2 3 4
1 2 4
2 3 4
1 1 3
2 4 3

*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
#define debug(x...) {cout << "[" << #x << "] = "; print(x);}
// const int N =;
void print() {cout << endl;}
template<typename T, typename... Ts>
void print(const T& value, const Ts&... values) {
	cout << value << ' '; print(values...);
}

struct dsu {
	vector<int> par, rank;
	vector<pair<int*, int> > where;
	void init(int n) {
		par.assign(n + 5, 0); rank.assign(n + 5, 1);
		for (int i = 0; i < n + 5; i++) par[i] = i;
	}
	int find(int x) {
		for (; x != par[x]; x = par[x]);
		return x;
	}
	void uni(int x, int y, bool saved) {
		x = find(x); y = find(y);
		if (x != y) {
			if (rank[x] > rank[y]) swap(x, y);
			if (saved) {
				where.push_back({&par[x], par[x]});
				where.push_back({&rank[y], rank[y]});
				where.push_back({&rank[x], rank[x]});
			}
			rank[y] += rank[x]; rank[x] = 0;
			par[x] = y;
		}
	}
	void rollback() {
		rloop(i, (int)where.size() - 1, 0) {
			*where[i].fi = where[i].se;
		}
		where.clear();
	}
};

int n, m;
struct Query {
	int type, u, v;
	Query decrypt(int last) const {
		auto [tu, tv] = minmax({(u + last - 1) % n + 1, (v + last - 1) % n + 1});
		return {type, tu, tv};
	}
};
vector<Query> query;
int S;
int glast = 0;

vector<pair<int, int> > createEdge(vector<Query> &inp) {
	vector<pair<int, int> > ret; ret.reserve(inp.size() * 2);
	for (const auto &cur : inp) {
		if (cur.type == 2) continue;
		auto rec = cur.decrypt(0);
		ret.push_back({rec.u, rec.v});
		rec = cur.decrypt(1);
		ret.push_back({rec.u, rec.v});
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	S = sqrt(m);
	loop(i, 1, m) {
		int type, u, v;
		cin >> type >> u >> v;
		query.push_back({type, u, v});
	}
	vector<Query> pen;
	set<pair<int, int> > proc;
	vector<int> order;
	auto clearPen = [&]() {
		dsu d; d.init(n);

		auto more = createEdge(pen);
		set<pair<int, int> > newEdge;
		for (const auto &edge : more) {
			if (auto it = proc.erase(edge); it)
				newEdge.insert(edge);
		}
		for (const auto &edge : proc) d.uni(edge.fi, edge.se, 0);

		for (const auto &fquery : pen) {
			auto tquery = fquery.decrypt(glast);
			// print(tquery.type, tquery.u, tquery.v);
			// if (tquery.type == 2 && tquery.u == 2 && tquery.v == 3) {
			// 	cout << proc << endl;
			// 	cout << newEdge << endl;
			// }
			if (tquery.type == 2) {
				for (const auto &edge : newEdge) d.uni(edge.fi, edge.se, 1);
				glast = (d.find(tquery.u) == d.find(tquery.v));
				order.push_back(glast);
				d.rollback();
			}
			else {
				if (auto [it, can] = newEdge.insert(mp(tquery.u, tquery.v)); can == false)
					newEdge.erase(it);
			}
		}
		proc.merge(newEdge);
		pen.clear();
	};
	for (const auto &cur : query) {
		pen.push_back(cur);
		if (pen.size() == S) clearPen();
	}
	clearPen();
	for (auto it : order) cout << it;
}
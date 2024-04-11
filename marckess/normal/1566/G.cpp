#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef tuple<int, int, int> iii;

const int MX = 100005;
int n, m, q;
set<iii> ari, best;
set<ii> in[MX];
map<ii, int> ww;
multiset<ll> tri;

void clear () {
	ari.clear();
	for (int i = 1; i <= n; i++)
		in[i].clear();
	tri.clear();
	best.clear();
	ww.clear();
}

bool valid (int u, int v) {
	auto it = in[u].begin();
	
	forn (i, 3) {
		if (it->se == v)
			return 1;
		
		it++;
		if (it == in[u].end())
			break;
	}
	
	return 0;
}

#define update(op, op2, u) { \
	if (in[u].size()) {\
		if (in[u].size()) { \
			auto it = in[u].begin(); \
			\
			forn (i, 3) { \
				if (op2 || (valid(u, it->se) && valid(it->se, u))) \
					best.op({it->fi, u, it->se}); \
				\
				it++; \
				if (it == in[u].end()) \
					break; \
			} \
		} \
		\
		if (in[u].size() >= 3) { \
			ll s = 0; \
			auto it = in[u].begin(); \
			\
			forn (i, 3) { \
				s += it->fi; \
				it++; \
			} \
			tri.op(s); \
		} \
	} \
}

#define upd(op, u, v, w) { \
	ari.op({w, u, v}); \
	\
	update(erase, 1, u); update(erase, 1, v); \
	in[u].op({w, v});  in[v].op({w, u}); \
	update(insert, 0, u); update(insert, 0, v); \
}

void insert(int u, int v, int w) {
	if (u > v) swap(u, v);
	ww[{u, v}] = w;
	upd(insert, u, v, w);
}

void erase(int u, int v) {
	if (u > v) swap(u, v);
	int w = ww[{u, v}];
	ww.erase({u, v});
	
	upd(erase, u, v, w);
}

bool valid (vi v) {
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	return v.size() == 4;
}

void query() {
	ll res = 1e18;
	
	if (tri.size())
		res = min(res, *tri.begin());
	
	const auto& [w, u, v] = *ari.begin();
	
	for (auto it = best.begin(); it != best.end();) {
		auto nex = it; nex++;
		const auto& [w2, u2, v2] = *it;
		
		if (!valid(u2, v2) || !valid(v2, u2)) {
			best.erase(it);
			it = nex;
			continue;
		}
		
		if (valid({u, v, v2, u2})) {
			res = min(res, 0ll + w + w2);
			break;
		}
		
		it = nex;
	}
	
	{
		auto it = in[u].begin();
		forn (i, 3) {
			auto jt = in[v].begin();
			
			forn (j, 3) {
				if (valid({u, v, it->se, jt->se}))
					res = min(res, 0ll + it->fi + jt->fi);
				
				jt++;
				if (jt == in[v].end())
					break;
			}
			
			it++;
			if (it == in[u].end())
				break;
		}
	}
	
	cout << res << endl;
}

void main_() {
	cin >> n >> m;
	clear();
	
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		insert(u, v, w);
	}
	
	query();
	
	cin >> q;
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		
		if (t) {
			int w;
			cin >> w;
			insert(u, v, w);
		} else {
			erase(u, v);
		}
		
		query();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
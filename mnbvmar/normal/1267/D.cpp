#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin() ,(x).end()
#define st first
#define nd second
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;

template <typename TH> void _dbg(const char *s, TH h) {
	cerr << s << "=" << h << "\n";
}
template <typename TH, typename ...TA> void _dbg(const char *s, TH h, TA... a) {
	while (*s != ',') cerr << *s++;
	cerr << "=" << h << ",";
	_dbg(s+1, a...);
}

template <typename T> ostream &operator<<(ostream &os, vector<T> V) {
	os <<"[";
	for (auto v:V) os << v << ",";
	return os << "]";
}
template <typename L, typename R> ostream &operator<<(ostream &os, pair<L,R> V) {
	return os << "(" << V.st << "," << V.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int Read() {
	int a, b, c;
	cin >> a >> b >> c;
	return a * 4 + b * 2 + c;
}

int n;
vi need_deploy;
vi passes;

vi parents[8];
vi children[8];
bool has_any[8];
map<pii, vi> samples;
vi needing[8];

int root;
bool vis[8];

bool Dfs(int v) {
	vis[v] = true;
	for (int s : children[v]) {
		if (s == root) { return false; }
		if (!vis[s] && !Dfs(s)) { return false; }
	}
	return true;
}

void Check() {
	for (int i = 0; i < 8; ++i) {
		children[i].clear();
	}
	for (int i = 0; i < 8; ++i) {
		for (int v : parents[i]) {
			children[v].push_back(i);
		}
	}

	for (int i = 0; i < 8; ++i) {
		fill(vis, vis + 8, false);
		if (!Dfs(i)) { return; }
	}

	#ifdef LOCAL
	for (int i = 1; i <= 7; ++i) {
		cerr << i << ":" << parents[i] << ", ";
	}
	cerr << "\n";
	#endif

	for (int i = 1; i <= 7; ++i) {
		if (__builtin_popcount(i) == 2 && SZ(parents[i]) == 2) {
			if (!children[i].empty()) {
				return;
			}
		}
	}

	Dfs(7);
	for (int i = 1; i < 8; ++i) {
		if (has_any[i] != vis[i]) {
			debug("1", i);
			return;
		}
		if (i < 7 && (!parents[i].empty()) != vis[i]) {
			debug("2", i);
			return;
		}
		bool in_graph = i == 7 || !parents[i].empty() || !children[i].empty();
		if (in_graph != vis[i]) {
			debug("3", i);
			return;
		}
	}

	#ifdef LOCAL
	for (int i = 1; i <= 7; ++i) {
		cerr << i << ":" << parents[i] << ", ";
	}
	cerr << "\n";
	#endif

	map<pii, vi> bringer;
	vector<vi> mneed(8, vi(8));

	for (int i = 1; i < 8; ++i) {
		for (int j : children[i]) {
			if (__builtin_popcount(i) < __builtin_popcount(j)) {
				bringer[pii(i, j)].push_back(needing[i][0]);
				continue;
			}
			if (!samples.count(pii(i, j))) {
				if (__builtin_popcount(j) == 2) {
					int a = j & (j - 1);
					int b = j ^ a;
					if (samples.count(pii(i, a)) && samples.count(pii(i, b))) {
						bringer[pii(i, j)].push_back(samples[pii(i, a)][0]);
						bringer[pii(i, j)].push_back(samples[pii(i, b)][0]);
						mneed[i][a] = 1;
						mneed[i][b] = 1;
						continue;
					}
				}
				return;
			}
			bringer[pii(i, j)].push_back(samples[pii(i, j)][0]);
			mneed[i][j] = true;
		}
	}

	vi copier(8, -1);
	for (int i = 1; i < 7; ++i) {
		//~ if (__builtin_popcount(i) > 1) {
			//~ for (int j : children[i]) { ++mneed[j]; }
		//~ }
		for (int j = 0; j < 8; ++j) {
			if (SZ(samples[pii(i, j)]) > mneed[i][j]) {
				copier[i] = samples[pii(i, j)][mneed[i][j]];
				break;
			}
		}
	}
	copier[7] = 0;

	vector<pii> edges;
	vector<bool> has_ct(n, true);

	for (int i = 0; i < n; ++i) {
		if (__builtin_popcount(need_deploy[i]) <= 1) {
			has_ct[i] = false;
		}
	}
	
	for (int i = 1; i <= 7; ++i) {
		if (copier[i] != -1) {
			const int v = copier[i];
			has_ct[v] = false;
			for (int s : needing[i]) {
				if (s != v) {
					edges.emplace_back(v, s);
				}
			}
		}

		for (int j : children[i]) {
			assert(bringer.count(pii(i, j)));
			for (int v : bringer[pii(i, j)]) {
				if (__builtin_popcount(i) != 1) {
					assert(has_ct[v]);
				}
				if (copier[j] != -1) {
					edges.emplace_back(v, copier[j]);
				} else {
					for (int s : needing[j]) {
						edges.emplace_back(v, s);
					}
				}
			}
		}
	}

	if (SZ(edges) > 264) { return; }

	cout << "Possible\n";
	for (bool v : has_ct) { cout << int(v) << " "; }
	cout << "\n";
	cout << SZ(edges) << "\n";
	for (auto [a, b] : edges) {
		cout << a+1 << " " << b+1 << "\n";
	}
	exit(0);
}

void Brute(int idx) {
	if (idx == 7) {
		return Check();
	}

	for (int mask = idx + 1; mask < 8; ++mask) {
		if ((mask & idx) == idx) {
			parents[idx] = vi{mask};
			Brute(idx + 1);
		}
	}

	if (idx == 3) {
		parents[idx] = vi{1, 2};
		Brute(idx+1);
	} else if (idx == 5) {
		parents[idx] = vi{4, 1};
		Brute(idx+1);
	} else if (idx == 6) {
		parents[idx] = vi{4, 2};
		Brute(idx+1);
	}

	parents[idx].clear();
	Brute(idx+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n;
	need_deploy.resize(n);
	passes.resize(n);
	for (int i = 0; i < n; ++i) {
		need_deploy[i] = Read();
		has_any[need_deploy[i]] = true;
	}
	for (int i = 0; i < n; ++i) {
		passes[i] = Read();
	}

	
	for (int i = 0; i < n; ++i) {
		if (!need_deploy[i]) { continue; }
		samples[pii(need_deploy[i], need_deploy[i] & passes[i])].push_back(i);
		needing[need_deploy[i]].push_back(i);
		//~ avails[need_deploy[i]].insert(need_deploy[i] & passes[i]);

		//~ if (i && need_deploy[i] == 7) {
			//~ has_ct[i] = true;
			//~ edges.emplace_back(0, i);
		//~ }
	}

	Brute(1);
	cout << "Impossible\n";

	//~ map<int, set<int>> avails;
	//~ vector<pii> edges;
	//~ vi has_ct(n);

	//~ has_ct[0] = true;

	//~ for (int x : {3, 5, 6}) {
		//~ avails[x].insert(-1);
	//~ }

	//~ for (int idx3 : avails[3]) for (int idx5 : avails[5]) for (int idx6 : avails[6]) {
		
	//~ }
}
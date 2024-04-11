#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}
const int maxn = 200100;

vector <int> graf[maxn], revgraf[maxn], sccgraf[maxn], conn[maxn];
int neighboring_layer[maxn], layer[maxn];
int sccdeg[maxn];
bool odw[maxn];
int scc[maxn], n, m;

inline void add(int from, int to) {
	graf[from].push_back(to);
	revgraf[to].push_back(from);
}

void inspect(int node, vector <int> &nodes) {
	odw[node] = true;
	nodes.push_back(node);
	
	for (auto u : graf[node]) {
		if (!odw[u]) inspect(u, nodes);
	}
	
	for (auto u : revgraf[node]) {
		if (!odw[u]) inspect(u, nodes);
	}
}

void dfs(int x, vector <int> &top) {
	odw[x] = 1;
	for (auto u : graf[x])
		if (!odw[u]) dfs(u, top);
		
	top.push_back(x);
}

void rdfs(int x, int &sc) {
	odw[x] = 1;
	scc[x] = sc;
	conn[sc].push_back(x);
	
	for (auto u : revgraf[x])
		if (!odw[u]) rdfs(u, sc);
}

void do_greedy(int curr, int total, vector <int> &greedy) {
	if (curr > total) return;
	for (auto u : conn[curr]) greedy.push_back(u);
	int nast_spojna = total + 1;
	for (auto u : conn[curr])
		for (auto v : graf[u])
			if (scc[v] > curr) nast_spojna = min(nast_spojna, scc[v]);
	
	do_greedy(nast_spojna, total, greedy); 
}

bool check(vector <int> &cand) {
	vector <bool> req(2 * n, 0);
	for (auto u : cand) req[u] = 1;
	for (int i=0; i<2*n; i+=2) {
		if (!req[i] && !req[i+1]) return false;
	}
	
	return true;
}

set <PII> edges;
inline bool edge(int x, int y) {
	return (edges.find({x, y}) != edges.end());
}

inline int neg(int x) {
	if (x&1) return --x;
	return ++x;
}

void solve_component(vector <int> &nodes) {
	assert(sz(nodes) % n == 0);
	if (sz(nodes) < n) return; //there definitely isn't a way to go through n nodes if we have less nodes than n
	for (int i=0; i<2*n; ++i) conn[i].clear(), sccgraf[i].clear(), odw[i] = 0, scc[i] = 0, sccdeg[i] = 0, layer[i] = 0;
	vector <int> top = {};
	for (auto u : nodes) 
		if (!odw[u]) dfs(u, top);
	fill(odw, odw+2*n, false);
	reverse(top.begin(), top.end());

	int sc = 0;
	for (auto u : top) {
		if (!odw[u]) {
			++sc;
			rdfs(u, sc);
			//debug("SCC number: ", sc);
			//for (auto nd : conn[sc]) cerr << nd << ' ';
			//cerr << endl;
			 
		}
	}
	
	edges.clear();
	for (int i=1; i<=sc; ++i)
		for (auto u : conn[i])
			for (auto v : graf[u]) {
				PII ed = {i, scc[v]};
				if (i < scc[v] && !edge(i, scc[v])) {
					edges.insert(ed);
					sccdeg[scc[v]]++;
					sccgraf[i].push_back(scc[v]);
				}
			}
	
	//we've got a clear SCC graph without duplicate edges
	vector <vector <int> > layers(sc + 1);
	for (int i=1; i<=sc; ++i) layers[i] = {};
	
	FOR(i, 1, sc) {
		sort(conn[i].begin(), conn[i].end());
		neighboring_layer[i] = inf;
		if (!sccdeg[i]) {
			layer[i] = 1;
			layers[1].push_back(i);
		}
	}
	
	//find layers
	int vis = 0, step = 1;
	while (vis < sc) {
		assert(sz(layers[step]) <= 2);
		for (auto nodeInLayer : layers[step]) {
			++vis;
			for (auto endpoint : sccgraf[nodeInLayer]) {
				sccdeg[endpoint]--;
				if (sccdeg[endpoint] == 0) {
					layers[step + 1].push_back(endpoint);
					layer[endpoint] = step + 1;
				}
			}
		}
		
		step += 1;
	}
	
	for (auto u : edges) {
		assert(layer[u.e1] < layer[u.e2]);
		debug(conn[u.e1][0], conn[u.e2][0]);
		neighboring_layer[u.e1] = min(neighboring_layer[u.e1], layer[u.e2]);
	}
	
	step--;
	
	int fst = layers[1][0], sec = layers[1][0], half = (step + 1) / 2;
	if (sz(layers[1]) > 1) sec = layers[1][1];
	FOR(i, 1, step) {
		cout << "Layer: " << i << ' ';
		for (auto u : layers[i]) cout << conn[u] << ' ';
		cout << endl;
	}
	
	if (sz(nodes) == n) { //the easy case of all nodes connected
		vector <int> greedy = {};
		FOR(i, 1, step) {
			if (sz(layers[i]) > 1) return;
			for (auto u : conn[layers[i][0]]) greedy.push_back(u);
		}

		assert(check(greedy));
		OUT("YES");
	}
	
	vector <int> vis_first = {fst}, vis_second = {sec};
	while (layer[fst] < step && layer[sec] < step) {
		///debug(conn[fst][0], conn[sec][0]);
		if (neighboring_layer[fst] == neighboring_layer[sec]) {
			int next_layer = neighboring_layer[fst];
			//meetup detection
			int e1 = 0, e2 = 0;
			for (auto next_node : layers[next_layer]) {
				e1 += edge(fst, next_node);
				e2 += edge(sec, next_node);
			}
			int nsz = (int)layers[next_layer].size();
			if (neighboring_layer[fst] > half && e1 == nsz && e2 == nsz) {
				///debug(conn[fst][0], conn[sec][0], neighboring_layer[fst], layer[fst]);
				//here is a meeting point. Hence, we can append appropriate part of sec to first!!!
				
				map <int, bool> next_step;
				for (auto u : sccgraf[fst]) {
					//next_step[u] = 1;
					next_step[neg(conn[u][0])] = 1;
				}

				
				while (!vis_second.empty()) {
					int last_visited = vis_second.back();
					if (next_step[conn[last_visited][0]]) break;
					vis_second.pop_back();
				}
				
				///debug(vis_second);
				///for (auto u : vis_second) cout << conn[u][0] << ' ';
				///cout << endl;
				//now these nodes are the same, we can perform the search
				while (!vis_second.empty()) {
					int last_visited = vis_second.back();
					vis_second.pop_back();
					bool found = false;
					for (auto try_node : sccgraf[fst]) {
						if (conn[try_node][0] == neg(conn[last_visited][0])) {
							found = true;
							fst = try_node;
							vis_first.pb(fst);
						}
					}
					
					assert(found);
				}
				
				break; //now we have reached last node
			}

			if (sz(layers[next_layer]) == 1) { //if both have edges here then surely there must be an edge between both
				assert(edge(fst, layers[next_layer][0]));
				assert(edge(sec, layers[next_layer][0]));
				fst = layers[next_layer][0];
				sec = layers[next_layer][0];
			}
			else if (edge(fst, layers[next_layer][0]) && edge(sec, layers[next_layer][1])) { //we can move once in straight line
				fst = layers[next_layer][0];
				sec = layers[next_layer][1];
			}
			else if (edge(fst, layers[next_layer][1]) && edge(sec, layers[next_layer][0])) { //we can move once diagonally
				fst = layers[next_layer][1];
				sec = layers[next_layer][0];
			}
			else { //this should NOT happen
				assert(1 == 0);
			}
			
			vis_first.pb(fst);
			vis_second.pb(sec);
		}
		else if (neighboring_layer[fst] < neighboring_layer[sec]) {
			int next_layer = neighboring_layer[fst];
			if (sz(layers[next_layer]) == 2) OUT("NO");
			fst = layers[next_layer][0];
			vis_first.pb(fst);
		}
		else if (neighboring_layer[sec] < neighboring_layer[fst]) {
			int next_layer = neighboring_layer[sec];
			if (sz(layers[next_layer]) == 2) OUT("NO");
			sec = layers[next_layer][0];
			vis_second.pb(sec);
		}
	}

	vector <int> greedy = {};
	for (auto u : vis_first)
		for (auto v : conn[u]) greedy.pb(v);
	
	//for (auto u : vis_first) cout << conn[u][0] << ' ';
	//cout << endl;
	assert(check(greedy));
	//if (check(greedy)) {
	{
		cout << "YES\n";
		//debug(greedy);
		exit(0);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << a + b << ' ' << endl;
	}
}
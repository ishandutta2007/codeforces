#pragma comment (linker, "/STACK:128000000") 
//#include "testlib.h" 
#include <cstdio> 
#include <cassert> 
#include <algorithm> 
#include <iostream> 
#include <memory.h> 
#include <string> 
#include <vector> 
#include <set> 
#include <map> 
#include <cmath> 
#include <bitset> 
//#include <unordered_map> 
//#include <unordered_set> 
#include <ctime> 
#include <stack> 
#include <queue> 
using namespace std;
//#define FILENAME "" 
#define mp make_pair 
#define all(a) a.begin(), a.end() 
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1; 

bool doing = true;

int main() {
#ifdef AIM
	freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout); 
#else 
	//freopen("input.txt", "r", stdin); 
	//freopen("output.txt", "w", stdout); 
	//freopen(FILENAME".in", "r", stdin); 
	//freopen(FILENAME ".out", "w", stdout); 
#endif 
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": "; 
		solve();
		//++timer; 
	}

#ifdef room111 
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif 

	return 0;
}

//BE CAREFUL: IS INT REALLY INT? 

//#define int li 

void precalc() {


}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

vector<vector<pair<int, int>>> dis;
vector<vector<vector<int>>> has;

vector<char> done;

vector<int> res;

void erase(vector<int>& cur, int val) {
	for (auto it = cur.begin(); it != cur.end(); ++it) {
		if (*it == val) {
			cur.erase(it);
			return;
		}
	}
	assert(false);
}

void dfs(int v) {
	if (res[v] != -1) {
		return;
	}
	assert(has[v][0].size() == 0 || has[v][1].size() == 0);
	bool have = false;
	for (int j = 0; j < 2; ++j) {
		if (!have && has[v][j].size() == 0) {
			res[v] = j ^ 1;
			have = true;
			continue;
		}
		vector<int> now = has[v][j];
		for (int num : now) {
			if (done[num]) {
				continue;
			}
			done[num] = true;
			for (auto liter : dis[num]) {
				int var = liter.first;
				int type = liter.second;
				erase(has[var][type], num);
				if (has[var][type].empty()) {
					dfs(var);
				}
			}
		}
	}
}

vector<vector<int>> gr;
vector<int> mt;
vector<int> revmt;
vector<char> used;
bool try_kuhn(int v) {
	if (used[v]) {
		return false;
	}
	used[v] = true;
	for (size_t i = 0; i<gr[v].size(); ++i) {
		int to = gr[v][i];
		if (mt[to] == -1 || try_kuhn(mt[to])) {
			mt[to] = v;
			revmt[v] = to;
			return true;
		}
	}
	return false;
}

void solve() {
	int n, vars;
	scanf("%d%d", &n, &vars);
	dis.resize(n);
	has.assign(vars, vector<vector<int>>(2));
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		dis[i].resize(k);
		for (int j = 0; j < k; ++j) {
			int cur;
			scanf("%d", &cur);
			int type = 1;
			if (cur < 0) {
				type = 0;
				cur = -cur;
			}
			--cur;
			dis[i][j] = make_pair(cur, type);
			has[cur][type].push_back(i);
		}
	}

	done.assign(n, false);

	res.assign(vars, -1);
	for (int i = 0; i < vars; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (has[i][j].empty()) {
				dfs(i);
			}
		}
	}
	
	gr.resize(n);

	for (int i = 0; i < n; ++i) {
		if (done[i]) {
			continue;
		}
		for (auto item : dis[i]) {
			gr[i].push_back(item.first);
		}
	}

	mt.assign(vars, -1);
	revmt.assign(n, -1);
	for (int run = 1; run;) {
		run = 0;
		used.assign(n, false);
		for (int v = 0; v < n; ++v) {
			if (!done[v] && revmt[v] == -1 && try_kuhn(v)) {
				run = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (done[i]) {
			continue;
		}
		int cur = revmt[i];
		if (cur == -1) {
			cout << "NO\n";
			return;
		}
		int type = -1;
		for (auto item : dis[i]) {
			if (item.first == cur) {
				type = item.second;
				break;
			}
		}
		assert(type != -1);
		res[cur] = type;
	}

	cout << "YES\n";
	for (int i = 0; i < vars; ++i) {
		if (res[i] == -1) {
			res[i] = 0;
		}
		cout << res[i];
	}
	cout << "\n";

}
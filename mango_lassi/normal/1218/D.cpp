#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 1e5;
const int K = 50;
const int H = 17; // 2^17 > 1e5
vector<pair<int, int>> conns[N];
vector<int> cycles[K];
int visited[N];

ll modInv(ll a, ll b = MOD - 2) {
	if (b & 1) return a * modInv(a, b ^ 1) % MOD;
	if (b == 0) return 1;
	return modInv(a*a % MOD, b >> 1);
}
int TI = modInv(1<<H);

// res[k] = \sum_{i,j : i^j == k} a[i] b[j]
// overflows if n res[i] overflows
void xorTF(vector<int>& v) {
	for (int b = 1; b < v.size(); b *= 2) {
		for (int i = 0; i < v.size(); ++i) {
			if (i & b) continue;
			int ri = v[i^b];
			v[i^b] = v[i] - ri;
			v[i] = v[i] + ri;
			if (v[i^b] < 0) v[i^b] += MOD;
			if (v[i] >= MOD) v[i] -= MOD;
		}
	}
}
vector<int> xorConv(vector<int> a, vector<int> b) {
	xorTF(a); xorTF(b);
	for (int i = 0; i < a.size(); ++i) a[i] = (ll)a[i]*b[i] % MOD;
	xorTF(a);
	for (int& v : a) v = (ll)v * TI % MOD;
	return a;
}

pair<int, int> dfs(int i, int p, int& cc) {
	visited[i] = visited[p] + 1;
	pair<int, int> res = {-1, -1};
	for (auto pr : conns[i]) {
		int t = pr.first;
		if (t == p) continue;
		if (visited[t]) {
			if (visited[t] < visited[i]) {
				res = {t, cc};
				cycles[cc].resize(1<<H, 0);
				// cycles[cc][0] = 1; // do we need to have a spanning tree?
				++cycles[cc][pr.second];
				++cc;
			}
		} else {
			auto sub = dfs(t, i, cc);
			if (sub.first != -1) {
				res = sub;
				++cycles[res.second][pr.second];
			}
		}
	}
	if (res.first == i) res = {-1, -1};
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int xr = 0; 
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		conns[a].push_back({b, w});
		conns[b].push_back({a, w});
		xr ^= w;
	}

	int cc = 0; // <= 42
	dfs(0, 0, cc);

	vector<int> res(1<<H, 0);
	res[0] = 1;
	vector<int> can = res;

	for (int i = 0; i < cc; ++i) {
		res = xorConv(res, cycles[i]);
		can = xorConv(can, cycles[i]);
		for (int& v : can) v = min(v, 1);
	}
	for (int j = 0; j < (1<<H); ++j) {
		if (can[j ^ xr]) {
			cout << j << ' ' << res[j ^ xr] << '\n';
			break;
		}
	}
}
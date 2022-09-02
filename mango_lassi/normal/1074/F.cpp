#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;

struct MinSeg {
	const int INF = 1e9;

	int h;
	vector<pair<int, int>> seg;
	vector<int> tag;

	pair<int, int> join(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return {a.first, a.second + b.second};
		else return min(a, b);
	}

	void update(int i) {
		seg[i] = join(seg[2*i], seg[2*i+1]);
	}

	void push(int i) {
		if (tag[i] == 0) return;
		seg[i].first += tag[i];
		if (i < h) {
			tag[2*i] += tag[i];
			tag[2*i+1] += tag[i];
		}
		tag[i] = 0;
	}

	void init(const vector<int>& vals) {
		int n = vals.size();
		h = 1;
		while(h < n) h <<= 1;

		seg.resize(2*h);
		tag.resize(2*h, 0);
		for (int i = 0; i < n; ++i) seg[i + h] = {vals[i], 1};
		for (int i = n; i < h; ++i) seg[i + h] = {INF, 0};
		for (int i = h-1; i > 0; --i) update(i);
	}

	pair<int, int> get(int a, int b, int i = 1, int ia = 0, int ib = -1) {
		if (ib == -1) ib = h-1;

		push(i);
		if (b < ia || ib < a) return {INF, 0};
		if (a <=ia && ib <=b) return seg[i];
		int mid = (ia + ib) >> 1;
		return join(get(a, b, 2*i, ia, mid), get(a, b, 2*i+1, mid+1, ib));
	}

	void add(int a, int b, int v, int i = 1, int ia = 0, int ib = -1) {
		if (ib == -1) ib = h-1;

		push(i);
		if (b < ia || ib < a) return;
		if (a <=ia && ib <=b) {
			tag[i] += v;
			push(i);
		} else {
			int mid = (ia + ib) >> 1;
			add(a, b, v, 2*i, ia, mid);
			add(a, b, v, 2*i+1, mid+1, ib);
			update(i);
		}
	}
};

const int N = 1<<18;
const int L = 18;
vector<int> conns[N];
int siz[N];
int dep[N];
int par[N][L];

int ord[N];
vector<int> seq1;

void dfs(int i, int p) {
	siz[i] = 1;
	dep[i] = dep[p] + 1;
	par[i][0] = p;

	ord[i] = seq1.size();
	seq1.push_back(i);
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs(t, i);
		siz[i] += siz[t];
	}
}

int moveUp(int i, int d) {
	for (int l = 0; l < L; ++l) {
		if (d & (1<<l)) i = par[i][l];
	}
	return i;
}

int getLca(int a, int b) {
	if (dep[b] < dep[a]) swap(a, b);
	if (dep[a] < dep[b]) b = moveUp(b, dep[b] - dep[a]);
	if (a == b) return a;

	for (int l = L-1; l >= 0; --l) {
		if (par[a][l] != par[b][l]) {
			a = par[a][l];
			b = par[b][l];
		}
	}
	return par[a][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		
		conns[a].push_back(b);
		conns[b].push_back(a);
	}


	// Euler tour transform
	dfs(0, 0);
	// Jump tree
	for (int l = 1; l < L; ++l) {
		for (int i = 0; i < n; ++i) {
			par[i][l] = par[par[i][l-1]][l-1];
		}
	}
	
	vector<int> zeroes(n, 0);
	MinSeg seg;
	seg.init(zeroes);
	
	set<ll> actives;
	for (; q > 0; --q) {
		int a, b;
		cin >> a >> b;
		--a; --b;

		// Put them into unique order
		if (ord[b] < ord[a]) swap(a, b);
		ll code = a + (ll)n * b;

		int mult = 1;
		if (actives.find(code) != actives.end()) {
			mult = -1;
			actives.erase(code);
		} else {
			actives.insert(code);
		}

		int lca = getLca(a, b);
		if (lca != a) {
			seg.add(0, n-1, mult);
			seg.add(ord[a], ord[a] + siz[a]-1, -mult);
			seg.add(ord[b], ord[b] + siz[b]-1, -mult);
		} else {
			int c = moveUp(b, dep[b] - dep[a] - 1);
			seg.add(ord[c], ord[c] + siz[c]-1, mult);
			seg.add(ord[b], ord[b] + siz[b]-1, -mult);
		}


		auto sub = seg.get(0, n-1);
		if (sub.first == 0) cout << sub.second << '\n';
		else cout << "0\n";
	}
}
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct Node { int v, p; };

struct DSU {
	int N;
	vector<int> V;
	vector<vector<Node>> W;

	void init(int n) {
		N = n;
		V.resize(N); W.resize(N);
		rep(i, N) V[i] = i;
		rep(i, N) W[i] = { { i,0 } };
	}
	int root(int a) { return (V[a] == a) ? a : (V[a] = root(V[a])); }
	void unite(int a, int b, int t) {
		a = root(a); b = root(b);
		if (W[a].size() < W[b].size()) {
			V[a] = b;
			W[b].back().p = t;
			for (Node& w : W[a]) W[b].push_back(w);
			W[a].clear();
		}
		else {
			V[b] = a;
			W[a].back().p = t;
			for (Node& w : W[b]) W[a].push_back(w);
			W[b].clear();
		}
	}
};

struct RMQ {
	int N;
	vector<pair<int,int>> V;
	void init(vector<int>& v) {
		N = 1; while (N < v.size()) N *= 2;
		V.resize(N * 2);
		rep(i, v.size()) V[N + i] = { v[i],i };
		for (int i = N - 1; i >= 1; i--) V[i] = max(V[i * 2], V[i * 2 + 1]);
	}
	void upd(int p, int x) {
		p += N; V[p].first = x;
		while (p != 1) {
			p /= 2;
			V[p] = max(V[p * 2], V[p * 2 + 1]);
		}
	}
	pair<int, int> query(int l, int r, int a = 0, int b = 0, int i = -1) {
		if (i == -1) { a = 0; b = N; i = 1; }
		if (r <= a || b <= l) return { 0,0 };
		if (l <= a && b <= r) return V[i];
		auto q1 = query(l, r, a, (a + b) / 2, i * 2);
		auto q2 = query(l, r, (a + b) / 2, b, i * 2 + 1);
		return max(q1, q2);
	}
};

struct Edge { int u, v, p; };

const int xN = 200000;

int N, M, Q;
int A[xN];
vector<Edge> J;

vector<pair<int, int>> query;

RMQ G;

bool farbreaktime(int a, int b) {
	return J[a].p > J[b].p;
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	rep(i, N) scanf("%d", &A[i]);
	J.resize(M);
	rep(i, M) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		J[i] = { u,v,Q };
	}

	rep(i, Q) {
		int c, v; scanf("%d%d", &c, &v); v--;
		query.push_back({ c, v });
		if (c == 2) {
			J[v].p = i;
		}
	}

	vector<Node> xarr;

	{
		DSU dsu; dsu.init(N);
		vector<int> I(M); rep(i, M) I[i] = i;
		sort(I.begin(), I.end(), farbreaktime);
		rep(i, M) {
			Edge& j = J[I[i]];
			if (dsu.root(j.u) == dsu.root(j.v)) j.p = -1;
			else dsu.unite(j.u, j.v, j.p);
		}
		rep(i, J.size()) if (J[i].p == -1) { swap(J[i], J.back()); J.pop_back(); i--; }
		rep(i, N) if (dsu.root(0) != dsu.root(i)) {
			dsu.unite(0, i, 0);
			J.push_back({ 0,i,0 });
		}
		xarr = dsu.W[dsu.root(0)];
	}

	vector<vector<int>> elim(Q + 1);
	elim[0] = { 0,N };
	rep(i, N - 1) elim[xarr[i].p].push_back(i + 1);

	vector<int> P(N);
	rep(i, N) P[xarr[i].v] = i;

	vector<int> A2(N);
	rep(i, N) A2[i] = A[xarr[i].v];

	RMQ rmq; rmq.init(A2);

	set<int> elimed;

	rep(i, Q) {
		for (int p : elim[i]) elimed.insert(p);
		int c = query[i].first;
		int v = query[i].second;
		if (c == 1) {
			int p = P[v];
			int rb = *elimed.upper_bound(p);
			int lb = *--elimed.upper_bound(p);
			auto q = rmq.query(lb, rb);
			rmq.upd(q.second, 0);
			printf("%d\n", q.first);
		}
	}
		
	return 0;
}
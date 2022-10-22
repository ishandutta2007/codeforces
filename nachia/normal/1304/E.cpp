#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct RootedTree {
	UL N;
	vector<vector<UL>> E;
	vector<UL> P;
	struct LCA {
		using Node = pair<UL, UL>;
		const Node defval = { -1, -1 };
		vector<Node> V;
		vector<UL> Pos;
		UL N;
		void init(UL n) {
			Pos.resize(n);
			N = 1; while (N < n * 2) N <<= 1;
			V.assign(N * 2 - 1, defval);
		}
		Node rmq(UL a, UL b, UL l = 0, UL r = -1, UL i = 0) {
			if (b <= l || r <= a) return defval;
			if (a <= l && r <= b) return V[i];
			return min(rmq(a, b, l, (l + r) / 2, i * 2 + 1), rmq(a, b, (l + r) / 2, r, i * 2 + 2));
		}
		UL query(UL a, UL b) {
			UL A = min(Pos[a], Pos[b]);
			UL B = max(Pos[a], Pos[b]);
			return rmq(A, B + 1, 0, N, 0).second;
		}
		void update(int p, Node v) {
			UL q = p + N - 1;
			V[q] = v;
			while (q != 0) {
				q = (q - 1) / 2;
				V[q] = min(V[q * 2 + 1], V[q * 2 + 2]);
			}
		}
		UL depth(UL v) { return get(Pos[v]).first; }
		Node get(int p) { return V[p + N - 1]; }
	} lca;
	UL itr = 0;
	void DFS_Create(UL p, UL d) {
		for (auto e : E[p]) {
			if (P[p] == e) continue;
			P[e] = p; lca.V[lca.N + itr - 1] = { d, p }; itr++;
			DFS_Create(e, d + 1);
		}
		lca.Pos[p] = itr;
		lca.V[lca.N + itr - 1] = { d, p }; itr++;
	}
	void Create() {
		UL p = 0;
		P.assign(N, 0);
		lca.init(N);
		DFS_Create(0, 0);
		rep(i, lca.N - 1) {
			UL p = lca.N - 2 - i;
			lca.V[p] = min(lca.V[p * 2 + 1], lca.V[p * 2 + 2]);
		}
	}
	UL Dis(UL a, UL b) {
		UL A = lca.depth(a);
		UL B = lca.depth(b);
		UL C = lca.depth(lca.query(a, b));
		//cout << "Distance(" << a << "," << b << ") = " << (A - C + B - C) << endl;
		return A - C + B - C;
	}
};


struct Problem {

	void Solve() {
		RootedTree G;
		UL N; cin >> N;
		G.N = N; G.E.resize(N);
		rep(i, G.N - 1) {
			UL a, b; cin >> a >> b; a--; b--;
			G.E[a].push_back(b); G.E[b].push_back(a);
		}
		G.Create();
		UL Q; cin >> Q;
		vector<bool> ans(Q, false);
		rep(i, Q) {
			UL x, y; cin >> x >> y; x--; y--;
			UL u, v; cin >> u >> v; u--; v--;
			UL k; cin >> k;
			UL d1 = G.Dis(u, v);
			UL d2 = min(G.Dis(u, x) + G.Dis(v, y), G.Dis(u, y) + G.Dis(v, x)) + 1;
			//cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
			if (k % 2 == d1 % 2) {
				ans[i] = ans[i] || (k >= d1);
			}
			if(k % 2 == d2 % 2) {
				ans[i] = ans[i] || (k >= d2);
			}
		}
		rep(i, Q) cout << (ans[i] ? "YES" : "NO") << endl;
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, Q; cin >> N >> Q;
	vector<int> A(N); for (int &a : A) cin >> a;
	int M = *max_element(A.begin(), A.end()) + 2;
	vector<vector<int>> divs(M);
	for (int i = 2; i < M; ++i) if (divs[i].empty()) {
		for (int j = i; j < M; j += i) divs[j].push_back(i);
	} 
	vector<int> par(M, -1);
	auto get_par = [&](int v) {
		if (par[v] == -1) par[v] = v;
		while (v != par[v]) {
			v = par[v] = par[par[v]];
		}
		return v;
	};
	auto merge = [&](int v, int u) {
		par[get_par(u)] = get_par(v);
	};

	for (int a : A) {
		int p = divs[a].front();
		for (int q : divs[a]) merge(p, q);
	}
	
	set<pair<int, int>> st;
	for (int a : A) {
		vector<int> divss = divs[a];
		for (int p : divs[a+1]) divss.push_back(p);
		for (int p : divss) {
			for (int q : divss) {
				int rp = get_par(p);
				int rq = get_par(q);
				if (rp == rq) continue;
				if (rp > rq) swap(rp, rq);
				st.insert({rp, rq}); 
			}
		}
	}

	while (Q--) {
		int v, u; cin >> v >> u;
		v = get_par(divs[A[v - 1]].front());
		u = get_par(divs[A[u - 1]].front());
		if (v > u) swap(v, u);
		if (v == u) {
			cout << "0\n";
		} else if (st.count({v, u})) {
			cout << "1\n";
		} else {
			cout << "2\n";	
		}
	}
	return 0;
}
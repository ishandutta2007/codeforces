#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct RAQ {
	vector<UL> node;
	UL N;
	UL n;
	void init(UL n) {
		N = 1;
		while (N < n)N <<= 1;
		this->n = n;
		node.assign(N * 2 - 1, 0);
	}
	UL query(UL a, UL b, UL l = 0, UL r = -1, UL i = 0) {
		if (r == -1) r = N;
		if (b <= l || r <= a) return -1;
		if (a <= l && r <= b) return node[i];
		return (query(a, b, l, (l + r) / 2, i * 2 + 1) & query(a, b, (l + r) / 2, r, i * 2 + 2)) | node[i];
	}
	void update(UL a, UL b, UL v, UL l = 0, UL r = -1, UL i = 0) {
		if (r == -1) r = N;
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) { node[i] |= v; return; }

		update(a, b, v | node[i], l, (l + r) / 2, i * 2 + 1);
		update(a, b, v | node[i], (l + r) / 2, r, i * 2 + 2);

		node[i] |= node[i * 2 + 1] & node[i * 2 + 2];
	}

};


struct Problem {

	void Solve() {
		UL N, M; cin >> N >> M;
		RAQ Q; Q.init(N);
		vector<pair<pair<UL, UL>, UL>> C(M);
		rep(i, M) {
			UL l, r, a; cin >> l >> r >> a; l--;
			C[i] = { { l, r }, a };
			//cout << "Update(" << l << "," << r << "," << a << ")" << endl;
			Q.update(l, r, a);
		}
		bool ok = true;
		rep(i, M) {
			UL buf = Q.query(C[i].first.first, C[i].first.second);
			//cout << "Query[" << i << "] = " << buf << endl;
			if (buf != C[i].second)
				ok = false;
		}
		if (!ok) { cout << "NO" << endl; return; }
		cout << "YES" << endl;
		rep(i, N) {
			if (i) cout << " ";
			cout << Q.query(i, i + 1);
		}cout << endl;
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
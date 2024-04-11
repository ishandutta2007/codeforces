#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct UF {
	UL N; vector<UL> V;
	void init(UL n) {
		N = n; V.resize(N); rep(i, N) V[i] = i;
	}
	UL root(UL p) {
		if (V[p] == p) return p;
		return V[p] = root(V[p]);
	}
	void unite(UL a, UL b) {
		UL A = root(a), B = root(b);
		V[A] = B;
	}
};

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> A(N + 2);
		rep(i, N) {
			char c; cin >> c;
			A[i + 1] = c - 'a';
		}
		A[0] = A[N + 1] = 100;
		UL ans = 0;
		for (UL t = 25; t > 0; t--) {
			vector<UL> buf;
			rep(i, A.size()) {
				if (A[i] == 100) { buf.push_back(A[i]); continue; }
				if (A[i] == t && buf.back() == t - 1) { ans++; continue; }
				if (A[i] == t - 1) {
					while (buf.back() == t) {
						buf.pop_back(); ans++;
					}
				}
				buf.push_back(A[i]);
			}
			A = move(buf);
		}
		cout << ans << endl;
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
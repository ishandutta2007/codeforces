#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
	struct Forest_Uni {
		vector<UL> v;
		UL Sz;
		void init(UL n) {
			Sz = n;
			v.clear();
			rep(i, n) v.push_back(i);
		}
		void add() { v.push_back(v.size()); }
		UL root(UL p) {
			if (v[p] == p) return p;
			return v[p] = root(v[p]);
		}
		void unite(UL a, UL b) {
			UL A = root(a);
			UL B = root(b);
			if (A != B) {
				Sz--;
				v[A] = B;
			}
		}
	} G;

    void Solve() {
        UL N, M, Q; cin >> N >> M >> Q;
		G.init(N + M);
		rep(i, Q) {
			UL x, y; cin >> x >> y;
			x--; y--; y += N;
			G.unite(x, y);
		}
		cout << (G.Sz - 1) << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}
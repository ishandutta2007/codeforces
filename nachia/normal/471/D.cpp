#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<typename E>
struct SeqSearchTable {
	vector<E> v;
	vector<UL> t;
	SeqSearchTable(vector<E> seq) { init(move(seq)); }
	void init(vector<E> seq) {
		v = move(seq);
		t.resize(v.size());
		t[0] = (UL)-1;
		UL p = 1, q = -1;
		while (p < v.size()) {
			if (q == (UL)-1) { t[p] = 0; p++; q = 0; }
			else if (v[q] == v[p - 1]) { t[p] = t[p - 1] + 1; p++; q++; }
			else { q = t[q]; }
		}
	}
};
template<typename E>
struct SeqSearch {
	vector<UL> query(const vector<E>& seq, const SeqSearchTable<E>& tg) {
		vector<UL> f;
		UL p = 0, q = 0;
		while (p < seq.size()) {
			if (seq[p] == tg.v[q]) {
				p++; q++;
				if (q == tg.v.size()) {
					f.push_back(p - tg.v.size());
					q = tg.t[q - 1] + 1;
				}
			}
			else {
				q = tg.t[q];
				if (q == (UL)-1) { p++; q = 0; }
			}
		}
		return move(f);
	}
};

struct Problem {

	void Solve() {
		UL N, W; cin >> N >> W;
		if (W == 1) { cout << N << endl; return; }
		vector<int> A(N); rep(i, N) cin >> A[i];
		vector<int> B(W); rep(i, W) cin >> B[i];
		rep(i, N - 1) A[i] = A[i] - A[i + 1];
		rep(i, W - 1) B[i] = B[i] - B[i + 1];
		A.pop_back(); N--;
		B.pop_back(); W--;
		//rep(i, N) cout << A[i] << " "; cout << endl;
		//rep(i, W) cout << B[i] << " "; cout << endl;
		auto S = SeqSearch<int>().query(A, SeqSearchTable<int>(B));
		UL ans = S.size();
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
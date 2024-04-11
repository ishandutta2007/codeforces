#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct SeqSearchTable {
	string v;
	vector<UL> t;
	SeqSearchTable(string seq) { init(move(seq)); }
	void init(string seq) {
		v = move(seq);
		t.resize(v.size() + 1);
		t[0] = (UL)-1;
		UL p = 1, q = -1;
		while (p <= v.size()) {
			if (q == (UL)-1) { t[p] = 0; p++; q = 0; }
			else if (v[q] == v[p - 1]) { t[p] = q + 1; p++; q++; }
			else { q = t[q]; }
		}
	}
};
struct SeqSearch {
	vector<UL> query(const string& seq, const SeqSearchTable& tg) {
		vector<UL> f;
		UL p = 0, q = 0;
		while (p < seq.size()) {
			if (seq[p] == tg.v[q]) {
				f.push_back(q + 1);
				p++; q++;
				if (q == tg.v.size()) q = tg.t[q - 1] + 1;
			}
			else {
				q = tg.t[q];
				if (q == (UL)-1) {
					f.push_back(0);
					p++; q = 0;
				}
			}
		}
		return move(f);
	}
};

struct Problem {

	void Solve() {
		string S; cin >> S;
		UL N = S.size();
		auto table = SeqSearchTable(S);
		vector<UL> G;
		{
			UL p = S.size();
			while (p != 0) {
				G.push_back(p);
				p = table.t[p];
			}
		}
		reverse(G.begin(), G.end());
		vector<UL> T(N + 1);
		vector<UL> T2(N + 1);
		rep(i, N) { T[i + 1]++; }
		{
			for (UL i = N; i > 0; i--) {
				T[table.t[i]] += T[i];
			}
		}
		vector<pair<UL, UL>> ans;
		rep(i, G.size()) ans.push_back({ G[i], T[G[i]] });
		cout << ans.size() << endl;
		rep(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
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
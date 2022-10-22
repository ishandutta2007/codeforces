#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {

	void Looop() {
		string S; cin >> S;
		UL N = S.size();
		UL r, c; r = c = 0;
		bool Format = false;
		for (UL i = 1; i < N - 1; i++) {
			if (S[i] == 'C')
				if ('0' <= S[i - 1] && S[i - 1] <= '9') Format = true;
		}
		if (Format) {
			if (S[0] != 'R') { cout << "ERROR" << endl; return; }
			UL p = 1;
			while (S[p] != 'C') {
				r = r * 10 + (S[p] - '0');
				p++;
			}
			p++;
			while (p < N) {
				c = c * 10 + (S[p] - '0');
				p++;
			}
			string T;
			while (c != 0) { c--; T.push_back('A' + c % 26); c /= 26; }
			reverse(T.begin(), T.end());
			cout << T << r << endl;
		}
		else {
			UL p = 0;
			while ('A' <= S[p] && S[p] <= 'Z') {
				c *= 26; c += 1; c += (S[p] - 'A');
				p++;
			}
			while (p < N) {
				r = r * 10 + (S[p] - '0');
				p++;
			}
			cout << "R" << r << "C" << c << endl;
		}
		
	}

	void Solve() {
		UL N; cin >> N;
		rep(i, N) Looop();
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
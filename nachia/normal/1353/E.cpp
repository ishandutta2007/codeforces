#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
public:

	

	void Solve() {
		UL T; cin >> T;
		while (T--) {
			UL N, K; cin >> N >> K;
			string S; cin >> S;
			UL Z = 0; rep(i, N) Z += S[i] - '0';
			int ans = 0;
			rep(s, K) {
				UL l = 0;
				UL r = (N - s + K - 1) / K;
				vector<int> L(r + 1);
				int m = 0;
				int mm = 0;
				rep(i, r) {
					L[i + 1] = L[i] +
						((S[s + K * i] == '0') ? -1 : 1);
					mm = max(mm, L[i + 1] - m);
					m = min(m, L[i + 1]);
				}
				ans = max(ans, mm);
			}
			printf("%d\n", Z - ans);
		}
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
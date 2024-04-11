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
			string S; cin >> S;
			UL N = S.size();
			vector<int> P(N, -1);
			int B[3] = { -1,-1,-1 };
			UL ans = 1000000;
			rep(i, N) {
				if (S[i] == '1') B[0] = i;
				if (S[i] == '2') B[1] = i;
				if (S[i] == '3') B[2] = i;
				int P = min(B[0], min(B[1], B[2]));
				if (P != -1) ans = min(ans, i - P + 1);
			}
			if (ans == 1000000) ans = 0;
			printf("%d\n", ans);
		}
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
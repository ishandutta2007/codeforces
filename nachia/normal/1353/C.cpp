#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
public:

	void Solve() {
		UL T; scanf("%d", &T);
		while (T--) {
			ULL N; cin >> N;
			ULL ans = 0;
			for (ULL i = 1; i <= N; i += 2) {
				ans += N * N - i * i;
			}
			cout << ans << endl;
		}
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
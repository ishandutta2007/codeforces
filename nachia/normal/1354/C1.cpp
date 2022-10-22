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
		cout << fixed << setprecision(10);
		while (T--) {
			UL N; cin >> N; N *= 2;
			double angle = 2.0 * acos(-1.0) / N;
			double ans = 0.5 / tan(angle / 2.0) * 2.0;
			cout << ans << endl;
		}
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
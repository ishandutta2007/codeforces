#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL T; cin >> T;
		rep(i, T) {
			int N, B; cin >> N >> B;
			vector<int> P(N + 1);
			rep(i, N) {
				char d; cin >> d;
				if (d == '0') P[i + 1] = P[i] + 1;
				else P[i + 1] = P[i] - 1;
			}
			if (P[N] < 0) { rep(i, N + 1) P[i] = -P[i]; B = -B; }
			int cy = P[N];
			int ans = 0;
			//cout << "cy = " << cy << endl;
			if (cy == 0) {
				rep(i, N) { if (P[i] == B) { ans = -1; } }
			}
			else {
				rep(i, N) {
					P[i] -= B;
					if (P[i] <= 0)if ((-P[i]) % cy == 0) ans++;
				}
			}
			cout << ans << endl;
		}
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
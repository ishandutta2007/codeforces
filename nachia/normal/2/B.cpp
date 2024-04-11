#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	pair<UL, bool> dp2[1001][1001];
	pair<UL, bool> dp5[1001][1001];
	pair<UL, UL> zero = { 0, 0 };

	void Solve() {
		UL N; cin >> N;
		rep(i, N) { dp2[i + 1][0] = dp2[0][i + 1] = { 1000000, true }; }
		rep(i, N) { dp5[i + 1][0] = dp5[0][i + 1] = { 1000000, true }; }
		dp2[1][0] = dp5[1][0] = { 0, true };
		rep(y, N) {
			rep(x, N) {
				UL a; cin >> a;
				pair<UL, bool> &p2 = dp2[x + 1][y + 1], &p5 = dp5[x + 1][y + 1];
				if (dp2[x + 1][y].first < dp2[x][y + 1].first)
					p2 = { dp2[x + 1][y].first, false };
				else p2 = { dp2[x][y + 1].first, true };
				if (dp5[x + 1][y].first < dp5[x][y + 1].first)
					p5 = { dp5[x + 1][y].first, false };
				else p5 = { dp5[x][y + 1].first, true };
				if (a == 0) { zero = { x + 1, y + 1 }; }
				else {
					while (a % 2 == 0) { a /= 2; p2.first++; }
					while (a % 5 == 0) { a /= 5; p5.first++; }
				}
			}
		}

		if (dp2[N][N].first > dp5[N][N].first) {
			for (UL x = 1; x <= N; x++)
				for (UL y = 1; y <= N; y++)
					dp2[x][y] = dp5[x][y];
		}

		string ans;
		if (zero.first != 0 && dp2[N][N].first != 0) {
			cout << 1 << endl;
			rep(x, zero.first - 1) cout << 'R';
			rep(x, zero.second - 1) cout << 'D';
			rep(x, N - zero.first) cout << 'R';
			rep(x, N - zero.second) cout << 'D';
			cout << endl;
		}
		else {
			UL x, y; x = y = N;
			while (x != 1 || y != 1) {
				if (dp2[x][y].second) { ans.push_back('R'); x--; }
				else { ans.push_back('D'); y--; }
			}
			reverse(ans.begin(), ans.end());
			cout << dp2[N][N].first << endl;
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
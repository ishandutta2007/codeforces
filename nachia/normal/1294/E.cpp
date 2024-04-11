#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL H, W; cin >> H >> W;
		vector<vector<UL>> matrix(W);
		rep(y, H) {
			rep(x, W) {
				UL v; cin >> v; v--;
				if (v % W == x && v < H * W) matrix[x].push_back(v / W);
				else matrix[x].push_back(1000000);
			}
		}
		UL ans = 0;
		rep(x, W) {
			UL ansbuf = H;
			vector<UL> buf(H);
			rep(y, H) buf[y] = y + H;
			rep(y, H) {
				if (matrix[x][y] == 1000000) continue;
				else buf[(y + H - matrix[x][y]) % H]--;
			}
			rep(y, H) {
				ansbuf = min(ansbuf, buf[y]);
			}
			ans += ansbuf;
		}
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
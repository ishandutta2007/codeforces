#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;){
		int N, M, r, c, p, q;
		cin >> N >> M >> r >> c >> p >> q;
		int ans = 0, dr = 1, dc = 1;
		for (;;){
			if (r == p || c == q) break;
			if (r+dr > N) dr = -1;
			if (c+dc > M) dc = -1;
			if (r+dr < 1) dr = 1;
			if (c+dc < 1) dc = 1;
			r += dr; c += dc;
			ans++;
		}
		cout << ans << '\n';
	}
}